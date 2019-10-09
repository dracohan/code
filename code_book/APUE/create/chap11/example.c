/* example.c*/
#include <stdio.h>
#include <pthread.h>
#include <stdint.h>

static pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond=PTHREAD_COND_INITIALIZER;

void thread(void) {
    int i;
    for(i=0;i<15;i++) {
        pthread_mutex_lock(&mtx);//需要操作head这个临界资源，先加锁，
        printf("This is a pthread.\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx);//解锁
        sleep(1);
    }
    sleep(3);
}
 
 int main(void)
{
    pthread_t id;
    int i,ret;
    ret=pthread_create(&id,NULL,(void *) thread,NULL); // 成功返回0，错误返回错误编号
    if(ret!=0) {
        printf ("Create pthread error!\n");
        exit (1);
    }
    pthread_mutex_lock(&mtx);
    for (int i = 0; i < 9; i++) {
        pthread_cond_wait(&cond,&mtx);
        printf("This is the main process.\n");
    }
    uint32_t a[10];
    printf("sizeof: %d", sizeof(a));

    printf("waiting child process.\n");
    pthread_mutex_unlock(&mtx);
    pthread_join(id,NULL);
    printf("done.\n");
    return (0);
}