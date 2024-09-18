/* capability.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main()
{
    int fd;
    char *v[2];
    fd = open("lab1", O_RDWR | O_APPEND);
    if(fd == -1){
        printf("Cannot open lab1\n");
        exit(0);
    }

    printf("File descriptor fd is %d\n", fd);

    setuid(getuid());

    v[0] = "/bin/dash"; v[1] = 0;
    execve(v[0], v, 0);
}