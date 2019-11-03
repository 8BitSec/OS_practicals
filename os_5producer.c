#include<stdio.h>
#include<string.h>			// for strlen()
#include<fcntl.h>			// for O_* flags
#include<unistd.h>			// for ftruncate()
#include<sys/mman.h>		// for mmap()
#include<sys/shm.h>			// for shm_*

#define SIZE 4096		// size in bytes of shared memory object

int main()
{
	const char *name = "SharedMemory";	// name of shared memory object

	const char *msg_0 = "Hello";		 //  messages (strings) written 
	const char *msg_1 = "World!";		//	  to shared memory
	
	int shm_fd; 				// shared memory file descriptor

	void *ptr;					// pointer for shared memory object

	shm_fd = shm_open( name, O_CREAT | O_RDWR, 0666 );  // object created

	ftruncate(shm_fd, SIZE);	// configure the size of object

	ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

	/*
		write messages to the shared memory
	*/	
	sprintf(ptr, "%s", msg_0);
	ptr += strlen(msg_0);
	
	sprintf(ptr, "%s", msg_1);
	ptr += strlen(msg_1);

	return 0;
}
