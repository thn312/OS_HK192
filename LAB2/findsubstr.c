#include <stdio.h>
#include "findsubstr.h"

int find_sub_string(const char *str, const char* sub){
    int i = 0;
    int j = 0;
    while(str[i] != '\0'){
        if(str[i] == sub[j]){
            j++;
            i++;
            if(sub[j] == '\0') return 1;
        }
       else{
            j=0;
            i++;
       }
    }
    return -1;
}