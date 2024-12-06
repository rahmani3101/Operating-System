#include<stdio.h>
#include <unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
	int n ,i;
	printf("Enter the number of process to create : ");
	scanf("%d " ,&n);
	for(i=0;i<n;i++)
	{
		pid_t pid =fork();
		if(pid<0)
		{
			printf("Fork failed fior iteration %d \n " , i );
			exit(1);
		}
		else if(pid == 0)
		{
			printf("Child Process created in iteration %d \n " , i);
			printf("PID : %d , Parent PID : %d \n " , getpid() , getppid());
			exit(0);
		}
		else
		{
		}
	}
	for(i=0;i<n ; i++)
	{
		wait(NULL);
	}
	printf("Parent process (PID : %d ) has finished waiting for all children \n " , getpid());
	return 0;
}				
