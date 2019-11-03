#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int GetLine(FILE *f,char* line, int size)
{
    char ch;
    int i=0;

    if( f == NULL )
    {
        printf("\nUnable to open file!\n");
        return 0;
     }

    while( ( ch = fgetc(f) )!= EOF  && i < size )
    {
        if( ch!='\n' )      *( line +  i++ ) = ch;

        else
        {
            *( line + i ) = '\0';
            return i;
         }
     }

     return i ;
} //Getline()

int main()
{
    FILE *f;
    int no_of_chars;
    char readfile[20], str[MAX];

    printf("\nEnter the name of the text file :");
        scanf("%s",readfile);

    f = fopen(readfile,"r");

    if( !f )
    {
        printf("\nUnable to open the file!\n");
        exit(1);
    }

    printf("\nFILE : \"%s\"\n",readfile);

    no_of_chars = GetLine(f,str,MAX) ;

    printf("\nTotal characters read : %d\n",no_of_chars);

    if( no_of_chars == MAX )
    {
        printf("\nMax Buffer Size reached while reading the line.\n");
        printf("\nCharacters read are :  %s",str);
    }

    else if( no_of_chars != 0 )
        printf("Line read :   %s\n",str);

    else
        printf("\nNo line read :(\n");

    fclose(f);
    return 0;
}
