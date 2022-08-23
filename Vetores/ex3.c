#include <stdio.h>
#define TAMVETOR 4
int main(){
    int vetor[TAMVETOR];
    int i;
    for (i = 0; i < TAMVETOR; i++){
        printf("Informe a %d posicao: ", i+1);
        scanf("%d", &vetor[i]);
    }

    int contpar = 0;
    for (i = 0; i < TAMVETOR; i++){
        if ((vetor[i] % 2) == 0){
            contpar++;
            printf("%d, ", vetor[i]);
        }
    }
    printf("\nForam encontrados %d numeros pares\n", contpar);
    return 0;
}