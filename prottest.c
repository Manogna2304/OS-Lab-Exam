#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  char *p;
  int pid;

  printf(1, "\nQ1: PAGE PROTECTION TEST\n");

  p = sbrk(4096);

  if(p == (char*)-1) {
    printf(1, "sbrk failed\n");
    exit();
  }

  *p = 'A';
  printf(1, "Initial value: %c\n", *p);

  if(mprotect(p, 1) == 0)
    printf(1, "mprotect successful\n");
  else
    printf(1, "mprotect failed\n");

  printf(1, "Read protected page: %c\n", *p);

  pid = fork();

  if(pid == 0) {
    printf(1, "Child attempting write...\n");
    *p = 'B';
    printf(1, "ERROR: Child survived write\n");
    exit();
  }

  wait();

  printf(1, "Parent still sees: %c\n", *p);

  if(munprotect(p, 1) == 0)
    printf(1, "munprotect successful\n");

  *p = 'C';
  printf(1, "New value after write: %c\n", *p);

  printf(1, "Unaligned address test: %d\n",
         mprotect(p + 1, 1));

  printf(1, "Zero length test: %d\n",
         mprotect(p, 0));

  printf(1, "Beyond memory test: %d\n",
         mprotect((void*)0x7ffff000, 1));

  printf(1, "Q1 TEST COMPLETE\n");

  exit();
}
