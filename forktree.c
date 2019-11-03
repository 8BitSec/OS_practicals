#include<stdio.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/unistd.h>

int main()
{
	int i,j=0;

	for(i=0;i<5;i++,j++)
	{
		fork();

		printf("Process%d",j);				
	}

	return 0;
}