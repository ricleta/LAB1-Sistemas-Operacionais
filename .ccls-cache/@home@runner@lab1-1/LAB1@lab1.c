#include <stdio.h>
#include "auxiliares.h"

int main(void) 
{
  int tam = 10000;
  int i = 0;
  int soma = 0;
  
  int *arr1 = (int *) malloc(sizeof(int) * tam);
  int *arr2 = (int *) malloc(sizeof(int) * tam);
  int *arr3 =  (int *) malloc(sizeof(int) * tam);
  
  preenche_array(1, tam, arr1);
  preenche_array(2, tam, arr2);
  preenche_array(3, tam, arr3);  
  
  // printf("--------------------\n");
  // printa_array(arr1, tam);
  // printf("--------------------\n");
  // printa_array(arr2, tam);
  // printf("--------------------\n");
  // printa_array(arr3, tam);

  for (i = 0; i < tam; i++)
  {
    soma += arr1[i] + arr2[i] + arr3[i];
  }

  printf("Soma = %d\n", soma);
  
  return 0;
}