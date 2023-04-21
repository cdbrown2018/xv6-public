// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = {"sh", 0};

int main(void)
{
  int pid, wpid;

  if (open("console", O_RDWR) < 0)
  {
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0); // stdout
  dup(0); // stderr

  if (open("hello", O_RDWR) < 0)
  {
    mknod("hello", 7, 1);
    open("hello", O_RDWR);
  }

  if (open("zero", O_RDWR) < 0)
  {
    mknod("zero", 2, 1);
    open("zero", O_RDWR);
  }

  if (open("dnull", O_RDWR) < 0)
  {
    mknod("dnull", 4, 1);
    open("dnull", O_RDWR);
  }

  if (open("ticks", O_RDWR) < 0)
  {
    mknod("ticks", 3, 1);
    open("ticks", O_RDWR);
  }

  for (;;)
  {
    printf(1, "init: starting sh\n");
    pid = fork();
    if (pid < 0)
    {
      printf(1, "init: fork failed\n");
      exit();
    }
    if (pid == 0)
    {
      exec("sh", argv);
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while ((wpid = wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
