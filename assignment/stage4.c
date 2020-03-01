#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>



int doForking(char *program, char *args[], char *envp[]){
    printf("I am: %d\n", (int)(getpid()));

    pid_t pid = fork();
    printf("fork returned: %d\n" , (int) pid);

    if(pid < 0){
        perror("fork failed");
    }
    else if (pid == 0){
        printf("I am the child with pid: %d\n", (int)getpid());
        sleep(2);
        if (execve(program, args, envp) == -1){
            perror("command invalid");
            //fflush(stdout);
        }
        printf("child exitting.. \n");
        printf("child finishes with pid: %d\n", (int)getpid());
        exit(0);
    }
    
    printf("I am the parent waiting for the child to end with pid: %d\n", (int)getpid());
    wait(NULL);
    printf("parent ending with pid: %d\n", (int)getpid());
    
    return 0;
}


int cfile(char *source, char *destination){
    FILE *file1, *file2;
    char ch;
    file1 = fopen(source, "r");
    file2 = fopen(destination, "w");
    if (file1 == NULL){
        perror("Unable to read the source file\n");
        if (file2 == NULL){
            perror("Unable to write into destination file\n");  
        }
    }
    else {
        while((ch = fgetc(file1)) != EOF){
            fputc(ch, file2);
        }
        printf("Copied file successfully\n");
    }
    
    
    return 0;
}
int ddir (char *filename){
    if (rmdir(filename) == 0) 
      printf("Deleted directory successfully\n"); 
    else
      perror("Unable to delete the directory\n");
  
   return 0;
}


int df (char *filename){
    if (remove(filename) == 0) 
      printf("Deleted successfully\n"); 
    else
        perror("Unable to delete the file\n"); 
  
   return 0;
}

int dc (char *directory){
    if(chdir(directory) == 0)
        printf("Directory changed\n");
    else 
        perror("Unable to change directory\n");
    return 0;
}

int main (int argc, char *argv[], char * envp[]){
printf("Stage3.c My PID s: %d \n", getpid());

    char *args[100] ;
    char string[256];

        int i ;
        for (i = 1; i < argc; i++){
            args[i-1] = argv[i];
        }
    while (strcmp(args[0], "finish") != 0 ){
    

        if (strcmp(argv[1], "df") == 0 ){
            df(argv[2]);
        }
        else if (strcmp(argv[1], "dc") == 0 ){
            dc(argv[2]);
        }
        else if (strcmp(argv[1], "ddir") == 0 ){
            ddir(argv[2]);
        }
        else if (strcmp(argv[1], "cfile") == 0 ){
            cfile(argv[2], argv[3]);
        }
        else doForking(argv[1], args, envp);

        for (i = 0; i<100; i++){
                args[i] = NULL;
            }
            
            scanf( "%s" , string );
            char * pch;
            pch = strtok (string," ");
            for (i = 0; pch != NULL; i++){
                args[i] = pch;
                pch = strtok (NULL, " ");
            }
    }
    
    return 0;
}


