#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int agrc, char* argv[]){
    FILE* f = fopen("numbers.txt","r");
    if(!f) {
        printf("No file !");
        return -1;
    }
    char line[255];
    int arr[255];
    int size = 0;

    while(fgets(line,255,f)){
        arr[size] = atoi(line);
        size++;
    }
    fclose(f);
    int count2 = 0, count3 = 0; 
    if(fork() == 0){
        for(int i = 0; i< size; i++){
            if(arr[i] % 3 ==0){
                count3 ++;
            }
        }
        printf("%d\n",count3);
    }
    else{
        for(int i =0 ; i< size; i++){
            if(arr[i] % 2 == 0) count2++;
        }
        printf("%d\n",count2);
    }
    return 0;
}