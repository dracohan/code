#include <pthread.h>
#include "error.c"

struct msg {
	struct msg *m_next;
	/* ... more stuff here ... */
};
pthread_t ntid;

struct msg *workq;
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void
process_msg(void)
{
	struct msg *mp;

	for (;;) {
        printf("entering process_msg...\n");
		pthread_mutex_lock(&qlock);
        printf("process_msg locked...\n");
		while (workq == NULL){
            printf("do some work for one time\n");
			pthread_cond_wait(&qready, &qlock);
            printf("process_msg wait done\n");
        }
		// mp = workq;
		// workq = mp->m_next;
		pthread_mutex_unlock(&qlock);
        printf("process_msg unlocked...\n");
        sleep(3);
        printf("process_msg sleep 3...\n");
		/* now process the message mp */
	}
}

void
enqueue_msg(struct msg *mp)
{
    int i = 0;
	while(1){
        if (i == 3)
            workq = (struct msg*)malloc(sizeof(struct msg));
        printf("entering enqueing_msg ...\n");
        pthread_mutex_lock(&qlock);
        // mp->m_next = workq;
        // workq = mp;
        printf("enqueing_msg locked...\n");
        pthread_mutex_unlock(&qlock);
        printf("enqueing_msg unlocked...\n");
        pthread_cond_signal(&qready);
        printf("enqueing_msg signaling...\n");
        sleep(3);
        printf("enqueue_msg sleep 3...\n");
        i++;
    }
    
}

int main() {
    int     err;
    err = pthread_create(&ntid, NULL, enqueue_msg, NULL);
    if (err != 0) 
        err_quit("can't create thread: %s\n", strerror(err));
    process_msg();
}