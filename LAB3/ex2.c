#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(int agrc, char* agrv[]){

pid_t pid1, pid2, pid3, pid4, pid5, pid6, pid7;
printf("A is Parent of all: %d\n",getpid());

pid1 = fork();

if(pid1 == 0){  
    printf("B id: %d, its Parent id: %d \n", getpid(),getppid());
    pid2 = fork();

    if(pid2 == 0){
        printf("E id: %d, its Parent id: %d \n", getpid(),getppid());
        pid3 = fork();
    
        if(pid3 == 0)  {
            printf("I id: %d, its Parent id: %d \n", getpid(),getppid());
        }
        
        else wait(NULL);
    }

    else{
        wait(NULL);
        pid4 = fork();
        
        if(pid4 == 0){
            printf("F id: %d, its Parent id: %d \n", getpid(),getppid());
        }

        else wait(NULL);
    }

}

else{
    wait(NULL);
    pid5 = fork();
    
    if(pid5 == 0){
        printf("C id: %d, its Parent id: %d \n", getpid(),getppid());
        wait(NULL);
        pid6 = fork();
    
        if(pid6 == 0) printf("G id: %d, its Parent id: %d \n", getpid(),getppid());
        else wait(NULL);
    }

    else{
        wait(NULL);
        pid7 = fork();
        if(pid7 == 0) printf("D id: %d, its Parent id: %d \n", getpid(),getppid());
        else wait(NULL);
    }
}
return 0;
}

