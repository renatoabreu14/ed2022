#include <stdio.h>
#include <string.h>

char* substituiCaracter(char texto[50], char p, char s){
    int pos = 0;
    while (texto[pos] != '\n'){
        if (texto[pos] == p){
            texto[pos] = s;
        }
        pos++;
    }
    return texto;
}

int main(){
    char frase[50];
    fflush(stdin);
    fgets(frase, 50, stdin);
    substituiCaracter(frase, 'o', 'a');
    printf("%s\n", frase);
    return 0;
}