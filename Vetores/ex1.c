#include <stdio.h>

int main(){
    int vetor[10];
    int i;
    for (i = 0; i < 10; i++){
        printf("Informe a %d posicao: ", i+1);
        scanf("%d", &vetor[i]);
    }

    for (i = 0; i < 10; i++){
        if (vetor[i] < 0){
            vetor[i] = 0;
        }
        printf("Posicao %d: %d\n", i, vetor[i]);
    }


    return 0;
}