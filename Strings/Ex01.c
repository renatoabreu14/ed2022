#include <stdio.h>

int tamanhostring(char str[21]){
    int tam = 0;
    while ((str[tam] != '\n')/*||(str[tam] != '\0')*/){
        tam++;
    }
    return tam;
}

int main(){
    char str1[21];
    fflush(stdin);
    fgets(str1, 21, stdin);
    printf("O tamanho de str1 é: %i", tamanhostring(str1));
}