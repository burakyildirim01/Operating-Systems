#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  pid_t pid = fork();
  
  if (pid > 0) {
    sleep (15);
  }
  else {
    exit (0);
  }
  return 0;
}