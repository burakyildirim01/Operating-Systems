#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
        int     fd[2];
        pid_t   childpid;
        int     cake_num = 1;

        pipe(fd);
        
        printf("Starting baking %d\n",cake_num);

        sleep(3);
        write(fd[1], &cake_num, sizeof(cake_num));
        if((childpid = fork()) == 0)
        {
                
                read(fd[0], &cake_num, sizeof(cake_num));
                printf("Preparing dough for %d\n", cake_num);
                exit(0);
        }
        else
        {
                sleep(3);
                write(fd[1], &cake_num, sizeof(cake_num));
                if((childpid = fork()) == 0)
                {
                    
                    read(fd[0], &cake_num, sizeof(cake_num));
                    printf("Adding ingredients to cake %d\n", cake_num);
                    
                    exit(0);
                }else
                {
                    sleep(3);
                    write(fd[1], &cake_num, sizeof(cake_num));
                    if((childpid = fork()) == 0)
                    {
                        
                        read(fd[0], &cake_num, sizeof(cake_num));
                        printf("Serving cake %d\n", cake_num);
                        exit(0);
                    }else
                    {
                        sleep(0);
                        write(fd[1], &cake_num, sizeof(cake_num));
                    }
                }

        read(fd[0], &cake_num, sizeof(cake_num));
        printf("Finished cake %d\n",cake_num);

        
        
        }
        exit(0);
        return 0;
}