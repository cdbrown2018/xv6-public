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

int nullread(struct inode *ip, char *dst, int n)
{
    return 0;
}

int nullwrite(struct inode *ip, char *buf, int n)
{
    return n;
}

void nullinit(void)
{
    devsw[DNULL].read = nullread;
    devsw[DNULL].write = nullwrite;
}