#include<stdio.h>
#include<stdlib.h>				// for atoi()
#include<pthread.h>

int sum;						// global variable, will be shared by all threads

void *runner(void *param);		// this function will be called by the thread/s

int main(int argc, char *argv[])
{
	pthread_t tid;				// thread identifier
	pthread_attr_t attributes;  // set of thread attributes

	if( argc != 2 )
	{
		printf("Usage : thread <integer value>\n");
		return 1;
	}

	if( atoi(argv[1]) < 0 )
	{
		fprintf(stderr,"[!] %d must be a positive integer!",atoi(argv[1]));
		return 1;
	}

	pthread_attr_init(&attributes);		//get the default attributes

	pthread_create(&tid, &attributes, runner, argv[1]);		// create the thread

	pthread_join(tid, NULL);			// wait for thread to join

	printf("Sum upto %d integers is : %d\n", atoi(argv[1]), sum);
}

void *runner( void *param )
{
	int i;
	int n = atoi(param);

	for( i=1; i<=n; i++ )
	{
		sum += i;
	}

	pthread_exit(0);
}//runner()