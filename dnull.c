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

int dnullwrite(struct inode *ip, char *buf, int n)
{
    return 0;
}

void dnullinit(void)
{
    devsw[DNULL].write = dnullwrite;
}