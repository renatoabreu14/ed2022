#include <stdio.h>

int main(){
    /*int *A;     // Declara a variável A como ponteiro
    int N = 10; // Declara a variável N e atribui 10
    A = &N;     // Armazena o endereço de N em A
    printf("&A = %p \n", &A);   // Escreve o endereço do ponteiro A
    printf("A = %p \n", A);     // Escreve o conteúdo armazenado em A (end. de N)
    printf("*A = %i \n", *A);   // Escreve o conteúdo onde A aponta (valor de N)
    printf("N = %i \n", N);     // Escreve o valor de N
    printf("&N = %p \n", &N);   // Escreve o endereço de N*/

    char *A=0x0;
    double *C=0x0;
    printf("A = %p\n",A);
    A++;
    printf("A = %p\n",A);
    printf("C = %p\n",C);
    C++;
    printf("C = %p\n",C);
// Ponteiro A do tipo char (aponta para 0x00)
// Ponteiro C do tipo double (aponta para 0x00)
// Mostra o endereço antes do incremento de A
// Mostra o endereço depois do incremento de A
// Mostra o endereço antes do incremento de C
// Mostra o endereço depois do incremento de C
}