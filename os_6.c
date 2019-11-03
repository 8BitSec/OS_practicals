/*
	Q. WAP to demonstrate Inter Process Communication (IPC) between parent and child using pipe system call.
*/

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

#define BUFF_SIZE 20		// buffer size
#define R_END 0				// read end
#define W_END 1				// write end

int main()
{
	char write_msg[BUFF_SIZE] = "HELLO WORLD";
	char read_msg[BUFF_SIZE];

	int fd[2];						//file (pipe) descriptor for pipe
	pid_t pid;

	if( pipe(fd) == -1 )			// create the pipe
	{
		fprintf(stderr,"[!] Creation of pipe failed!");
		return 1;
	}

	pid = fork();					// fork a child process

	if( pid < 0 )
	{
		fprintf(stderr,"[!] Forking a process failed!");
		return 1;
	}

	else if( pid == 0 )
	{
		close(fd[W_END]); 			// close write end

		read(fd[R_END], read_msg, BUFF_SIZE);	// read the msg
		printf("\nRead msg is : %s\n",read_msg);  // print the read msg

		close(fd[R_END]);			// close read end
	}//child process ends

	else
	{
		close(fd[R_END]);			//close read end

		write(fd[W_END], write_msg, strlen(write_msg)+1 );	//write the msg

		close(fd[W_END]);
	}//parent process ends

	return 0;
}
