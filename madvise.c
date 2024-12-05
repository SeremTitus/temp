/* madvise.c */
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
  struct stat st;
  char content[20];
  char *new_content = "########";
  void *map;

  int f=open("./numberfile", O_RDWR);
  fstat(f, &st);

  // Map the entire file to memory
  map=mmap(NULL, st.st_size, PROT_READ|PROT_WRITE,
                             MAP_PRIVATE, f, 0);

  // Read 20 bytes from the file via the mapped memory
  memcpy((void*)content, map, 20);
  printf("Before changing the mapped memory: %s\n", content);

  // Write to the file via the mapped memory
  memcpy(map+6, new_content, strlen(new_content));
  memcpy(content, map, 20);
  printf("After changing the mapped memory: %s\n", content);

  madvise(map, st.st_size, MADV_DONTNEED);
  memcpy((void*)content, map, 20);
  printf("After using madvise to drop the private copy: %s\n", content);

  // Clean up
  munmap(map, st.st_size);
  close(f);
  return 0;
}