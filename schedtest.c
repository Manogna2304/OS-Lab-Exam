#include "types.h"
#include "stat.h"
#include "user.h"

int
main(void)
{
  int pid[3];
  int priorities[3] = {5, 10, 15};
  int i, j;

  printf(1, "\nQ2: PRIORITY SCHEDULER TEST\n");

  set_priority(getpid(), 1);

  printf(1, "Parent priority set to 1\n");

  for(i = 0; i < 3; i++) {
    pid[i] = fork();

    if(pid[i] == 0) {
      for(j = 0; j < 20000000; j++) {
        // CPU-bound workload
      }

      printf(1, "Child with priority %d finished\n",
             priorities[i]);

      exit();
    }

    if(pid[i] < 0) {
      printf(1, "Fork failed\n");
      exit();
    }

    set_priority(pid[i], priorities[i]);
  }

  for(i = 0; i < 3; i++)
    wait();

  printf(1, "Done\n");

  exit();
}

