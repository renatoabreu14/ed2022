#include <stdio.h>
#include <stdlib.h>

int qtdchr(char str[21], char chr){
    int i = 0;
    int qtd = 0;
    while ((str[i] != '\n')/*||(str[i] != '\0')*/){
        if (str[i] == chr){
            qtd++;
        }
        i++;
    }
    return qtd;
}

int main(){
    char str1[21];
    char chr;
    fflush(stdin);
    fgets(str1, 21, stdin);
    scanf("%c", &chr);
    printf("A qtd de %c em str1 é: %i", chr, qtdchr(str1, chr));
}