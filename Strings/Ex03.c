#include <stdio.h>
#include <stdlib.h>
#include <string.h>//necessário para strtok;

int contaPalavras(char frase[50]){
    char *t;
    t = strtok(frase," ");
    int cont = 0;
    while(t != NULL){
        cont++;
        t=strtok(NULL," ");
    }
    return cont;
}

int main (void)
{
    char frase[50];
    fflush(stdin);
    fgets(frase, 50, stdin);
    printf("%i\n", contaPalavras(frase));
    return(0);
}