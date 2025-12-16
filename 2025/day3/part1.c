#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Required for strlen

#define MAX 101

int main() {
  FILE *fp = fopen("input.txt", "r");

  if (fp == NULL) {
    perror("Failed to open input file");
    exit(1);
  }

  char str[MAX];
  size_t count = 0;
  size_t result = 0;

  while (fscanf(fp, "%100s", str) == 1) {
    size_t len = strlen(str);
    count++;
    
    int max_rating = 0;
    for(size_t i=0; i<len-1; i++){
      for(size_t j=i+1; j<len; j++){
        int bat1 = str[i] - '0';
        int bat2 = str[j] - '0';

        int rating = (bat1*10) + bat2;
        if(rating > max_rating) max_rating = rating;
      }
    }
    result += max_rating;
    printf("max rating = %d\n", max_rating);

  }
  fclose(fp);

  printf("Read %zu valid numbers\n", count);
  printf("Result = %zu\n", result);

  return 0;
}
