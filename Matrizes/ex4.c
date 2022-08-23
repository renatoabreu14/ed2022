#include <stdio.h>
#define LINHAS 3
#define COLUNAS 3

int main(){
    int mat1[LINHAS][COLUNAS], mat2[LINHAS][COLUNAS], mat3[LINHAS][COLUNAS];
    int l, c;

    for(l = 0; l < LINHAS; l++){
        for (c = 0; c < COLUNAS; c++){
            printf("Informe o elemento %d, %d da M1: ", l, c);
            scanf("%d", &mat1[l][c]);
        }
    }

    for(l = 0; l < LINHAS; l++){
        for (c = 0; c < COLUNAS; c++){
            printf("Informe o elemento %d, %d da M2: ", l, c);
            scanf("%d", &mat2[l][c]);
        }
    }

    for(l = 0; l < LINHAS; l++) {
        for (c = 0; c < COLUNAS; c++) {
            if (mat1[l][c] > mat2[l][c]){
                mat3[l][c] = mat1[l][c];
            }else{
                mat3[l][c] = mat2[l][c];
            }
            printf("M3 - Elemento %d, %d: %d\n", l, c, mat3[l][c]);
        }
    }

    for (l = 0; l < LINHAS; l++){
        printf("%d\t%d\t%d\n", mat3[l][0], mat3[l][1], mat3[l][2]);
    }
    return 0;
}