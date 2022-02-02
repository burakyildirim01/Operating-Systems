#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();

	if (pid < 0) {
		fprintf(stderr, "Fork Failed\n");
		return 1;
	}
	else if (pid == 0) {
		execlp("/bin/ps","ps -f",NULL);
	}
	else {
		wait(NULL);
		printf("Child finished execution.\n");
	}
    
    return 0;
}