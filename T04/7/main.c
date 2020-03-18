#include <stdio.h>

#define SIZE 16

void sort(int *, int);

void sort(int *p, int n)
{
  int *q, *const end = p + n, temp;

  for (; p < end; ++p)
    for (q = p + 1; q < end; ++q)
      if (*p > *q)
      {
        temp = *p;
        *p = *q;
        *q = temp;
      }
}

int main(void)
{
  int i;
  int array[SIZE] = {34, -5, 2, 0, 12, 100, 56, 22,
                     44, -3, -9, 11, 17, 29, 6, 18};

  printf("El array antes de ser ordenado:\n");
  for (i = 0; i < SIZE; ++i)
    printf("%i ", array[i]);

  sort(array, SIZE);

  printf("\n\nEl array después de ser ordenado:\n");
  for (i = 0; i < SIZE; ++i)
    printf("%i ", array[i]);

  printf("\n");

  return 0;
}