#include <stdio.h>

struct entry
{
  int value;
  struct entry *next;
};

void insertEntry(struct entry *entry, struct entry *after);

int main(void)
{
  // Declarar entradas
  struct entry n1, n2, n3;

  n1.value = 100;
  n2.value = 200;
  n3.value = 300;

  n1.next = &n2;
  n2.next = &n3;

  // Pedir dato al usuario
  int i;

  printf("Ingresa el valor que quieres agregar: ");
  scanf("%d", &i);

  // Crear nueva estructura para el valor
  struct entry n;
  n.value = i;

  printf("Antes de llamar a la función\n");
  printf("%i ", n2.value);
  printf(" %i \n", n2.next->value);

  // Llamar a la función
  insertEntry(&n, &n2);

  printf("Después de llamar a la función\n");
  printf("%i ", n2.value);
  printf(" %i \n", n2.next->value);

  return 0;
}

void insertEntry(struct entry *entry, struct entry *after)
{
  entry->next = after->next;
  after->next = entry;
}