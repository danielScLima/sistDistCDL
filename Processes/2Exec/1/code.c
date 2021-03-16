#include <stdio.h>
#include <unistd.h>

int main()
{
      //execl("/bin/ls","ls","code.c",NULL) ;     //Exemplo 1
      execl("/bin/cat","cat","code.c",NULL) ;   //Exemplo 2
      //execl("/bin/tree","tree","-c",NULL) ;       //Exemplo 3
      
      //A linha abaixo não é executada
      printf ("Eu ainda nao estou morto\n") ;
      
      return 0;
}
