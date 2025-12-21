#include <stdio.h>

typedef struct interval {
  unsigned long long start;
  unsigned long long end;
} Interval;

#define MAX_INTERVALS_LEN 1024

int main() {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Failed to open file");
    return 1;
  }

  Interval intervals[MAX_INTERVALS_LEN];
  int count = 0;
  while (fscanf(fp, "%llu-%llu", &intervals[count].start,
                &intervals[count].end) == 2) {
    count++;
  }
  printf("Read %d intervals\n", count);

  // Skip count lines
  rewind(fp);
  for (int i = 0; i < count; i++) {
    while (fgetc(fp) != '\n')
      ;
  }

  // read ids
  unsigned long long id;
  int id_count = 0;
  int result = 0;
  while (fscanf(fp, "%llu", &id) == 1) {
    id_count++;
    int fresh = 0;

    for (int i = 0; i < count; i++) {
      if (id >= intervals[i].start && id <= intervals[i].end) {
        fresh = 1;
        break;
      }
    }
    if (fresh)
      result++;
  }
  printf("Processed %d ids\n", id_count);
  printf("result = %d\n", result);
  fclose(fp);
}
