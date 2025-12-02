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
      counter = (counter - number_to_add) % 100;
      if (counter < 0)
        counter += 100;
    } else if (direction == 'R') {
      counter = (counter + number_to_add) % 100;
    }

    if (counter == 0)
      zero_count++;
  }

  printf("%zu\n", zero_count);
  fclose(fp);
  return 0;
}
