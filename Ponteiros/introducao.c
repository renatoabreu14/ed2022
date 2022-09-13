#include <stdio.h>

void incrementar(int *contador){
    *contador = *contador + 1;
    //printf("%x\n", contador);
    printf("%p\n", contador);
}

int main(){
    int contador = 0;
    incrementar(&contador);
    printf("%p\n", &contador);
}