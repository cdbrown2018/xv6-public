#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int dNullFd = open("/dev/dnull", O_WRONLY);

    char buffer[10];
    snprintf(buffer, dNullFd, "%d");
    printf(2, buffer);

    if (0 > dNullFd)
    {
        printf(2, "Error: Unable to open dnull\n");
    }
    else
    {
        write(dNullFd, "Hello", 5);
        close(dNullFd);
    }
    exit();
}