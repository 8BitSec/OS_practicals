#include<stdio.h>
#include<stdlib.h>
#include<getopt.h>

int main(int argc, char *args[])
{	
	char option;
	int vflag=0, cflag=0, mflag=0, hflag=0;

    while( ( option = getopt(argc,args,"vcmah")) != -1 )
    {
        switch(option)
        {
			case 'a':   vflag = cflag = mflag = 1;	break;
            case 'v':   vflag = 1;	break;
            case 'c':   cflag = 1;	break;
            case 'm':   mflag = 1;	break;            
            case 'h':   hflag = 1;	break;
            case '?':
                        printf("Try \'procinfo -h\' for more information\n");
                        return 1;
        }//switch(options)
    }//while

    if( hflag == 1 )
    {
        printf("\nUsage : procinfo -options\n");
        printf("\nOptions :");
        printf("\n  -v : show the Kernel version");
        printf("\n  -c : show the CPU info");
        printf("\n  -m : show the Memory info");
        printf("\n  -a : show all above stated information");
        printf("\n  -h : show this help\n");
    }

	else
	{
		if( argc != 2 )
		{
			printf("Usage : procinfo -options[-vcm]\n");
        	printf("Try \'procinfo -h\' for more information\n");
        	return 0;
		}

		if( vflag == 1 )
		{
			system("cat /proc/version|awk ' BEGIN{ print \"Kernel version :\"}{print $1,$3}'");
		}
	
		if( cflag == 1 )
		{
			system("cat /proc/cpuinfo|awk 'NR==5'|awk ' BEGIN{ print \"CPU Type :\"}{print $4,$5,$6,$8,$9}'");
			system("cat /proc/cpuinfo|awk 'NR==4'|awk ' BEGIN{ print \"Model :\"}{print $3}'");		
		}

		if( mflag == 1)
		{
			system("cat /proc/meminfo|awk 'NR==1'|awk ' BEGIN{ print \"Configured Memory :\"}{print $2,$3}'");
			system("cat /proc/meminfo|awk 'NR==2'|awk ' BEGIN{ print \"Used Memory :\"}{print $2,$3}'");
			system("cat /proc/meminfo|awk 'NR==3'|awk ' BEGIN{ print \"Available Memory :\"}{print $2,$3}'");
		}
	}//if-else

	return 0;
}