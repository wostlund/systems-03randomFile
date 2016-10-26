#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

char* genArray(){
  int i;
  char* x = calloc(110, sizeof(char));
  printf("Generating Random Numbers:\n");
  srand(time(0));
  int a = 0;
  for(i=0; i<10; i++){
    int j = rand();
    printf("     random %d: %d\n", i, j);
    char* k = calloc(1, sizeof(int*));
    sprintf(k, "%d", j);
    strcat(k, "\n");
    strcat(x, k);
    a+=sizeof(k);
  }
  printf("\n%s\n", x);
  return x;
}

int main(){
  umask(0000);
  char i;
  char* k = genArray();
  int x = open("file1.txt", O_CREAT | O_RDWR, 0666);
  printf("\nWriting Numbers to File...\n\n");
  write(x, k, 110);
  int* y = calloc(10, sizeof(int));
  read(x, y, sizeof(int) * 10);
  printf("Reading Numbers to File...\n\n");
  printf("Veritfication that written values were the same:\n");
  for(i = 0; i < 10; i++){
    printf("    random %d: %d\n", i, *(y+i));
  }
  return 0;
}
