#include <stdio.h>
#include <stdlib.h>

// Declaración de la estructura para los productos
typedef struct {
  char name[100];
  double price;
} Product;

// Declarar funciones
void print_menu(void);
void add_product(Product *products, int *n);
void print_products(Product *products, int *n);

/*
¿Cómo funciona este programa?

Con este programa los dueños de una tienda de abarrotes pueden almacenar productos.
Como nota, cada vez que se termina el programa, la lista de productos se elimina.
*/
int main(void) {
  // Preguntarle al usuario qué quiere hacer
  char choice;

  // Inicializar variable con el número de elementos en la lista
  int *number_of_products = (int *) calloc(1, sizeof(int));
  // Inicializar lista de productos
  Product *products = (Product *) malloc(sizeof(Product) * (*number_of_products));

  do {
    print_menu();
    // Almacenar decisión
    scanf(" %c", &choice);

    switch(choice) {
      case 'a':
        add_product(products, number_of_products);
        break;
      case 'i':
        print_products(products, number_of_products);
        break;
      case 's':
        printf("Adiós :)\n");
        break;
      default:
        printf("No reconozco esa opción\n");
        break;
    }
  } while (choice != 's');

  return 0;
}

// Imprime el menú al usuario
void print_menu(void) {
  printf("\n***** BIENVENIDO *****\n");
  printf("¿Qué quiere hacer?\n");
  printf("[a]gregar producto\n");
  printf("[i]mprimir productos\n");
  printf("[s]alir\n\n");
}

// Pedirle los datos al usuario y almacenarlos en la lista de productos
void add_product(Product *products, int *n) {
  // Aumentar el número de productos y modificar el tamaño de la lista de productos
  products = (Product *) realloc(products, sizeof(Product) * (++(*n)));

  // Pedirle los datos
  printf("***** AGREGAR PRODUCTO *****\n");
  printf("Ingrese el nombre: ");
  scanf(" %[^\n]", (products + (*n - 1))->name);
  printf("Ingrese el precio: ");
  scanf(" %lf", &((products + (*n - 1))->price));
}

// Imprime los productos
void print_products(Product *products, int *n) {
  printf("\n***** PRODUCTOS *****\n");

  for (int i = 0; i < *n; i++) {
    printf("===== %s =====\n", (products + i)->name);
    printf("Precio: %f\n", (products + i)->price);
  }
}