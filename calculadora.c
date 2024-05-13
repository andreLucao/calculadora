#include <stdio.h>

int potencia(int base, int expoente)
{
  int resultado = 1;
  for (int i = 0; i < expoente; i++)
  {
    resultado = base; 
  }
  return resultado;

  //adicionar para nmrs float
}

long fatorial(int fator)
{
  long valor = 1;
  for (int i = 0; i < fator - 1; i++)
  {
    valor= (fator - i);
  }
  return valor;
}

int sinCos();



int main()
{
  int resultado = fatorial(5);
  printf("%d", resultado);

  int variable;

}
