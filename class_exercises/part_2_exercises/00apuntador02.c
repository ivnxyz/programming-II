#include <stdio.h>

int main(){
  int var1=6, var2=4, var3=0; // Aquí se declarar y definen 3 variables
  int *var1_ap, *var2_ap; // Aquí declaran dos variables apuntador

  var1_ap = &var3; // Aquí se usa el operador de referencia
  var3 = var1 + var2; // Aquí se operan dos apuntadores

  printf("%p %d %p %d\n", var1_ap, var3, &var3, *var1_ap); // Aquí se usan los operadores de deferencia para acceder a los valores de variables apuntador

  return 0;
}