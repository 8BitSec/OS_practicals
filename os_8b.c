#include<stdio.h>
#define MAX 10

//structure of a process
typedef struct
{
	int id;			//process id
	int btm;		//process burst time
} process;

int main()
{
	process tmp,p[MAX];		//temp for swapping; processes array
	int n;					//total no. of processes
	int i,j;				//indexes for iteration
	int tbt,btm;			//total burst time; burst time

	printf("Enter no. of processes (max 10): ");	scanf("%d",&n);

	i=0,tbt=0;

	while(i<n)
	{
		printf("\nFor process P(%d)\n",i+1);
		printf("Enter burst time : ");		scanf("%d",&btm);
		
		tbt += btm;
		p[i].id = i+1;		
		p[i].btm = btm;
		i++;		
	}

        
	i=0,j=0;

	while(i<n)
	{
		while(j<n)
		{
			if(p[i].btm > p[j].btm)
			{
				tmp=p[i];
				p[i]=p[j];
				p[j]=tmp;
			}
			j++;
		}
		j=i+1;
		i++;
	}

	i=0,j=0;
	while(i<tbt)
	{	
		printf("\nTime\t\tProcess\n");

		while(j<n)
		{
			if(p[j].btm==0)
			j++;
			else
			{
				printf("%d\t\t\t%d\n",i+1,p[j].id);
				i++;
				p[j].btm--;
			}
		}		
	}
	printf("\n");
	return 0;
}
