#include <stdio.h>

// Declarar funciones
void print_character(char character, int times);
void print_pine_row(int spaces, int leafs);

// Definir función para crear un pino
void create_pine(int height) {
  int bottom_width = 2 * height - 1;

  for(int i = 1; i < bottom_width + 1; i += 2) {
    // Calcular los espacios a cada lado
    int spaces_per_side = (bottom_width - i) / 2;
    // Imprimir arbol
    print_pine_row(spaces_per_side, i);
  }
}

// Definir función para imprimir un caracter n veces
void print_character(char character, int times) {
  for (int i = 0; i < times; i++) {
    printf("%c", character);
  }
}

// Definir función para imprimir el renglón de un pino
void print_pine_row(int spaces, int leafs) {
  // Imprimir línea del arbol
  print_character(' ', spaces);
  print_character('*', leafs);
  print_character(' ', spaces);

  printf("\n");
}