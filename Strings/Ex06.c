#include <stdio.h>
#include <string.h>//necessário para strtok;

void exibeUltimaPalavra(char frase[50]){
    char *t;
    t = strtok(frase," ");
    while(t != NULL){
        if (strtok(NULL," ") == NULL){
            printf("%s", t);
        }
        t=strtok(NULL," ");
    }
}

int main (void){
    char frase[50];
    fflush(stdin);
    fgets(frase, 50, stdin);
    exibeUltimaPalavra(frase);
    return(0);
}