/* sidechannel.c */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <emmintrin.h>
#include <x86intrin.h>

uint8_t array[256*4096];
int temp;
char secret = XX;
#define CACHE_HIT_THRESHOLD (80)

void flushSideChannel()
{
  int i;
  for (i = 0; i < 256; i++) array[i*4096 + 1024] = 1;
  for (i = 0; i < 256; i++) _mm_clflush(&array[i*4096 + 1024]);
}

void victim()
{
  temp = array[secret*4096 + 1024];
}

void reloadSideChannel()
{
  int junk=0;
  register uint64_t time1, time2;
  volatile uint8_t *addr;
  int i;
  for(i = 0; i < 256; i++){
     addr = &array[i*4096 + 1024];
     time1 = __rdtscp(&junk);
     junk = *addr;
     time2 = __rdtscp(&junk) - time1;
     if (time2 <= CACHE_HIT_THRESHOLD){
         printf("array[%d*4096 + 1024] is in cache.\n",i);
         printf("The Secret = %d.\n",i);
     }
  }
}

int main(int argc, const char **argv)
{
  flushSideChannel();
  victim();
  reloadSideChannel();
  return (0);
}
