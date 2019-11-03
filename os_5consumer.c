/*
	Q. WAP to demonstrate producer-consumer problem using shared memory.
				^this program
*/

#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/shm.h>

#define SIZE 4096		// size in bytes of shared memory object

int main()
{
	const char *name = "SharedMemory";	// name of shared memory object

	int shm_fd;			// file descriptor

	void *ptr; 			// pointer to shared mem object

	shm_fd = shm_open( name, O_RDONLY, 0666 );		//opening the shared mem object

	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);

	printf("%s", (char *)ptr);

	shm_unlink(name);

	return 0;
}
