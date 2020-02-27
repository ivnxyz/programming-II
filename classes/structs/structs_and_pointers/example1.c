#include <stdio.h>

// Declarar una estructura
typedef struct Point { // Con typedef se le da un nuevo nombre al tipo 'Point', con esto ya no se tiene que escribir 'struct Point' al declarar un punto
  int x;
  int y;
} Point; // Point es el nombre del tipo 'struct Point'

// Una función que toma un punto y lo imprime
void display(Point p);
void displayByReference(Point *pointPointer); // Esta hace lo mismo pero por referencia

int main() {
  // Declarar el apuntador
  Point *pointPointer; // pointPointer almacenará la dirección de una estructura Point
  
  // Declarar el punto 1
  Point point1;

  // Asignarle un valor al apuntador
  pointPointer = &point1;
  printf("%p\n", pointPointer);

  // Obtener valores de la estructura
  printf("x: %d\n", pointPointer->x);
  printf("y: %d\n", pointPointer->y);

  // Guardar datos en la estructura en el apuntador
  printf("Ingresa x1: ");
  scanf("%d", &pointPointer->x);

  printf("Ingresa y1: ");
  scanf("%d", &pointPointer->y);

  // Volver a obtener valores de la estructura
  printf("x: %d\n", pointPointer->x);
  printf("y: %d\n", pointPointer->y);

  // Otra forma de obtener los valores de la estructura
  printf("x: %d\n", (*pointPointer).x);
  printf("y: %d\n", (*pointPointer).y);

  // Pasarle el punto a la función
  display(*pointPointer);
  display(*pointPointer);

  // Pasarle el punto a la función por referencia
  displayByReference(pointPointer);
  displayByReference(pointPointer);

  return 0;
}

// Definición de la función
// Aquí se pasa la estructura por copia
void display(Point p) {
  printf("************* Punto **************\n");
  printf("%d\n", p.x);
  printf("%d\n", p.y);

  // Modificar el punto
  p.x = 1000;
}

void displayByReference(Point *pointPointer) {
  printf("************* Punto **************\n");
  printf("%d\n", pointPointer->x);
  printf("%d\n", pointPointer->y);

  // Modificar el punto
  pointPointer->x = 1000;
}