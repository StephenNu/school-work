#include <stdio.h>
#include <pthread.h>
#define NTHREADS 10
#define COUNT1 3
#define COUNT2 6
void *thread_fun(void *);
void *thread_fun2(void *);
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_var = PTHREAD_COND_INITIALIZER;
int counter = 0;

int main() 
{
	pthread_t thread_id1, thread_id2;
	int i, j;
	pthread_create(&thread_id1, NULL, thread_fun, NULL);
	pthread_create(&thread_id2, NULL, thread_fun2, NULL);
	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);

	printf("final value %d\n", counter);
	return 0;
}

void *thread_fun(void *dummy)
{
	for (;;)
	{
		pthread_mutex_lock(&mutex1);
		pthread_cond_wait(&cond_var, &mutex1 );

		counter++;
		printf("thread 1 value = %d\n", counter);
		pthread_mutex_unlock(&mutex1);
		if (counter >= NTHREADS) 
		{
			return NULL;
		}
	}
}
void *thread_fun2(void *dummy)
{
	for (;;)
	{
		pthread_mutex_lock (&mutex1);
		if (counter < COUNT1 || counter > COUNT2 )
		{
			pthread_cond_signal(&cond_var);
		}
		else
		{
			counter++;
			printf("fun2 value %d\n", counter);
		}
		pthread_mutex_unlock(&mutex1);
		if (counter >= NTHREADS) 
		{
			return NULL;
		}
	}
}
