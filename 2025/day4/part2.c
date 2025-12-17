#include <stdio.h>
#define MAX_ROW 135
#define MAX_COL 135

typedef struct position {
  int i;
  int j;
} position;

int main() {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("failed to open file");
    return 1;
  }

  char grid[MAX_ROW][MAX_COL + 2];
  size_t count = -1;
  while (fgets(grid[++count], MAX_COL + 2, fp) != NULL) {
  }

  int result = 0;
  while (1) {
    int iteration_result = 0;
    position to_remove[MAX_ROW * MAX_COL];
    int to_remove_count = 0;

    for (size_t i = 0; i < MAX_ROW; i++) {
      for (size_t j = 0; j < MAX_COL; j++) {
        if (grid[i][j] != '@')
          continue;

        int rolls = 0;
        // Top row
        if (i > 0 && j > 0 && grid[i - 1][j - 1] == '@')
          rolls++;
        if (i > 0 && grid[i - 1][j] == '@')
          rolls++;
        if (i > 0 && j + 1 < MAX_COL && grid[i - 1][j + 1] == '@')
          rolls++;

        // Middle row
        if (j > 0 && grid[i][j - 1] == '@')
          rolls++;
        if (j + 1 < MAX_COL && grid[i][j + 1] == '@')
          rolls++;

        // Bottom row
        if (i + 1 < MAX_ROW && j > 0 && grid[i + 1][j - 1] == '@')
          rolls++;
        if (i + 1 < MAX_ROW && grid[i + 1][j] == '@')
          rolls++;
        if (i + 1 < MAX_ROW && j + 1 < MAX_COL && grid[i + 1][j + 1] == '@')
          rolls++;

        if (rolls < 4) {
          iteration_result++;
          to_remove[to_remove_count].i = i;
          to_remove[to_remove_count++].j = j;
        }
      }
    }
    printf("iteration result = %d\n", iteration_result);
    result += iteration_result;
    if (iteration_result == 0)
      break;
    for (int k = 0; k < to_remove_count; k++) {
      grid[to_remove[k].i][to_remove[k].j] = '.';
    }
  }
  printf("Final result = %d\n", result);
  fclose(fp);
}
