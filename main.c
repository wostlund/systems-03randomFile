#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int* genArray(){
  umask(0000);
  int* array = calloc(10, sizeof(int));
  int i;
  printf("Reading file...\n\n");
  for(i = 0; i < 10; i++){
    int y = open("file.txt", O_RDONLY, 0444);
    int j;
    read(y, array, 10 * sizeof(int));
    //*(array + i) = j;
  }
  return array;
}

void printArray(int* array, char size){
  printf("Verifying array is equal to the original...\n\n");
  char i;
  for(i = 0; i < size; i++){
    printf("     array[%d] = %d\n", i, array[i]);
  }
}

int main(){
  umask(0000);
  int* array1 = calloc(40, 1);
  char i;

  int file = open("/dev/random", O_RDONLY, 0444);
  printf("Generating random numbers...\n\n");
  read(file, array1, 10 * sizeof(int));
  for(i = 0; i < 10; i ++){
    printf("    Random number %d: %d\n", i, *(array1 + i));
  }
  close(file);

  int f = open("file.txt", O_CREAT | O_RDWR, 0666);
  printf("\nWriting numbers into file...\n\n");
  for(i = 0; i < 10; i++){
    write(f, array1 + i, sizeof(int));
  }

  int* array2 = genArray();
  printArray(array2, 10);
  return 0;
}
