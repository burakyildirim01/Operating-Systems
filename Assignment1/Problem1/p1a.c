#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
  int level = 0;
  printf("Main Process ID: %d, level: 0 \n", getpid());
  for (int i = 0; i < 4; i++) {
    if (fork() == 0) {
      level++;
      printf("Process ID: %d, Parent ID: %d, level: %d \n", getpid(), getppid(), level);
      
    } else {
      wait(NULL);
    }
  }
  return 0;
}