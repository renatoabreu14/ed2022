#include <stdio.h>

int main(){
    int mat[5][5];
    int l, c;

    for (l = 0; l < 5; l++){
        for (c = 0; c < 5; c++){
            if (l == c){
                mat[l][c] = 1;
            }else{
                mat[l][c] = 0;
            }
            printf("Elemento %d, %d: %d\n", l, c, mat[l][c]);
        }
    }

    return 0;
}