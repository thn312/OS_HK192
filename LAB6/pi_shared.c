#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NThread 100

long n = 0;
pthread_mutex_t mutex;

void* genPoint(void* p){
	double x, y;
	unsigned int seed = rand();
	int count = 0;
	for(int i = 0; i < (size_t)p; i++){
		x = (double)rand_r(&seed) / ((double)RAND_MAX/2);
		y = (double)rand_r(&seed) / ((double)RAND_MAX/2);
		if((x-1)*(x-1) + (y-1)*(y-1) < 1) count++;
	}

    pthread_mutex_lock(&mutex);
    n+=count;
    pthread_mutex_unlock(&mutex);
	pthread_exit((void*)n);
}

int main(int argc, char* argv[]){
	clock_t start = clock();
	pthread_t tid[NThread];

	size_t N = atoi(argv[1]);
	void* rv;

    pthread_mutex_init(&mutex,NULL);

	for(int i = 0; i < NThread; i++){
		pthread_create(&tid[i] , NULL, genPoint, (void*)(N/NThread));
	}

	for(int i = 0; i < NThread; i++){
		pthread_join(tid[i], &rv) ;
	}
	double pi = (double)4*n/N;
    
    pthread_mutex_destroy(&mutex);
	clock_t stop = clock();
    
    // TODO: You must the execution time in milliseconds
	double misecs = ((double)(stop - start)* 1000.0)/CLOCKS_PER_SEC;
    printf("Pi: %f\nTime: %f ms\n", pi, misecs); 
}