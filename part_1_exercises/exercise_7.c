#include<stdio.h>

// Declaracion de la estructura
struct estudiante {
    char nombre[50];
    int matricula;
    int edad;
};

// Declaracion de la funcion
void display(struct estudiante estdnt);
void update_age(struct estudiante *student);

// Funcion principal
int main() {
  struct estudiante std;

  printf("Nombre del estudiante: ");
  scanf("%s", std.nombre);
  printf("Matricula: ");
  scanf("%d", &std.matricula);
  printf("Edad: ");
  scanf("%d", &std.edad);

  // Paso de la variable de estructura como argumento
  update_age(&std);
  display(std);

  return 0;
}

// Definicion de la funcion con argumento de tipo struc
void display(struct estudiante estdnt){
  printf("\nNombre del estudiante: %s", estdnt.nombre);
  printf("\nMatricula: %d\n", estdnt.matricula);
  printf("\nEdad: %d\n", estdnt.edad);
}

void update_age(struct estudiante *student) {
  student->edad += 1;
}