#include <stdio.h>
#include <string.h>

int main(){
    char str1[6] = {'t', 'e', 's', 't', 'e', '\0' };
    char *str2 = "teste";

    int tamanho = strlen(str1);

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("tam str1 = %d\n", tamanho);

    return 0;
}