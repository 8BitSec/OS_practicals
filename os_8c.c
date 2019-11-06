#include<stdio.h>
#define max 10

//structure of a process
typedef struct
{
	int id;		//process id
	int btm;	//burst time
} process;

int main()
{
	process tmp,p[max];			//temp for swapping; processes array
	int n;						//total number of processes
	int i,j;					//indexes for iteration
	int tbt,t,btm;				//total burst time; time t; burst time

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

	i=0,j=i+1;

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
		i++;
		j=i+1;
	}

	printf("\nTime\t\tProcess\n");
	
	t=i=btm=0;
	j=i+1;
	while(t<tbt)
	{	
		printf("%d\t\t\t%d\n",t+1,p[btm].id);	p[btm].btm--;
		
		if(p[btm].btm==0)btm++;
		i=btm,j=btm+1;
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
			i++;
			j=i+1;
		}
		t++;
	}
	return 0;
}
