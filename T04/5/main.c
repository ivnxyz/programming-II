#include <stdio.h>

struct entryD
{
  int value;
  struct entryD *previous;
  struct entryD *next;
};

void print_list(struct entryD *);

void print_dlist(struct entryD *p)
{
  int i;

  for (i = 1; p; ++i)
  {
    printf("n%i (%p)\n", i, (void *)p);
    printf(" valor: %i\n", p->value);
    printf(" siguiente: %p\n", (void *)p->next);
    printf(" anterior: %p\n", (void *)p->previous);
    p = p->next;
  }
}

int main(void)
{
  struct entryD n1, n2, n3, n4, n5;
  struct entryD *list_pointer = &n1;

  n1.value = 100;
  n1.previous = NULL;
  n1.next = &n2;

  n2.value = 200;
  n2.previous = &n1;
  n2.next = &n3;

  n3.value = 300;
  n3.previous = &n2;
  n3.next = &n4;

  n4.value = 400;
  n4.previous = &n3;
  n4.next = &n5;

  n5.value = 500;
  n5.previous = &n4;
  n5.next = NULL;

  print_dlist(list_pointer);

  return 0;
}