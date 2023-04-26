#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int dNullFd = open("/dev/null", O_WRONLY);

    if (0 > dNullFd)
    {
        printf(2, "Error: Unable to open dnull\n");
    }
    else
    {
        int bytesWritten = write(dNullFd, "Hello", 5);

        if (0 <= bytesWritten)
        {
            printf(1, "Sucessfully wrote %d bytes.\n", bytesWritten);
        }
        else
        {
            printf(2, "Error: Unable to write to dnull\n");
        }

        char *buffer[512];
        read(dNullFd, buffer, 512);
        printf(1, "Read <%s> (should be empty)\n", buffer);
        close(dNullFd);
    }
    exit();
}