#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>
void signalrm_signal(int sig)
{
	printf("Parent:Alarm has Fired!");
}
int main()
{
	pid_t pid;
	signal(SIGALRM,signalrm_signal);
	pid=fork();
	if (pid<0)
	{
		printf("Fork is Failed");
		exit(0);
	}
	if (pid==0)
	{
		printf("Child:Waiting for 3 seconds before sending SIGALRM signal to the parent...");		
		sleep(3);
		kill(getppid(),SIGALRM);
		exit (0);
	}
	else
	{
		printf("Parent:Waiting for SIGALRM from child process...");
		while(1)
		{
			pause();
		}
	}
		return 0;
	}
			
		
