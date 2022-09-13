#include <stdio.h>
#include <string.h>

void inverteString(char texto[50], char invertido[50]){
    int tam = strlen(texto);
    int i = 0;
    for (i = 0; i < tam; i++){
        invertido[i] = texto[(tam-1)-i];
    }
}

int main(){
    char texto[50];
    char invertido[50];
    fflush(stdin);
    fgets(texto, 50, stdin);
    inverteString(texto, invertido);
    printf("%s\n", invertido);
    return 0;
}
