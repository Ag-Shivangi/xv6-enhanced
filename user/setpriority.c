#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: setpriority new_priority pid\n");
        return 0;
    }
    int new_priority = 0;
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++)
    {
        new_priority *= 10;
        new_priority += (argv[1][i] - '0');
    }
    int pid = 0;
    len = strlen(argv[2]);
    for (int i = 0; i < len; i++)
    {
        pid *= 10;
        pid += (argv[2][i] - '0');
    }
    int here = set_priority(new_priority, pid);
    if (here == -1)
    {
        printf("Process with pid=%d not found\n", pid);
        exit(1);
    }
    printf("Old priority of process %d: %d\n", pid, here);
    printf("New priority of process %d: %d\n", pid, new_priority);
    return 0;
}