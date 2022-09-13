#include <stdio.h>

int main(){
    int a = 25;
    int *pa = &a;
    int b = *pa + a;
    printf("%d %p %p %d %d %p\n", a, pa, &a, *pa, b, &b);
}