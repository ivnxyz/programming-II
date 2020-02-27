#include <stdio.h>

// Estructura para almacenar los datos de un estudiante
struct Student {
  // Declarar los datos
  char first_name[20]; // 20
  char last_name[20]; // 20
  unsigned int age; // 4
  int subjects_ids[6]; // 24
};

int main() {
  // Obtener tamaño de la estructura
  unsigned int struct_size = sizeof(struct Student);
  printf("Tamaño de la estructura: %d\n", struct_size);

  // Inicializar una estructura
  struct Student student;

  // Tamaño de los miembros
  unsigned int first_name_size = sizeof(student.first_name);
  unsigned int last_name_size = sizeof(student.last_name);
  unsigned int age_size = sizeof(student.age);
  unsigned int subjects_size = sizeof(student.subjects_ids);

  // Imprimir datos
  printf("***********************\n");
  printf("Tamaño del nombre: %d\n", first_name_size);
  printf("Tamaño del apellido: %d\n", last_name_size);
  printf("Tamaño de la edad: %d\n", age_size);
  printf("Tamaño de las materias: %d\n", subjects_size);

  return 0;
}