// "hello" device driver

#include "types.h"
#include "defs.h"
#include "param.h" // for NDEV
#include "traps.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "file.h" // for struct devsw
// #include "memlayout.h"
// #include "mmu.h"
// #include "proc.h"
// #include "x86.h"

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

int zeroread(struct inode *ip, char *dst, int n)
{
    return s_cnputs(dst, n, "0");
}

int zerowrite(struct inode *ip, char *src, int n)
{
    return n;
}

void zeroinit(void)
{
    devsw[ZERO].read = zeroread;
    devsw[ZERO].write = zerowrite;
}