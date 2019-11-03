/*
	Q. WAP (using fork() and/or exec() commands) where parent and child execute:
		a. same program, same code		
		b. same program, different code
		c. different programs			<-- this program
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	printf("\nFork Demo");

	__pid_t pid = fork();

	if( pid < 0 )
	{
		printf("\nError while forking a process!\n");
		return 1;
	}

	else if( pid == 0 )
	{
		printf("\n\n!!Child Starts!!\n");
		execlp("/bin/ls","ls",NULL);
	}

	else
	{
		wait(NULL);
		printf("\n!!Parent process!!\n");
	}

	return 0;	
}
