/* racevul.c */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main()
{
    char * fn = "/tmp/XYZ";
    char buffer[60];
    FILE *fp;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);

    /* get user input */
    scanf("%50s", buffer);

    if(!access(fn, W_OK)){
        fp = fopen(fn, "a+");
        fwrite("\n", sizeof(char), 1, fp);
        fwrite(buffer, sizeof(char), strlen(buffer), fp);
        fclose(fp);
    }
    else
        printf("No permission: %02d:%02d\n", local->tm_min, local->tm_sec);

    return 0;
}
