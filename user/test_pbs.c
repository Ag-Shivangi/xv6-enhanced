#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int child_func()
{
    volatile int x = 0;
    int pidhere = getpid();
    for (int a = 0; a < 1000; a++)
    {
        x += a;
        printf("Currently running pid=%d\n", pidhere);
        if (a % 100 == 0)
        {
            sleep(5);
        }
    }
    exit(0);
}

int main()
{
    int pid1 = fork();
    if (pid1 == 0)
    {
        child_func();
    }
    set_priority(70, pid1);
    sleep(10);
    int pid2 = fork();
    if (pid2 == 0)
    {
        child_func();
    }
    set_priority(65, pid2);
    sleep(10);
    set_priority(60, pid2);
    sleep(10);
    set_priority(55, pid1);
    int ret1 = wait(0);
    int ret2 = wait(0);
    printf("PID of first fork=%d\n", ret1);
    printf("PID of second fork=%d\n", ret2);
    exit(0);
}