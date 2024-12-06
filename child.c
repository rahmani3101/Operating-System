#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/wait.h>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        pid_t pid = fork();
        
        if(pid < 0)
        {
            perror("Fork Failed ");
            return 1;
        }

        if(pid == 0)
        {
            
            printf("Child Process: Loop iteration %d, PID: %d\n", i, getpid());
            exit(0); // Child exits
        }
    }


    for (int i = 0; i < 5; i++) 
    {
        wait(NULL); 
    }

    return 0;
}

