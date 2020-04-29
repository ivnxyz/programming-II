#include <stdio.h>
#include <stdlib.h>

// Definir estructura
typedef struct {
  char name[200];
  char facebook[100];
  char birthday[30];
  char twitter[40];
  char address[200];
  char marital_status[40];
} Person;

// Declarar funciones
void ask_for_data(Person *persons, int data);
void save_date(FILE *filePointer, Person *persons, int data);

// Función principal
int main(void) {
  // Inicializar arreglo para las personas
  Person *persons = (Person *) malloc(sizeof(Person));

  // Preguntar al usuario cuántos datos va a ingresar
  int data;
  printf("¿Cuántas personas vas a agregar? ");
  scanf("%d", &data);

  // Pedir datos
  ask_for_data(persons, data);

  // Abrir archivo donde se guardarán los datos
  FILE *filePointer = fopen("datos.txt", "w");

  // Verificar que sí se abrió el archivo
  if (filePointer == NULL) {
    printf("Ocurrió un error al abrir el archivo donde se van a guardar los datos\n");
    return 1;
  }

  // Guardar los datos
  save_date(filePointer, persons, data);

  return 0;
}

void ask_for_data(Person *persons, int data) {
  // Pedir los datos
  for(int i = 0; i < data; i++) {
    printf("Ingresa el nombre completo #%d: ", i + 1);
    scanf(" %[^\n]", (persons + i)->name);

    printf("Ingresa el nombre de Facebook #%d: ", i + 1);
    scanf(" %[^\n]", (persons + i)->facebook);

    printf("Ingresa la fecha de nacimiento (día/mes/año) #%d: ", i + 1);
    scanf(" %[^\n]", (persons + i)->birthday);

    printf("Ingresa el nombre de usuario en Twitter #%d: ", i + 1);
    scanf(" %[^\n]", (persons + i)->twitter);

    printf("Ingresa la dirección #%d: ", i + 1);
    scanf(" %[^\n]", (persons + i)->address);

    printf("Ingresa el situación civil (casado/soltero) #%d: ", i + 1);
    scanf(" %[^\n]", (persons + i)->marital_status);

    // Imprimir separador
    printf("======================================\n");
  }
}

// Guardar los datos en un archivo externo
void save_date(FILE *filePointer, Person *persons, int data) {
  printf("***** GUARDANDO DATOS *****\n");

  for (int i = 0; i < data; i++) {
    // Guardar persona
    fprintf(
      filePointer,
      "%s;%s;%s;%s;%s;%s;\n",
      (persons + i)->name,
      (persons + i)->facebook,
      (persons + i)->birthday,
      (persons + i)->twitter,
      (persons + i)->address,
      (persons + i)->marital_status
    );
  }

  printf("Se guardaron los datos en el archivo!\n");
}