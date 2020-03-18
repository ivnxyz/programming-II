/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>

int main() {
  int var1, var2;
  int *var1_ap, *var2_ap;

  var1_ap = &var1;
  var2_ap = &var2;

  // Pedirle los datos al usuario
  printf("Dame var1: ");
  scanf("%d", &var1);

  printf("Dame var2: ");
  scanf("%d", &var2);

  printf("Apuntador: %p Valor var1: %d Valor var1_ap: %d\n", var1_ap, var1, *var1_ap);
  printf("Apuntador: %p Valor var2: %d Valor var2_ap: %d\n", var2_ap, var2, *var2_ap);
  return 0;
}