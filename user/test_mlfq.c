
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void large_loop()
{
    volatile int i;
    volatile int j = 0;
    for (i = 0; i < 10000000; i++)
    {
        j += i / 100000;
    }
}

int main(int argc, char *agrv[])
{
    if (argc != 1)
    {
        printf("Usage: test_mlfq\n");
        return 0;
    }
    for (int a = 0; a < 20; a++)
    {
        int pid = fork();
        if (pid == 0)
        {
            sleep(5 - a / 5);
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            large_loop();
            exit(0);
        }
    }
    sleep(10);
    for (int a = 0; a < 20; a++)
        wait(0);
    return 0;
}