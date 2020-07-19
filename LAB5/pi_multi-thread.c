#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS 100
typedef struct{
    int id;
    int nPoints;
    int count;
} Info_Thread;

Info_Thread p[NUM_THREADS];
pthread_t tid[NUM_THREADS];
int nPoints = 0;
int range = 0;
time_t    start = 0, end = 0; 

void *calPi(void *param){
    
    Info_Thread *p = (Info_Thread*)param;
    int seed = rand();
    srand(time(NULL));
    for(int  i =0; i < p->nPoints; i++){    
        double x = (double)rand_r(&seed)/(double)RAND_MAX;
        double y = (double)rand_r(&seed)/(double)RAND_MAX;
        if((x*x) + (y*y) <= 1){
            p->count ++;
        }
    }
    pthread_exit(EXIT_SUCCESS);
}

int main(int argc, char* argv[]){
    time(&start);

    if(argc != 2){
        printf("Missing nPoints !!");
        return -1;
    }

    nPoints = atoi(argv[1]);
    srand(time(NULL));
    for(int i = 0; i < NUM_THREADS; i++){
        p[i].id = i;
        p[i].count = 0;
        p[i].nPoints = nPoints/NUM_THREADS;
        pthread_create(&tid[i],NULL,calPi,&p[i]);
    }
    
    int count = 0;
    for(int i =0; i< NUM_THREADS; i++){
        pthread_join(tid[i],NULL);
        count += p[i].count;
    }

    //  printf("nPOints = %d\nPOint = %d\n",nPoints,count);
    
   
    double pi = 4*((double)(count)/(double)nPoints);
    
    time(&end); 
    double time_spend = difftime(end, start);
    
    printf("Pi = %f\nTime = %f sec\n",pi,time_spend);
    pthread_exit(EXIT_SUCCESS);
    return 0;
}
