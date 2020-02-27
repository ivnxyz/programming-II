/* ********************* TEXTO SIN ACENTOS *********************/
// Recuerda documentar tus codigos

#include <stdio.h>

struct item
{
  int code;
  float price;
  int discountCode;
};

struct item product()
{
  struct item stock;

  printf("\t\tIngrese el codigo de producto:");
  scanf("%i", &stock.code);

  printf("\t\tIngrese el precio:");
  scanf("%f", &stock.price);

  printf("\t\tIngresa el código de descuento:");
  scanf("%d", &stock.discountCode);

  return stock;
};

int main()
{
  struct item pro1;
  pro1 = product();

  printf("\t\t\tDatos del producto\n");

  printf("Codigo del producto:%i\n", pro1.code);
  printf("precio:$ %0.2f MXN\n", pro1.price);

  float descuento = 0;

  switch (pro1.discountCode)
  {
  case 1000:
    descuento = pro1.price * 0.3;
    break;
  case 420:
    descuento = pro1.price * 0.5;
    break;
  case 100:
    descuento = pro1.price * 0.2;
    break;
  default:
    break;
  }

  printf("precio con descuento:$ %0.2f MXN\n", pro1.price - descuento);

  return 0;
}