#include <stdio.h>

int main() {
  // Crear cadena
  char string[50];
  
  printf("Ingresa un texto: ");
  scanf("%[^\n]", string);

  // Crear el primer apuntador
  char *firstPointer = string;
  // Crear el apuntador doble
  char **doublePointer = &firstPointer;

  // Obtener los índices
  int firstVowelIndex = -1;
  int secondVowelIndex = -1;
  char firstCharacter = *(*doublePointer);
  int i = 0;

  while (*(*doublePointer) != '\0') {
    switch (*(*doublePointer)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        // Obtener la primera vocal
        if (firstVowelIndex == -1) {
          firstVowelIndex = i;
        }
        break;
      default:
        break;
    }

    (*(doublePointer))++;
    i++;
  }

  while (i > 0) {
    switch (*(*doublePointer)) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        // Obtener la última vocal
        if (secondVowelIndex == -1) {
          secondVowelIndex = i;
        }
        break;
      default:
        break;
    }

    (*(doublePointer))--;
    i--;
  }

  // Voltear valores
  if (firstVowelIndex != -1 && secondVowelIndex != -1) {
    char temp = *(*doublePointer + firstVowelIndex);
    *(*doublePointer + firstVowelIndex) = *(*doublePointer + secondVowelIndex);
    *(*doublePointer + secondVowelIndex) = temp;
  }

  printf("%s\n", string);

  return 0;
}