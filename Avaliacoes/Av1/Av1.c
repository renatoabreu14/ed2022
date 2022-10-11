#include <stdio.h>
#include <string.h>

int main(){

    /*Questao06*/

    /*int *pti;
    int i = 10;
    pti = &i;

    printf("%p", pti);*/


    /*Questao 07*/
    /*int x, y, *p;y=0;
    p = &y;
    x = *p;
    printf("x=%d, y=%d, *p=%d\n", x, y, *p);
    x = 4;
    printf("x=%d, y=%d, *p=%d\n", x, y, *p);
    (*p)++;
    printf("x=%d, y=%d, *p=%d\n", x, y, *p);
    --x;
    printf("x=%d, y=%d, *p=%d\n", x, y, *p);
    (*p) += x;

    printf("x=%d, y=%d, *p=%d\n", x, y, *p);*/



    /*Questao08*/
    /*a*/
    /*int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p: %d\n", *p);*/

    /*b*/
    char *a, *b;
    a = "zebra";
    b = "uva";
    if (*a < *b){
        printf("%s vem antes de %s no dicionário", a, b);
    }else{
        printf("%s vem depois de %s no dicionário", a, b);
    }
}