/* secret.c */
#include <stdio.h>

int main()
{
    char input[100];
    int target = 0x20241113;

    printf("Please enter a string with format specifiers: ");
    fgets(input, sizeof(input), stdin);
    
    printf(input);

    return 1;
}
