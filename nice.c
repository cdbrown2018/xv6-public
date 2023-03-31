#include "types.h"
#include "stat.h"
#include "user.h"

/// @brief Updates a process with a new priority level.
/// @param argc The number of arguments.
/// @param argv An array of arguments.
/// @return Whether the process completed successfully.
int main(int argc, const char *argv[])
{
    if (3 != argc)
    {
        printf(1, "Usage: nice pid priority\n");
    }
    else
    {
        int pid = atoi(argv[1]);
        int priority = atoi(argv[2]);
        int oldPriority = nice(pid, priority);
        printf(1, "Old priority: %d. New priority: %d\n", oldPriority, priority);
    }
    exit();
    return 0;
}