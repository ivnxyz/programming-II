#include <stdio.h>
#include <stdlib.h>

// Definir estructura para el libro
typedef struct {
  char name[100];
  char author[200];
  float price;
} Book;

// Definir funciones
void print_menu();
void print_books(FILE *fp);
void ask_for_book_data(Book *book);
void store_book_data(FILE *fp, Book *book);

/*
¿Cómo funciona este programa?

Este programa le permite ver los libros que quiere comprar, agregar un libro o imprimir la lista de libros que ya se han guardado.
Es una especie de 'wishlist' hecha con C
*/
int main(void) {
  // Almacenar la decisión
  char choice;

  FILE *filePointer;

  do {
    // Imprimir menú y preguntar al usuario qué quiere hacer
    print_menu();
    scanf(" %c", &choice);

    switch (choice) {
      case 'a':
        printf("");

        // Abrir archivo
        filePointer = fopen("books.txt", "a");

        // Pedir datos
        Book *book = (Book *) malloc(sizeof(Book));
        ask_for_book_data(book);
        store_book_data(filePointer, book);

        // Cerrar archivo
        fclose(filePointer);
        break;
      case 'i':
        printf("");
        // Abrir archivo
        filePointer = fopen("books.txt", "r");

        if (filePointer != NULL) {
          // Imprimir libros
          print_books(filePointer);

          // Cerrar archivo
          fclose(filePointer);
        }

        break;
      case 's':
        printf("Adiós!\n");
        break;
      default:
        printf("No reconozco esa opción :(\n");
        break;
    }
  } while (choice != 's');

  return 0;
}

// Imprime el menú del programa
void print_menu() {
  printf("***** BIENVENID@ A SU WISHLIST *****\n");
  printf("¿Qué quiere hacer?\n");
  printf("[a]gregar libro\n");
  printf("[i]mprimir lista\n");
  printf("[s]alir\n\n");
}

// Imprime los libros que el usuario ya tiene
void print_books(FILE *fp) {
  printf("========== LIBROS ==========\n");
  int breaks_count = 0;
  int should_print_name = 1;
  int should_print_author = 1;
  int should_print_price = 1;

  char c;

  // Leer archivo (verificar que no sea el final)
  while (!feof(fp)) {
    c = fgetc(fp);

    if (feof(fp)) {
      break;
    }

    if (c == ';') {
      breaks_count += 1;
    }

    // Determinar si se deben imprimir las cabeceras de los datos
    if (breaks_count == 0 && should_print_name && c != '\n') {
      printf("\n***** TÍTULO *****\n");
      should_print_name = 0;
    } else if (breaks_count == 1 && should_print_author && c != '\n') {
      printf("\n***** AUTOR *****\n");
      should_print_author = 0;
    } else if (breaks_count == 2 && should_print_price && c != '\n') {
      printf("\n***** PRECIO *****\n");
      should_print_price = 0;
    } else if (breaks_count == 3) {
      // Resetear todas las variables
      breaks_count = 0;
      should_print_name = 1;
      should_print_author = 1;
      should_print_price = 1;
      printf("\n==========================\n");
    }

    if (c != ';' && c != '\n') {
      // Imprimir caracter
      printf("%c", c);
    }
  }
}

// Pedir los datos de un libro
void ask_for_book_data(Book *book) {
  printf("Ingrese el nombre del libro: ");
  scanf(" %[^\n]", book->name);

  printf("Ingrese el nombre del autor: ");
  scanf(" %[^\n]", book->author);

  printf("Ingrese el precio del libro: ");
  scanf(" %f", &(book->price));
}

void store_book_data(FILE *fp, Book *book) {
  // Guardar datos
  fprintf(fp, "%s;%s;%f;\n", book->name, book->author, book->price);
}