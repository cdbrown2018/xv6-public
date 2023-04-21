#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, const char **argv)
{
    char buffer[128];
    int up = uptime();
    snprintf(buffer, up, "%d");
    printf(1, buffer);
    exit();
}