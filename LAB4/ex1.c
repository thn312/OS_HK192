#include <stdio.h>
#include <stdlib.h>

void *aligned_malloc(unsigned int size, unsigned int align)
{
	void * ptr1 = malloc(size+align+sizeof(void*));
	size_t offset = align - ((size_t)ptr1)%align;

	if(offset < sizeof(void*))
	{
		offset += align;
	}

	void * ptr2 = ptr1 + offset;
	*(void **)((size_t)ptr2-sizeof(void*)) = ptr1;
	
	return ptr2;
}

void *aligned_free(void * ptr)
{ 
	free(*(void **)((size_t)ptr-sizeof(void*)));
}
