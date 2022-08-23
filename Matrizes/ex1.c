#include <stdio.h>

int main(){
    int mat [5][5];
    int l, c;

    for (l = 0; l < 5; l++){
        for (c = 0; c < 5; c++){
            printf("Informe o elemento %d, %d: ", l, c);
            scanf("%d", &mat[l][c]);
        }
    }

    int maior = 0;
    int lmaior, cmaior;

    for (l = 0; l < 5; l++) {
        for (c = 0; c < 5; c++) {
            if (mat[l][c] > maior){
                maior = mat[l][c];
                lmaior = l;
                cmaior = c;
            }
        }
    }
    printf("\nA posicao do maior elemento e: %d, %d\n", lmaior, cmaior);

    return 0;
}