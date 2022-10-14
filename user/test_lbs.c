#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int child_func(int tickets)
{
    settickets(tickets);
    volatile int x = 0;
    int pidhere = getpid();
    sleep(10);
    for (int a = 0; a < 1000000000; a++)
    {
        x += a / 3;
    }
    int runtime = getRunTime(pidhere);
    int waittime = getWaitTime(pidhere);
    printf("ProcessID %d, Runtime %d, Waittime %d\n", pidhere, runtime, waittime);

    exit(0);
}

int main()
{
    int pid1 = fork();
    if (pid1 == 0)
    {
        child_func(5);
    }
    sleep(5);
    int pid2 = fork();
    if (pid2 == 0)
    {
        child_func(15);
    }
    int ret1 = wait(0);
    int ret2 = wait(0);
    printf("PID of first fork=%d\n", ret1);
    printf("PID of second fork=%d\n", ret2);
    exit(0);
}