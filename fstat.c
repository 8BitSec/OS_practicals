#include<stdio.h>
#include<fcntl.h>
#include<time.h>
#include<sys/stat.h>

int main(int argc, char *args[])
{
    if( argc<2 )
    {
        printf("Please supply at least 1 filename\n");
        return 1;
    }

    struct stat f ;

    for(int i=1;i<argc;i++)
    {
        int src = open(args[i],O_RDONLY);

        if( fstat(src,&f) < 0 )
        {
            printf("\nError getting file info for file : %s!\n",args[i]);
        }

        else{
        printf("============================================================================");
        printf("\n%s", S_ISDIR(f.st_mode)? "DIRECTORY:  ":"FILE     :  ");
        printf(args[i]);

        printf("\nGroup id :  %g",f.st_gid);
        printf("\nUser id  :  %u",f.st_uid);
        printf("\nSize     : %d bytes",f.st_size);
        printf("\nBlock size: %lld",f.st_blksize);
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

        printf("\n\nLast time of modification ->    %s",ctime(&f.st_mtime));
        printf("Last status change        ->    %s",ctime(&f.st_ctime));
	    printf("Last file access          ->    %s",ctime(&f.st_atime));
        printf("============================================================================");

        if( i!=argc-1)
        {
            printf("\nPress ENTER to key to continue ...\n\n");
            char c = getchar();
        }
      }//else
  }//for
        return 0;
}//main()
