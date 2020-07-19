
#include "mem.h"
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void * proc(void *args) {
	int i;
	int index = 0;
	char * mem[ARRAY_SIZE];
	for (i = 0; i < ARRAY_SIZE; i++) {
		if (rand() % 2) {
			/* Allocate memory */
			unsigned int size = 1 << ((rand() % 4) + 4);
			mem[index] = mem_alloc(size);
			if (mem[index] != NULL) {
				index++;
			}
		}else{
			// Free memory
			if (index == 0) {
				continue;
			}
			unsigned char j = rand() % index;
			mem_free(mem[j]);
			mem[j] = mem[index - 1];
			index--;
		}
	}
}

int main() {
	
	srand(time(NULL));
	
	// Allocate 1KB memory
	mem_init(1 << 10);
	
	pthread_t p_0, p_1;
	pthread_create(&p_0, NULL, proc, NULL);
	pthread_create(&p_1, NULL, proc, NULL);
	pthread_join(p_0, NULL);
	pthread_join(p_1, NULL);
	
	mem_finish();
	
}

