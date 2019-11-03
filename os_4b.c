/*
	Q. WAP (using fork() and/or exec() commands) where parent and child execute:
		a. same program, same code		
		b. same program, different code		<-- this program
		c. different programs
*/

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid = fork();

	if( pid < 0 )
	{
		printf("\nError while forking a process!\n");
		return 1;
	}

	else if( pid == 0 )
	{
		printf("\n\n!!DIFFERENT CODE [CHILD]!!\n");
		execlp("/bin/echo","echo","Echo command run by child",NULL);
	}

	else
	{	
		printf("\n!!Parent process!!\n");
	}

	return 0;	
}
