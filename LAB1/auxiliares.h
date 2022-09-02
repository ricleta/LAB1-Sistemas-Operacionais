#include <stdio.h>
#include <stdlib.h>

// malloca memoria para um vetor de tamanho tam e bota o
// valor de cada elemento como valor
void preenche_array(int valor, int tam, int *arr)
{
  int i;

  if (arr == NULL)
  {
    exit(-1);
  }

  for (i = 0; i < tam; i++)
  {
    arr[i] = valor;
  }
}

void printa_array(int *arr, int tam)
{
  for (int i = 0; i < tam; i++)
  {
    printf("Pos %d = %d\n", i, arr[i]);    
  }
}