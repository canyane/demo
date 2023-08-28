#include<stdio.h>
#include<thread>
#include<unistd.h>

void threadproc()
{
    while(1)
    {
        printf("I am New Thread!\n");
    }
}

void threadproc1()
{
    while(1)
    {
        printf("I am New Thread 1!\n");
        sleep(10);
    }
}

void threadproc2(int a,int b)
{
    while(1)
    {
        printf("I am New Thread 2!\n");
        sleep(20);
    }
}

void func()
{
    std::thread t(threadproc);
    t.detach();
}

int main()
{
    func();
    //创建线程1
    std::thread t1(threadproc1);
    //创建线程2
    std::thread t2(threadproc2,1,2);

    while(1){}
    return 0;
}