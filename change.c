/* change.c */
#include <stdio.h>

int main()
{
    char input[100];
    int target = 0x20241113;

    printf("The address of target variable: 0x%.8x\n", (unsigned) &target);
    
    printf("Please enter a string with format specifiers: ");
    fgets(input, sizeof(input), stdin);
    
    printf(input);
    printf("The value of target is changed to: 0x%.8x\n", target);

    return 1;
}
