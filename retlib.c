/* retlib.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int foo(char *str)
{
    char buffer[100];
    
    strcpy(buffer, str);
    
    return 1;
}

int main(int argc, char **argv)
{
    char str[400];
    FILE *badfile;

    char *shell = (char *)getenv("MYSHELL");
    if(shell)
    {
        printf("/bin/zsh address: 0x%x\n", (unsigned int)shell);
    }

    badfile = fopen("badfile_libc", "r");
    fread(str, sizeof(char), 300, badfile);

    foo(str);
    printf("Returned Properly\n");

    return 1;
}