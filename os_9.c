#include<stdio.h>

void first_fit(int[],int,int[],int,int[]);
void best_fit(int[],int,int[],int,int[]);
void worst_fit(int[],int,int[],int,int[]);
void print_allocation(int[],int);

int main()
{
	int b,p;		//no. of blocks; no. of processes
	int i,j;

	printf("\nEnter the no. of blocks: ");		scanf("%d",&b);

	int block_size[b];

	printf("\nEnter the respective block sizes for %d blocks:\n", b);
	for(i=0; i<b; i++)
	{
		printf("Block %d = ",i+1);
		scanf("%d",&block_size[i]);
	}

	printf("\nEnter the no. of processes: ");		scanf("%d",&p);

	int process_size[p], allocation[p];

	printf("\nEnter the respective process sizes for %d processes:\n", p);
	
	for(i=0; i<p; i++)
	{
		printf("Process %d = ",i+1);
		scanf("%d",&process_size[i]);
	}

	printf("\n\nFIRST FIT allocation:\n");

	first_fit(block_size,b,process_size,p,allocation);
	print_allocation(allocation,p);

	printf("\n\nBEST FIT allocation:\n");

	best_fit(block_size,b,process_size,p,allocation);
	print_allocation(allocation,p);

	printf("\n\nWORST FIT allocation:\n");

	worst_fit(block_size,b,process_size,p,allocation);
	print_allocation(allocation,p);

	
	return 0;
}

void first_fit(int block[], int b, int process[], int p, int allocation[])
{
	int i,j;
	int temp[b];

	for(i=0;i<b;i++) 	temp[i]=block[i];

	for(i=0; i<p; i++)
	{
		allocation[i] = 0;
		for(j=0; j<b; j++)
		{
			if( temp[j] >= process[i] )
			{
				allocation[i] = j+1;
				temp[j] -= process[i];
				break;
			}			
		}
	}
}

void best_fit(int block[], int b, int process[], int p, int allocation[])
{
	int i,j;
	int best;
	int temp[b];

	for(i=0;i<b;i++) 	temp[i]=block[i];

	for(i=0; i<p; i++)
	{
		best = -1;
		allocation[i] = 0;
		for(j=0; j<b; j++)
		{
			if( temp[j] >= process[i])
			{
				if( best == -1 )				best = j;
				else if( temp[best] >  temp[j] )	best = j;
			}
		}
		if( best != -1 )
		{
			allocation[i] = best + 1;
			temp[best] -= process[i];
		}
	}
}

void worst_fit(int block[], int b, int process[], int p, int allocation[])
{
	int i,j;
	int worst;
	int temp[b];

	for(i=0;i<b;i++) 	temp[i]=block[i];

	for(i=0; i<p; i++)
	{
		worst = -1;
		allocation[i] = 0;
		for(j=0; j<b; j++)
		{
			if( temp[j] >= process[i])
			{
				if( worst == -1 )					worst = j;
				else if( temp[worst] <  temp[j] )	worst = j;
			}
		}
		if( worst != -1 )
		{
			allocation[i] = worst + 1;
			temp[worst] -= process[i];
		}
	}
}

void print_allocation(int allocation[], int n)
{
	int i;
	
	printf("\n\n\tProcess\t\tBlock\n");

	for(i=0;i <n; i++)
	{
		if( allocation[i] != 0)		printf("\t  %d\t\t  %d\n",i+1,allocation[i]);
		else						printf("\t  %d\t\tUnallocated\n",i+1);
	}
}