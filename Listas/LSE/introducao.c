#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *prox;
};

struct Lista{
    struct Nodo *prim;
};

void criarLista(struct Lista *pLista){
    pLista->prim = NULL;
}

int estaVazia(struct Lista *pLista){
    return (pLista->prim == NULL);
}

void inserirInicio(struct Lista *pLista, int valor){
    struct Nodo *novo;
    novo = (struct Nodo*) malloc(sizeof(struct Nodo));
    novo->info = valor;
    novo->prox = pLista->prim;
    pLista->prim = novo;
}

void mostrarLista(struct Lista *pLista){
    struct Nodo *p;
    for (p = pLista->prim; p != NULL; p = p->prox){
        printf("%d\t", p->info);
    }
    printf("\n");
}

void removerInicio(struct Lista *pLista){
    struct Nodo *aux = pLista->prim;
    pLista->prim = pLista->prim->prox;
    free(aux);
}

void inserirOrdenado(struct Lista *pLista, int valor){
    struct Nodo *novo;
    novo = (struct Nodo*) malloc(sizeof(struct Nodo));
    novo->info = valor;

    struct Nodo *anterior, *atual;

    anterior = NULL;
    atual = pLista->prim;

    while ((atual != NULL) && (atual->info < valor)){
        anterior = atual;
        atual = atual->prox;
    }
    novo->prox = atual;
    if (anterior == NULL){
        pLista->prim = novo;
    }else{
        anterior->prox = novo;
    }
}

int main(){
    int valor, opcao;
    struct Lista minhaLista;
    criarLista(&minhaLista);

    do{
        printf("1 - Inserir elemento no início\n");
        printf("2 - Inserir elemento em ordem (só se a lista estiver ordenada)\n");
        printf("3 - Remover elemento no início\n");
        printf("4 - Remover elemento\n");
        printf("5 - Mostrar a lista\n");
        printf("6 - Sair\n");
        printf("Informe a opcao: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:{
                printf("Informe um número inteiro:");
                scanf("%d", &valor);
                inserirInicio(&minhaLista, valor);
                break;
            }
            case 2:{
                printf("Informe um número inteiro:");
                scanf("%d", &valor);
                inserirOrdenado(&minhaLista, valor);
                break;
            }
            case 3:{
                removerInicio(&minhaLista);
                break;
            }
            case 5:{
                if (estaVazia(&minhaLista)){
                    printf("Lista vazia");
                }else{
                    mostrarLista(&minhaLista);
                }
                break;
            }
            default:{
                printf("Opcão inválida!");
                break;
            }
        }

    }while(opcao != 6);
}