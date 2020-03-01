#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main (int argc, char *argv[], char * envp[]){
printf("Stage1.c My PID s: %d \n", getpid());
    char string[100];
    char *args[100] ;
    int i ;
    scanf( "%[^\n]" , string );
    printf("%s", string);
    char * pch;
    pch = strtok (string," ");
    for (i = 0; pch != NULL; i++){
        args[i] = pch;
        pch = strtok (NULL, " ");
    }
    //for (i = 0; i< 3; i++){
      //  printf("%s", args[i]);
    //}

    return 0;
}