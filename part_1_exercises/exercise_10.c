#include<stdio.h>
#include<string.h>

typedef struct {
  char titulo[200];
  char autor[80];
  char editorial[80];
  int anio;
} Libro;


// Funcion principal
int main() {
  // Almacenar libros
  int cantidad = 4;
  Libro libros[cantidad];

  // Pedir libros 
  for (int i = 0; i < cantidad; i++) {
    // Pedir titulo
    printf("Ingresa el título del libro %d: ", i + 1);
    scanf(" %[^\n]%*c", libros[i].titulo);

    // Pedir autor
    printf("Ingresa el autor del libro %d: ", i + 1);
    scanf("%[^\n]%*c", libros[i].autor);

    // Pedir editorial
    printf("Ingresa la editorial del libro %d: ", i + 1);
    scanf("%[^\n]%*c", libros[i].editorial);

    // Pedir año
    printf("Ingresa el año de publicación del libro (entero) %d: ", i + 1);
    scanf("%d", &libros[i].anio);
  }

  // Guardar en el archivo
  FILE *f = fopen("libros.txt", "w");

  if (f == NULL) {
      printf("Error al abrir el archivo!\n");
      return 1;
  }

  for (int j = 0; j < cantidad; j++) {
    fprintf(f, "*******************\n");
    // Guardar texto
    fprintf(f, "Libro #%d: %s\n", j + 1, libros[j].titulo);
    fprintf(f, "Autor #%d: %s\n", j + 1, libros[j].autor);
    fprintf(f, "Editorial #%d: %s\n", j + 1, libros[j].editorial);
    fprintf(f, "Año #%d: %d\n", j + 1, libros[j].anio);
    fprintf(f, "*******************\n");
  }

  fclose(f);

  return 0;
}