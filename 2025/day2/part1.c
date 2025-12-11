#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX 24

bool is_invalid(size_t x) {
  char str[MAX];
  sprintf(str, "%zu", x);

  int str_len = strlen(str);
  if (str_len % 2)
    return false;

  int half = str_len / 2;
  for (int i = 0; i < half; i++) {
    if (str[i] != str[half + i])
      return false;
  }
  printf("Invalid: %zu\n", x);
  return true;
}
int main() {
  FILE *fp;
  fp = fopen("input.txt", "r");
  if (fp == NULL) {
    printf("Failed to open input file");
    return 1;
  }

  size_t first, last;
  size_t invalid_sum = 0;
  while (fscanf(fp, "%zu-%zu,", &first, &last) == 2) {
    for (size_t i = first; i <= last; i++) {
      if (is_invalid(i))
        invalid_sum += i;
    }
  }
  printf("%zu\n", invalid_sum);
  fclose(fp);
}
