#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

void forkExample() 
{ 
    // child process because return value zero 
    int ret;
    ret = fork();
    if (ret == 0) //É o processo filho
    {
        printf("Hello from Child!\n"); 
  	}
    // parent process because return value non-zero. 
    else if (ret > 0) //é o processo pai e deu certo criar o filho 
    {
        printf("Hello from Parent. The child was created!\n"); 
    }
    else //if ret is negative
    {
    	printf("Hello from Parent. The child could not be created!\n"); 
    }
} 

int main() 
{ 
    forkExample(); 

    return 0; 
} 
