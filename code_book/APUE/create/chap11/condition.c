/* example.c*/
#include <stdio.h>
#include <pthread.h>
#include "error.c"
pthread_mutex_t count_lock;
pthread_cond_t count_nonzero;
unsigned count = 10;
pthread_t ntid;
decrement_count()
{
    printf("entering decreatement_count()\n");
    pthread_mutex_lock (&count_lock);
    while(count==0)
        pthread_cond_wait( &count_nonzero, &count_lock);
    count=count -1;
    pthread_mutex_unlock (&count_lock);
    printf("exiting decreatement_count()\n");
}
increment_count()
{
    printf("entering increatement_count()\n");
    pthread_mutex_lock(&count_lock);
    if(count==0)
        pthread_cond_signal(&count_nonzero);
    count=count+1;
    pthread_mutex_unlock(&count_lock);
    printf("exiting increatement_count()\n");
}
void printids(const char *s) {
    pid_t       pid;
    pthread_t   tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u itd %u (0x%x) \n", s, (unsigned int)pid, 
        (unsigned int)tid, (unsigned int)tid);
}
void* thr_fn1(void *arg) {
    printids("new thread fn1:");
    int i;
    while(1)
    {
        /* code */
    increment_count();
    sleep(1);
    }
    
    printids("exiting fn1:");
    return ((void *)0);
}
void* thr_fn2(void *arg) {
    printids("new thread fn2:");
    while ( 1)
    {
    decrement_count();
    sleep(1);
    }
    printids("exiting fn2:");
    return ((void *)0);
}
 int main(void)
{
    int     err;
    
    err = pthread_create(&ntid, NULL, thr_fn1, NULL);
    if (err != 0) 
        err_quit("can't create thread: %s\n", strerror(err));
    err = pthread_create(&ntid, NULL, thr_fn2, NULL);
    if (err != 0) 
        err_quit("can't create thread: %s\n", strerror(err));
    // decrement_count();
    printids("main thread: ");
    sleep(10);
    exit(0);
}

