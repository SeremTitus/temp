/* stackguard.c */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void foo(char *str)
{
    char buffer[12];
    strcpy(buffer, str);
}

int main(int argc, char *argv[])
{
    foo(argv[1]);
    printf("You have successfully returned from foo() \n\n");
    return 0;
}