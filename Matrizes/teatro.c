#include <stdio.h>
int consulta(){
    printf("Consulta");
}
int main(){
    char menu[] = "1- Consulta\n2- Venda\n3- Reserva\n4- Liberar\n5- Sair\n\nEscolha uma opcao:";
    int opcao;

    do{
        printf("%s", menu);
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:{
                consulta();
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