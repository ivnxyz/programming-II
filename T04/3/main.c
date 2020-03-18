#include <stdio.h>

struct entry
{
  int value;
  struct entry *next;
};

void insertEntry(struct entry *newEntry, struct entry *existingEntry)
{
  newEntry->next = existingEntry->next;
  existingEntry->next = newEntry;
}

int main(void)
{
  void insertEntry(struct entry * newEntry, struct entry * existingEntry);

  struct entry head, n1, n2, nE;
  struct entry *listPointer;

  head.next = &n1;

  n1.value = 100;
  n1.next = &n2;

  n2.value = 200;
  n2.next = (struct entry *)0;

  listPointer = head.next;

  printf("Valores en la lista antes de insertar una entrada:");
  while (listPointer != (struct entry *)0)
  {
    printf("%i ", listPointer->value);
    listPointer = listPointer->next;
  }
  printf("\n");

  nE.value = 50;
  insertEntry(&nE, &head);

  listPointer = head.next;

  printf("Valores en la lista después de insertar una entrada:");
  while (listPointer != (struct entry *)0)
  {
    printf("%i ", listPointer->value);
    listPointer = listPointer->next;
  }
  printf("\n");

  return 0;
}