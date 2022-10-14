#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int child_func()
{
    volatile int x = 0;
    int pidhere = getpid();
    for (int a = 0; a < 1000000000; a++)
    {
        x += a / 2;
    }
    int runtime = getRunTime(pidhere);
    int waittime = getWaitTime(pidhere);
    printf("ProcessID %d, Runtime %d, Waittime %d\n", pidhere, runtime, waittime);
    exit(0);
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        int pid = fork();
        if (pid == 0)
        {
            child_func();
        }
    }
    for (int i = 0; i < 10; i++)
    {
        wait(0);
    }
    exit(0);
}