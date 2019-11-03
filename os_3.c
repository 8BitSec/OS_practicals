#include<stdlib.h>
#include<stdio.h>
#include<getopt.h>

int copy( FILE *src , FILE *dest );

int main( int argc, char *args[] )
{
    int c, appflag;

    while ( ( c = getopt(argc,args,"ao")) != -1 )
    {
        switch(c)
        {
            case 'a' :
                        appflag = 1;
                        break;
            case 'o'  :
                        appflag = 0;
                        break;
            case '?' :
                        exit(1);
                        break;
            default  :
                        appflag = 0;
                        break;
        }//switch(c)

    }

    if( argc > 4 )
    {
        printf("Too many arguments for the operation!\n");
        exit(1);
    }

    else if( argc < 3 )
    {
        printf("Too few arguments for the operation!\n");
        exit(1);
    }

    FILE *src, *dest ;
    int s,d;

    s = ( argc > 3 )? 2:1 ;
    d = s + 1 ;

    src = fopen( args[s], "r" );

    if( !src )
    {
        printf("Unable to open the source file!\n");
        exit(1);
    }

    char *mode = (appflag == 0)? "w" : "a" ;

    dest = fopen( args[d] , mode );

    int no_of_chars = copy(src,dest);

    if( no_of_chars == 0 )
        printf("\nNo data copied :(\n");

    else
        printf("Operation Completed!\n%d characters copied from \"%s\" to \"%s\".\n",no_of_chars,args[s],args[d]);

    fclose(src);
    fclose(dest);
    return 0;
}

int copy( FILE *src , FILE *dest )
{
    int i = 0;
    char c;

    while( ( c = fgetc(src) ) != EOF )
    {
        fputc(c,dest);
        i++;
    }
    return i;
}
