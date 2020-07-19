
#ifndef STRUCTS_H
#define STRUCTS_H

#include <pthread.h>

/* The PCB of a process */
struct pcb_t {
	/* Values initialized for each process */
	int arrival_time; 	// The timestamp at which process arrives
				// and wishes to start
	int burst_time;		// The amount of time that process requires
				// to complete its job
	int pid;		// process id
};

/* 'Wrapper' of PCB in a queue */
struct qitem_t {
	struct pcb_t * data;
	struct qitem_t * next;	
};

/* The 'queue' used for both ready queue and in_queue (e.g. the list of
 * processes that will be loaded in the future) */
struct pqueue_t {
	/* HEAD and TAIL for queue */
	struct qitem_t * head;
	struct qitem_t * tail;
	/* MUTEX used to protect the queue from
	 * being modified by multiple threads*/
	pthread_mutex_t lock;
};

#endif


