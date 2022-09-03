#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include "auxiliares.h"

int main(void)
{
  int tam = 1000, tam_p = tam / 8;
  int i = 0;
  int soma = 0;
  Timer comeco, fim;
  int worker_num;
  int segmento;

  int *arr1 = (int *)malloc(sizeof(int) * tam);
  int *arr2 = (int *)malloc(sizeof(int) * tam);
  int **arr3; /* Eu acho que tem que ser double pointer
                 Pq se ele retornar um endereço de memoria
                 compartilhado, ent na hora que desse o
                 malloc iria sobrescrever (?)         */

  preenche_array(1, tam, arr1);
  preenche_array(2, tam, arr2);
  preenche_array(0, tam, arr3);

  segmento = shmget(IPC_PRIVATE, sizeof(int), IPC_CREATE | IPC_EXCL | S_IRUSR | S_IWUSR);
  arr3 = (int **)shmat(segmento, 0, 0);
  
  *arr3 = (int *)malloc(sizeof(int) * tam);
  // printf("--------------------\n");
  // printa_array(arr1, tam);
  // printf("--------------------\n");
  // printa_array(arr2, tam);
  // printf("--------------------\n");
  // printa_array(arr3, tam);

  gettimeofday(&comeco, NULL); // incio

  worker_num = workers(8);

  /*
    estou gerando 8 processos, porem talvez seja pra gerar 9
    8 filhos e 1 pai
  */

  for (int i = comeco; i < fim; i++)
  {
    *arr3[i] = arr1[i] + arr2[i];
  }

  gettimeofday(&fim, NULL);

  printa_array(arr3, tam);

  printf("\nTempo : %d ms\n", timediff(comeco, fim)); // fim

  free(arr1);
  free(arr2);
  shmdt(p);
  // libera a memória compartilhada
  free(*arr3); // N sei se o free deveria ser aqui
  shmctl(segmento, IPC_RMID, 0);

  return 0;
}