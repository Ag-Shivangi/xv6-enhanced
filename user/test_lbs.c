#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int child_func(int tickets)
{
    settickets(tickets);
    volatile int x = 0;
    int pidhere = getpid();
    // printf("Tickets=%d, pid=%d\n", tickets, pidhere);
    sleep(10);
    for (int a = 0; a < 100000; a++)
    {
        x += a;
        // if (a % 10 == 0)
        printf("%d\n", pidhere);
        // sleep(1);
    }
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
        child_func(85);
    }
    int ret1 = wait(0);
    int ret2 = wait(0);
    printf("PID of first fork=%d\n", ret1);
    printf("PID of second fork=%d\n", ret2);
    exit(0);
}