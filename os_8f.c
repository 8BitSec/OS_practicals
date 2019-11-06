#include<stdio.h>
#include<time.h>
#define MAX 10			// max no. of processes
#define Q 2				// time quantum

//function to wait for milliseconds supplied as 'n'
void delay(int n) 
{
    int milli_seconds = 1000 * n; 

    clock_t start_time = clock(); 

    while (clock() < start_time + milli_seconds); 
}//delay()

//structure of a process
typedef struct
{
	int id;				// process id
	int btm;			// burst time
	int atm;			// arrival time
} process;

int main()
{
	process tmp,p[MAX];			// temp for swapping; processes array
	int n;						// no. of processes
	int i,j;					// indexes for iteration
	int tbt,t,atm,btm;			// total burst time; time t; arrival time; burst time
	int q = Q;					// time quantum

	printf("Enter the total number of processes (max 10): ");
	scanf("%d",&n);

	i=0,tbt=0;
	while( i < n )
	{
		printf("For process P(%d)\n", i+1);
		printf("Enter arrival time: ");		scanf("%d",&atm);
		printf("Enter burst time: ");		scanf("%d",&btm);
		
		tbt += btm;

		p[i].id = i+1;
		p[i].btm = btm;
		p[i].atm = atm;
		
		i++;		
	}

	i=0, j=i+1;
	
	while( i < n )
	{
		while( j<n )
		{
			if(p[i].atm > p[j].atm)
			{
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
			j++;
		}
		i++;
		j=i+1;
	}

	printf("\n\tTime\t\tProcess\n");
	
	t = btm = 0;
	
	while(t<tbt)
	{	
		delay(1000);

		if( q!=0 && p[btm].btm!=0 )
		{
			printf("\t %d\t\t  %d\n",t+1,p[btm].id);
			p[btm].btm--;
			q--;
			t++;
		}

		else
		{
			q=Q;

			if( btm == (n-1) )	btm=0;
			else				btm++;
		}		
	}
	return 0;
}