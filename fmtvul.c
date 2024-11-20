/* fmtvul.c */
#include <stdio.h>

void fmtstr(char *str)
{
    unsigned int *framep;
    unsigned int *ret;

    asm("movl %%ebp, %0" : "=r" (framep));
    ret = framep + 1;  //Return address field

    printf("The value of return address field: 0x%.8x\n", (unsigned) ret);
    printf("The starting address of shellcode: 0x%.8x\n", (unsigned) (str + 145));
    
    printf(str);
    printf("\nNow the program is jumping to: 0x%.8x\n", *ret);
}

int main()
{
    FILE *formatfile;
    char str[200];

    formatfile = fopen("formatfile", "rb");
    fread(str, sizeof(char), 200, formatfile);
    fmtstr(str);

    return 1;
}
