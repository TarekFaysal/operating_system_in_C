#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[], char * envp[]){
printf("Stage1.c My PID s: %d \n", getpid());

    char *args[100] ;
    int i ;
    for (i = 1; i < argc; i++){
        args[i-1] = argv[i];
    }
    execve(argv[1], args, envp);
    return 0;
}