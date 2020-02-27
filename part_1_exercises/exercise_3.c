#include<stdio.h>
#include <string.h>

// Creamos una estructura con rotulo estudiante

struct estudiante{
  char nombre_estu[50];
  int codigo_estu;
  float califi_estu;
};


int main() {
  // Declarar variables para los estudiantes
  struct estudiante estudiante1, *pointer_estu1;
  struct estudiante estudiante2, *pointer_estu2;
  struct estudiante estudiante3, *pointer_estu3;

  // Asignar apuntadores
  pointer_estu1 = &estudiante1;
  pointer_estu2 = &estudiante2;
  pointer_estu3 = &estudiante3;

  // Asignar datos a las estructuras
  strcpy(pointer_estu1 -> nombre_estu, "Jose Perez");
  pointer_estu1 -> codigo_estu = 21212;
  pointer_estu1 -> califi_estu = 9.5;

  strcpy(pointer_estu2->nombre_estu, "Perla Perez");
  pointer_estu2->codigo_estu = 21111;
  pointer_estu2->califi_estu = 10;

  strcpy(pointer_estu3->nombre_estu, "Iván Martinez");
  pointer_estu3->codigo_estu = 11111;
  pointer_estu3->califi_estu = 9.5;

  // Guardar estudiantes en un array
  struct estudiante estudiantes[] = {estudiante1, estudiante2, estudiante3};

  // imprimir datos en pantalla
  for (int i = 0; i < sizeof(estudiantes)/sizeof(struct estudiante); i++) {
    printf("El nombre del estudiante es: %s \n", estudiantes[i].nombre_estu);
    printf("El codigo del estudiante es: %i \n", estudiantes[i].codigo_estu);
    printf("La calificacion del estudiante es: %2.1f \n", estudiantes[i].califi_estu);
  }

  return 0;
}