#include <stdio.h>
#include "readline.h"
#include "findsubstr.h"
#define MAX_LINE  100
int main( int argc , char *argv [] ) {
    if(argc < 2) return -1;
    char line[MAX_LINE];

    while(1){
        int i = 0;    
        while(i< MAX_LINE){
            char input = getchar();
            line[i] = input;
            if(line[i] == '\n' || line[i] == EOF) break;
            i++;
        }
        line[i+1] = '\0';
        if(read_line(line) == -1) break;
        else{
            if(find_sub_string(line,argv[1]) != -1) printf("%s",line);
        } 
    }
    return 0;   
}