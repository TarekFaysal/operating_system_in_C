#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
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
    printf("Stage2.c My PID s: %d \n", getpid());

    char *args[100] ;
    int i ;
    for (i = 1; i < argc; i++){
        args[i-1] = argv[i];
    }

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
    else if (execvp(argv [1], args) == -1){
            printf("Command invalid : %s\n", argv[0]);
            perror("command invalid");
            fflush(stdout);
            exit(0);
            return -1;
    }
    return 0;
}

