#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE* f;
    char c, readfile[20], writefile[20], text[50];

    printf("\n\t<---Reading from a file--->");
    printf("\nEnter the name of the source file :");
        gets(readfile);

    f = fopen(readfile,"r");

    if( !(f = fopen(readfile,"r")) )
    {
        printf("Unable to open the file!\n");
        exit(1);
    }

    printf("\nThe data present in the file is:\n");

    while( !feof(f) )
    {
        fscanf(f,"%c",&c);
        printf("%c",c);
    }

    fclose(f);

    printf("\n\t<---Writing to a file--->");
    printf("\nEnter the name of the destination file :");
        gets(writefile);

    if ( strcmp(writefile,"readwrite.c") == 0 )
    {
        printf("\nAction Forbidden!\n");
        exit(0);
    }

    f = fopen(writefile,"w");

    printf("\nEnter the text to write to the file :");
        gets(text);

    fprintf(f,"%s",text);

    printf("\nSuccess!");
    printf("\n\t<-- End of read/write -->\n");

    fclose(f);
    return 0;
}
