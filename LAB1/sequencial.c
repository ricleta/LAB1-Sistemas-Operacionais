#include <stdio.h>
#include "auxiliares.h"

int main(void) 
{
  int tam = 100000;
  int i = 0;
  Timer comeco, fim;
  int status;
  
  int *vetA = (int *) malloc(sizeof(int) * tam);
  int *vetB = (int *) malloc(sizeof(int) * tam);
  int *vetC =  (int *) malloc(sizeof(int) * tam);
  
  preenche_array(1, tam, vetA);
  preenche_array(2, tam, vetB);

  gettimeofday(&comeco, NULL); // incio

  for (int j = 0; j < 8; j++)
  {
    if (fork() == 0)
    {
      waitpid(-1, &status, 0);
      exit(0);
    }
  }
  
  for (i = 0; i < tam; i++)
  {
    vetC[i] = vetA[i] + vetB[i];
  }

  gettimeofday(&fim, NULL);
  
  // printa_array(vetC, tam);

  printf("\nTempo : %f ms\n", timediff(comeco, fim)); // fim
  
  return 0;
}