/* retrop.c */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int foo(char *str)
{
    char buffer[100];
    unsigned int *framep;
    
    asm("movl %%ebp, %0" : "=r" (framep));
    printf("Frame pointer value of foo(): 0x%x\n", (unsigned)framep);

    strcpy(buffer, str);
    return 1;
}

void func_noarg()
{
    static int i = 0;
    printf("func_noarg() has been invoked %d time!\n", ++i);
}

void func_arg(int i)
{
    printf("func_arg() has been invoked with argument: 0x%x!\n", i);     
}

int main(int argc, char **argv)
{
    char str[2000];
    FILE *badfile;

    badfile = fopen("badfile_rop", "r");
    fread(str, sizeof(char), 2000, badfile);

    foo(str);
    printf("Returned Properly\n");

    return 1;
}