#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int child_func()
{
    volatile int x = 0;
    int pidhere = getpid();
    for (int a = 0; a < 100000; a++)
    {
        x += a;
        if (a % 10000 == 0)
        {
            printf("Currently running pid=%d\n", pidhere);
        }
    }
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
        else
        {
            sleep(1);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        int pid = wait(0);
        printf("PID of fork number %d is %d\n", i + 1, pid);
    }
    exit(0);
}