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

    unsigned long long max_rating = 0;
    for (size_t a = 0; a < len - 11; a++) {
      for (size_t b = a + 1; b < len - 10; b++) {
        for (size_t c = b + 1; c < len - 9; c++) {
          for (size_t d = c + 1; d < len - 8; d++) {
            for (size_t e = d + 1; e < len - 7; e++) {
              for (size_t f = e + 1; f < len - 6; f++) {
                for (size_t g = f + 1; g < len - 5; g++) {
                  for (size_t h = g + 1; h < len - 4; h++) {
                    for (size_t i = h + 1; i < len - 3; i++) {
                      for (size_t j = i + 1; j < len - 2; j++) {
                        for (size_t k = j + 1; k < len - 1; k++) {
                          for (size_t l = k + 1; l < len; l++) {
                            int bat1 = str[a] - '0';
                            int bat2 = str[b] - '0';
                            int bat3 = str[c] - '0';
                            int bat4 = str[d] - '0';
                            int bat5 = str[e] - '0';
                            int bat6 = str[f] - '0';
                            int bat7 = str[g] - '0';
                            int bat8 = str[h] - '0';
                            int bat9 = str[i] - '0';
                            int bat10 = str[j] - '0';
                            int bat11 = str[k] - '0';
                            int bat12 = str[l] - '0';

                            unsigned long long rating =
                                ((unsigned long long)bat1 * 100000000000)
                              + ((unsigned long long)bat2 * 10000000000)
                              + ((unsigned long long)bat3 * 1000000000) 
                              + ((unsigned long long)bat4 * 100000000) 
                              + ((unsigned long long)bat5 * 10000000) 
                              + ((unsigned long long)bat6 * 1000000) 
                              + ((unsigned long long)bat7 * 100000) 
                              + ((unsigned long long)bat8 * 10000) 
                              + ((unsigned long long)bat9 * 1000) 
                              + ((unsigned long long)bat10 * 100) 
                              + ((unsigned long long)bat11 * 10) +
                                bat12;
                            if (rating > max_rating)
                              max_rating = rating;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }

    result += max_rating;
    printf("for %s, max rating = %llu\n", str, max_rating);
  }
  fclose(fp);

  printf("Read %zu valid numbers\n", count);
  printf("Result = %llu\n", result);

  return 0;
}
