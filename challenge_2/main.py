def generate_pine(n):
  bottom_length = 2*n - 1

  # Imprimir pino
  for i in range(1, bottom_length + 1, 2):
    spaces_per_side = (bottom_length - i)//2
    spaces = " " * spaces_per_side
    symbols = "*" * i

    print(spaces + symbols + spaces)

# Punto de entrada del programa
if __name__ == '__main__':
  # Pedirle los datos al usuario
  n = int(input("Ingresa el alto del árbol: "))
  generate_pine(n)