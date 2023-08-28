#include<sys/syscall.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

void* thread_proc(void* arg)
{
    pthread_t* tid1=(pthread_t*)arg;
    pthread_t tid2=pthread_self();
    pthread_t tid3=syscall(SYS_gettid);
    while(1)
    {
        printf("tid1: %ld,tid2: %ld,tid3: %ld\n",*tid1,tid2,tid3);
        sleep(3);
    }
}
int main()
{
    pthread_t tid;
    pthread_create(&tid,NULL,thread_proc,&tid);

    pthread_join(tid,NULL);
    
    return 0;
}