/*
	Q. WAP (using fork() and/or exec() commands) where parent and child execute:
		a. same program, same code		<-- this program
		b. same program, different code
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

	else
	{
		printf("\n!!SAME CODE!!\n");
	}

	return 0;
}
