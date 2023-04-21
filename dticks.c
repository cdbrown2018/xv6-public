// "hello" device driver

#include "types.h"
#include "param.h" // for NDEV
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h"
#include "stat.h"
#include "defs.h"
#include "traps.h"

// for struct devsw
// #include "memlayout.h"
// #include "mmu.h"
// #include "proc.h"
// #include "x86.h"

void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}

/// @brief Shamelessly stolen from geeks for geeks.
/// @param num The number to convert.
/// @param str The out buffer
/// @param base The base (think base 10, base 2)
/// @return The int converted to a string. Doesn't really need to return anything but hey.
char *citoa(int num, char *str, int base)
{
    int i = 0;
    int isNegative = 0;

    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    if (isNegative == 1)
    {
        str[i++] = '-';
    }

    str[i] = '\0';

    reverse(str, i);
    return str;
}

int uptime()
{
    uint xticks;

    acquire(&tickslock);
    xticks = ticks;
    release(&tickslock);
    return xticks;
}

// Copy into outbuffer at most n characters of string.
static int
s_cnputs(char *outbuffer, int n, const char *string)
{
    int count = 0;

    for (; count < n && '\0' != string[count]; ++count)
    {
        outbuffer[count] = string[count];
    }
    if (count < n)
    {
        outbuffer[count] = '\0';
    }
    return count;
}

int ticksread(struct inode *ip, char *dst, int n)
{
    int ticks = uptime();
    char buffer[256];
    citoa(ticks, buffer, 10);
    return s_cnputs(dst, n, buffer);
}

int tickswrite(struct inode *ip, char *buf, int n)
{
    return n;
}

void ticksinit(void)
{
    devsw[TICKS].read = ticksread;
    devsw[TICKS].write = tickswrite;
}