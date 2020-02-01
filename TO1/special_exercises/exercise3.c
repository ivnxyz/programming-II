#include <stdio.h>

int main() {
  int months[12] = {
    31,
    28,
    31,
    [3] = 0,
    31,
    [5] = 0,
    31,
    31,
    30,
    31,
    30,
    [11] = 0
  };

  for (int i = 0; i < sizeof(months)/sizeof(int); i++) {
    printf(" %d ", months[i]);
  }

  printf("\n");

  return 0;
}