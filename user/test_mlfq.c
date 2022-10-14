
#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *agrv[])
{
    if (argc != 2)
    {
        printf("Usage: test_mlfq <sleep time>\n");
        return 0;
    }
    for (int a = 0; a < 20; a++)
    {
        int pid = fork();
        if (pid == 0)
        {
            sleep(5 - a / 4);
            volatile int i;
            volatile int j = 0;
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            for (i = 0; i < 10000000; i++)
            {
                j += i / 100000;
            }
            exit(0);
        }
    }
    int sltime = 0;
    for (int a = 0; agrv[1][a] != '\0'; a++)
        sltime = sltime * 10 + (int)(agrv[1][a] - '0');
    sleep(sltime);
    for (int a = 0; a < 20; a++)
        wait(0);
    return 0;
}