#include<stdlib.h>
#include<stdio.h>

int copy( FILE *src , FILE *dest );

int main( int argc, char *args[] )
{

    if( argc > 3 )
    {
        printf("Too many arguments for the operation!\n");
        exit(1);
    }

    else if( argc < 2 )
    {
        printf("Too few arguments for the operation!\n");
        exit(1);
    }

    FILE *src, *dest ;

    src = fopen( args[1] , "r" );

    if( !src )
    {
        printf("\nUnable to open the source file!\n");
        exit(1);
    }

    dest = fopen( args[2] , "w" );

    int no_of_chars = copy(src,dest);

    if( no_of_chars == 0 )
        printf("\nNo data copied :(\n");

    else
        printf("Operation Completed!\n%d characters copied from \"%s\" to \"%s\".\n",no_of_chars,args[1],args[2]);

    fclose(src);
    fclose(dest);

    return 0;
}

int copy( FILE *src , FILE *dest )
{
    int i = 0;
    char c;

    while( !feof(src) )
    {
        c = fgetc(src);
        fputc(c,dest);
        i++;
    }

    return i;
}
