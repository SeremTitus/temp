/* random.c */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x[12];
    char *y = malloc(sizeof(char)*12);
    printf("Address of buffer x (on stack): 0x%lx\n", (unsigned long)x);
    printf("Address of buffer y (on heap): 0x%lx\n", (unsigned long)y);
}
