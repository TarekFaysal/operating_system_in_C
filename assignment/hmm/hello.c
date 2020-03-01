#include <stdio.h> 
#include <unistd.h>
int main(int argc, char *argv[]) 
{ 
    printf("hello.c\n");
    printf("my pid %d. \n", getpid());
    printf("My Arguements: ");
    for (int i = 0; i< argc; i++){
        printf("%s, ",argv[i] );
    }
    printf("\n");

    return 0;
     
} 