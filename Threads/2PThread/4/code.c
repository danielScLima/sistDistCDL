#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

/*Rotina que será executada pelos dois threads*/
void * routine(void *arg);

int main (int argc, char *argv[])
{
	pthread_t thread_ids[5];
	char nomes [5][100] = {"Thread A","Thread B","Thread C","Thread D","Thread E"};
	void * thread_res = NULL;
	int rstatus;
	int i;
	
	/*tenta iniciar o thread, indicando a função 'routine' e passando como argumento a string "Thread A"*/
	for (i=0;i<5;++i)
	{
		rstatus = pthread_create (&thread_ids[i], NULL, routine, (void*)(nomes[i]));
		
		/*verificar se ocorreu algum erro na chamada de pthread_create*/
		if(rstatus != 0)
		{
			printf ("Erro ao criar o thread %d.\n", i);
			exit(EXIT_FAILURE);
		}

		printf ("Thread %d (%s) criada com sucesso!\n", i, nomes[i]);
	}

	/*aguarda finalização do thread A identificado por thread_idA. O retorno é passado pelo ponteiro thread_res*/
	for (i=0;i<5;++i)
	{
		rstatus = pthread_join (thread_ids[i], &thread_res);

		if(rstatus != 0)
		{
			printf ("Erro ao aguardar finalização do thread %d.\n", i);
			exit(EXIT_FAILURE);
		}

		printf ("Thread %d finalizada! Retorno = %s\n", i, (char *)thread_res);
	}

	return 0;
}

void * routine(void *arg)
{
	int contador = 10;

	/*procedimento para decrementar um contador e exibir o seu valor*/
	while(contador--)
	{
		printf("%s: %i\n", (char *)arg, contador);
		
		//O comando abaixo força a interrupção da thread
		sched_yield();
	}

	/*finaliza a função retornando o argumento que foi recebido*/
	pthread_exit(arg);
}
