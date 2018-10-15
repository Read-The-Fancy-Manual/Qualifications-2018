#include <stdlib.h>
#include <unistd.h>

#define PATH "/home/chall/hello-world.py"

int     main(void)
{
    char *av[] = { PATH, NULL };
    execv(av[0], av);
    return EXIT_FAILURE;
}
