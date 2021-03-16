#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 

//Quantas strings hello serão exibidas?
//Quantos processos serão executados?

int main() 
{
	//até essa linha tem 1 processo
 
    fork(); //Fork 1: executará da linha 10-end (com essa linha, até agora tem 2 proc)
    fork(); //Fork 2: executará da linha 11-end (com essa linha, ate agora, tem 4 proc)
    fork(); //Fork 3: executará da linha 12-end (com essa linha, ate agora, tem 8 proc)

    printf("hello\n"); 
    
    //Execute com: ./saida | wc -l

    return 0; 
} 
