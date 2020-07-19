#include<stdio.h>
#include<pthread.h>

void *hello(void *tid){
    printf("Hello from thread %d\n", (int)tid);
}

int main(){
    pthread_t tid[10];
    int i;
    for(i = 0; i<10; i++){
        pthread_create(&tid[i], NULL, hello, (void*)i);
        pthread_join(tid[i],NULL);
    }
    pthread_exit(NULL);
}