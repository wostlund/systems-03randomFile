#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int* genArray(){
  srand(time(0));
  int i;
  int* k = calloc(110, sizeof(char));
  printf("Generating Random Numbers:\n");
  srand(time(0));
  for(i=0; i<10; i++){
    int j = rand();
    printf("     random %d: %d\n", i, j);
    *(k+i) = j;
  }
  return k;
}

char* setString(int* x){
  int a = 0;
  int i;
  char* y = calloc(111, sizeof(char));
  for(i=0; i<10; i++){
    char* k = calloc(1, sizeof(int*));
    sprintf(k, "%d", x[i]);
    strcat(k, "\n");
    strcat(y, k);
  }
  //printf("\n%s\n", y);
  return y;
}

int* changeToInt(char* x){
  int i;
  int* ans = calloc(10, sizeof(int));
  int j;
  for(i = 0; i < strlen(x); i++){
    char* a = calloc(10, sizeof(char));
    int l = 0;
    while(*(x+i)!='\n'){
      *(a+l) = *(x+i);
      i++;
      l++;
    }
    *(ans+j) = atoi(a);
    printf("%d\n ", *(ans+j));
    free(a);
  }
  free(x);
  return ans;
}

int main(){

  umask(0000);
  char i;
  char* k = setString(genArray());
  int x = open("file1.txt", O_CREAT | O_RDWR, 0666);

  printf("\nWriting Numbers to File...\n\n");
  write(x, k, 111);
  //free(k);

  char* y = calloc(111, sizeof(char));
  read(x, y, 111);

  printf("%s\n", y);
  printf("Reading Numbers to File...\n\n");
  printf("Veritfication that written values were the same:\n");

  int* array2 = calloc(10, sizeof(int));
  array2 = changeToInt(k);
  for(i = 0; i < 10; i++){
    printf("    random %d: %d\n", i, *(array2+i));
  }
  return 0;
}
