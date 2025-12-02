#include <stddef.h>
#include <stdio.h>

int main() {
  FILE *fp;
  fp = fopen("./input.txt", "r");
  if (fp == NULL) {
    printf("Failed to open input file\n");
    return 1;
  }

  size_t zero_count = 0;
  int counter = 50;
  char direction;
  int number_to_add;
  while (fscanf(fp, " %c%d", &direction, &number_to_add) == 2) {
    if (direction == 'L') {
      for (size_t i = 0; i < number_to_add; i++) {
        counter--;
        if (counter == 0)
          zero_count++;
        else if (counter == -1)
          counter = 99;
      }
    } else if (direction == 'R') {
      for (size_t i = 0; i < number_to_add; i++) {
        counter++;
        if (counter == 100)
          counter = 0;
        if (counter == 0)
          zero_count++;
      }
    }
  }

  printf("zero count = %zu\n\n\n", zero_count);
  fclose(fp);
  return 0;
}
