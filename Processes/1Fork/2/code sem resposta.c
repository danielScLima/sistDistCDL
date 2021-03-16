#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

//Quantas strings hello serão exibidas?
//Quantos processos serão executados?

int main() 
{
    fork(); //Fork 1 {A, B}
    fork(); //Fork 2 {A1, A2, B1, B2}
    fork(); //Fork 3 {A11, A12, A21, A22, B11, B12, B21, B22}

    printf("hello\n"); 

    return 0; 
} 
