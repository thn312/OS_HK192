#include <stdio.h>
#include "readline.h"

int read_line(char *str){
    int i = 0;
   	while(str[i] != '\0'){
		if(str[i] == '\n') return i;
		i++;
	}
    return -1;
}
