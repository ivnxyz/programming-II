#include <stdio.h>

void swap(int *, int *);
void sort3(int *, int *, int *);

void swap(int *p, int *q)
{
  int temp;

  temp = *p;
  *p = *q;
  *q = temp;
}

void sort3(int *a, int *b, int *c)
{
  if (*a > *b)
    swap(a, b);
  if (*a > *c)
    swap(a, c);
  if (*b > *c)
    swap(b, c);
}

int main(void)
{
  int i1 = 110, i2 = 345, i3 = 81;

  printf("%i %i %i -> ", i1, i2, i3);
  sort3(&i1, &i2, &i3);
  printf("%i %i %i\n", i1, i2, i3);

  return 0;
}