#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct interval {
  unsigned long long start;
  unsigned long long end;
  bool valid;
} Interval;

#define MAX_INTERVALS_LEN 1024

int comp(const void *a, const void *b) {
  Interval *ia = (Interval *)a;
  Interval *ib = (Interval *)b;
  if (ia->start < ib->start)
    return -1;
  if (ia->start > ib->start)
    return 1;
  return 0;
}

int main() {
  FILE *fp = fopen("input.txt", "r");
  if (fp == NULL) {
    perror("Failed to open file");
    return 1;
  }

  Interval intervals[MAX_INTERVALS_LEN];
  int count = 0;
  unsigned long long start;
  unsigned long long end;

  while (fscanf(fp, "%llu-%llu", &start, &end) == 2) {
    intervals[count].start = start;
    intervals[count].end = end;
    intervals[count].valid = true;
    count++;
  }
  fclose(fp);

  // Sort intervals by start time
  qsort(intervals, count, sizeof(Interval), comp);

  // Merge overlapping intervals in one pass
  for (int i = 1; i < count; i++) {
    if (!intervals[i].valid)
      continue;

    // Find the last valid interval before current
    int prev = i - 1;
    while (prev >= 0 && !intervals[prev].valid) {
      prev--;
    }

    if (prev >= 0 && intervals[prev].valid) {
      // Check if current interval overlaps or is adjacent to previous
      // Overlapping: prev.end >= current.start
      if (intervals[prev].end >= intervals[i].start - 1) {
        if (intervals[i].end > intervals[prev].end) {
          intervals[prev].end = intervals[i].end;
        }
        intervals[i].valid = false;
      }
    }
  }

  unsigned long long result = 0;
  for (int i = 0; i < count; i++) {
    if (intervals[i].valid) {
      result += (intervals[i].end - intervals[i].start) + 1;
    }
  }

  printf("Processed %d intervals\n", count);
  printf("result = %llu\n", result);

  return 0;
}
