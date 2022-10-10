#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Usage: strace mask command [args]\n");
        return 0;
    }
    int mask = 0;
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++)
    {
        mask *= 10;
        mask += (argv[1][i] - '0');
    }
    int pid = getpid();
    int here = trace(pid, mask);
    if (here == 0)
        exit(1);
    argv++;
    argv++;
    exec(argv[0], argv);
    return 0;
}