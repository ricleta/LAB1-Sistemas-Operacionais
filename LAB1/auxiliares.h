#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>


typedef struct timeval Timer;

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

//espera n processos filho terminarem
void wait_workers(int n){
  int error;
  for(int i=0;i<n;i++)
    waitpid(-1,&error,0);
}

//gera nProc processos filhos e 1 pai
int workers(int nProc){
  int i,error;
  int aux;
  for(i=0;i<nProc;i++){
    aux=fork();
    if(aux==0){
      break;
    }
  }
  return i;
}


//calcula a diferenca de tempo entre dois Timers 
float timediff(Timer t0, Timer t1)
{
	return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}