#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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


//gera nProc processos
int __workers(int nProc){
  int i,error;
  for(i=0;i<nProc;i++){
    if(fork()!=0){
      waitpid(-1, &error, 0);
    }else{
      break;
    }
  }
  return i;
}

//wrapper
int workers(int nProc){
  return __workers(nProc-1);
}

//calcula a diferenca de tempo entre dois Timers 
float timediff(Timer t0, struct Timer t1)
{
	return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}