#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 24

bool is_invalid(size_t x) {
  char str[MAX];
  sprintf(str, "%zu", x);
  size_t len = strlen(str);

  for (size_t window = 1; window <= len / 2; window++) {
    if (len % window != 0) {
      continue;
    }

    bool match = true;
    for (size_t i = window; i < len; i += window) {
      if (strncmp(str, str + i, window) != 0) {
        match = false;
        break;
      }
    }

    if (match) {
      char temp_sub[MAX];
      strncpy(temp_sub, str, window);
      temp_sub[window] = '\0';

      printf("%s is invalid. It is \"%s\" repeating.\n", str, temp_sub);
      return true;
    }
  }

  return false;
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
