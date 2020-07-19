#ifndef MEM_H
#define MEM_H

/* Prealocate memory using standard C malloc.
 * This function returns 0 if success, otherwise, return 1 */
int mem_init(unsigned int size);

/* Allocate a chunks of `size' bytes memory in the preallocated
 * regions created by calling initial function */
void* mem_alloc(unsigned int size);

/* Free allocated memory */
void mem_free(void * ptr);

/* Free used data */
void mem_finish();

#endif

