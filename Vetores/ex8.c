#include <stdio.h>
#define MENOR 5
#define MAIOR 10

int main(){
    int v1[MENOR], v2[MENOR];
    int vr[MAIOR];

    int i;
    for (i = 0; i < MENOR; i++){
        printf("Informe a %d posicao: ", i+1);
        scanf("%d", &v1[i]);
    }
    for (i = 0; i < MENOR; i++){
        printf("Informe a %d posicao: ", i+1);
        scanf("%d", &v2[i]);
    }

    int par = 0;
    int impar = 0;
    for (i = 0; i < MAIOR; i++){
        if ((i % 2) == 0){
            vr[i] = v1[par];
            par++;
        }else{
            vr[i] = v2[impar];
            impar++;
        }
    }
    for (i = 0; i < MAIOR; i++){
        printf("vr[%d]: %d\n", i, vr[i]);
    }
    return 0;
}