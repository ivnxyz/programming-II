#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

void print_menu();

int main() {
  // Almacenar decisión del usuario
  char choice;

  do {
    // Pedirle los datos al usuario
    printf("\nElige una opción del menú: \n");
    print_menu();
    scanf(" %c", &choice);
    system("@cls||clear");
    // Evaluar decisión del usuario
    switch (choice) {
      case 's':
        say_hello();
        break;
      case 'c':
        calculate_triangle_area();
        break;
      case 'x':
        say_goodbye();
        break;
      default:
        unknown_choice();
        break;
    }
  } while (choice != 'x');

  return 0;
}

// Definir función para imprimir el menú
void print_menu() {
  printf("\n**********************\n");
  printf("[s]aludar\n");
  printf("[c]alcular el área de un triángulo\n");
  printf("[x]para salir\n");
  printf("**********************\n");
}