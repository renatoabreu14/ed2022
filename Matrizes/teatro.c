#include <stdio.h>
#include <stdlib.h>
#define LINHAS 5
#define COLUNAS 11
int limpar(char teatro[LINHAS][COLUNAS]){
    int l, c;
    for (l = 0; l < LINHAS; l++){
        for (c = 0; c < COLUNAS; c++){
            teatro[l][c] = 'L';
        }
    }
}

int consulta(char teatro[LINHAS][COLUNAS]){
    system("clear");
    int l;
    for (l = 0; l < LINHAS; l++){
        printf("%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\t%c\n", teatro[l][0], teatro[l][1], teatro[l][2], teatro[l][3], teatro[l][4], 'C', teatro[l][6], teatro[l][7], teatro[l][8], teatro[l][9], teatro[l][10]);
    }
    return 0;
}

int venda(char teatro[LINHAS][COLUNAS]){
    system("clear");
    int c, l;
    printf("Informe a coluna: ");
    scanf("%d", &c);
    if (c == 5){
        printf("Corredor. Operacão cancelada!");
    }else{
        printf("Informe a linha: ");
        scanf("%d", &l);
        teatro[l][c] = 'V';
    }
    return 0;
}

int reserva(char teatro[LINHAS][COLUNAS]){
    system("clear");
    int c, l;
    printf("Informe a coluna: ");
    scanf("%d", &c);
    if (c == 5){
        printf("Corredor. Operacão cancelada!");
    }else{
        printf("Informe a linha: ");
        scanf("%d", &l);
        teatro[l][c] = 'R';
    }
    return 0;
}

int libera(char teatro[LINHAS][COLUNAS]){
    system("clear");
    int c, l;
    printf("Informe a coluna: ");
    scanf("%d", &c);
    if (c == 5){
        printf("Corredor. Operacão cancelada!");
    }else{
        printf("Informe a linha: ");
        scanf("%d", &l);
        teatro[l][c] = 'L';
    }
    return 0;
}

int main(){
    char teatro[LINHAS][COLUNAS];
    limpar(teatro);
    char menu[] = "1- Consulta\n2- Venda\n3- Reserva\n4- Libera\n5- Sair\n\nEscolha uma opcao:";
    int opcao;

    do{
        printf("%s", menu);
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:{
                consulta(teatro);
                break;
            }
            case 2:{
                venda(teatro);
                break;
            }
            case 3:{
                reserva(teatro);
                break;
            }
            case 4:{
                libera(teatro);
                break;
            }
            case 5:{
                break;
            }
            default:{
                printf("Opcao invalida!");
                break;
            }
        }
    }while(opcao != 5);
    return 0;
}