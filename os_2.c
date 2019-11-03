/*
	Q. WAP to print file details including owner access permissions, file access time, where file name is given as a 
	   command line argument.
*/

#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>
#include<getopt.h>

int main(int argc,char *args[])
{
    char option;
    int sflag=0, pflag=0, iflag=0, tflag=0, hflag=0;

    while( ( option = getopt(argc,args,"spith")) != -1 )
    {
        switch(option)
        {
            case 's':   sflag = 1;
                        break;
            case 'p':   pflag = 1;
                        break;
            case 'i':   iflag=1;
                        break;
            case 't':   tflag=1;
                        break;
            case 'h':   hflag =1;
                        break;
            case '?':
                        printf("Try \'fileinfo -h\' for more information\n");
                        return 1;
        }//switch(options)
    }//while



    if( hflag == 1 )
    {
        printf("\nUsage : fileinfo -options filename\n");
        printf("\nOptions :");
        printf("\n  -s : show the file size");
        printf("\n  -i : show the group and user id ");
        printf("\n  -p : show the permissions");
        printf("\n  -t : show last access, status change and modification time");
        printf("\n  -h : show this help\n");
    }

    else{

    if( argc!=3 )
    {
        printf("Usage : fileinfo -options[-spti] filename\n");
        printf("Try \'fileinfo -h\' for more information\n");
        return 0;
    }

    int src = open(args[2],O_RDONLY);

    struct stat f ;

    if( fstat(src,&f) < 0 )
    {
        printf("Error getting information about file \"%s\" !\n",args[2]);
        return 1;
    }

    printf("\n%s", S_ISDIR(f.st_mode)? "DIRECTORY :  ":"FILE  :  ");
    printf(args[2]);

    if( iflag == 1 )
    {
        printf("\n\nGroup id :  %g",f.st_gid);
        printf("\nUser id  :  %u",f.st_uid);
    }//iflag

    if( sflag == 1 )
    {
        printf("\n\nSize       : %d bytes",f.st_size);
        printf("\nBlock size : %lld\n",f.st_blksize);
    }//sflag

    if( pflag == 1 )
    {
        printf("\nPermissions  :-\n");
        printf("\tUser   ->  ");
        printf( ( f.st_mode & S_IRUSR )? "r":"-" );
        printf( ( f.st_mode & S_IWUSR )? "w":"-" );
        printf( ( f.st_mode & S_IXUSR )? "x":"-" );
        printf("\n\tGroup  ->  ");
        printf( ( f.st_mode & S_IRGRP )? "r":"-" );
        printf( ( f.st_mode & S_IWGRP )? "w":"-" );
        printf( ( f.st_mode & S_IXGRP )? "x":"-" );
        printf("\n\tOthers ->  ");
        printf( ( f.st_mode & S_IROTH )? "r":"-" );
        printf( ( f.st_mode & S_IWOTH )? "w":"-" );
        printf( ( f.st_mode & S_IXOTH )? "x":"-" );
        printf("\n");
    }//pflag

    if( tflag == 1 )
    {
        printf("\nLast time of modification ->    %s",ctime(&f.st_mtime));
	    printf("Last status change        ->    %s",ctime(&f.st_ctime));
	    printf("Last file access          ->    %s",ctime(&f.st_atime));
    }//tflag

   }//else
    return 0;
}
