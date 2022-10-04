#include <stdio.h>
#include <stdlib.h>

struct Nodo{
    int info;
    struct Nodo *ant;
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

void inserirListaVazia(struct Lista *pLista, struct Nodo *novo){
    novo->ant = NULL;
    novo->prox = NULL;
    pLista->prim = novo;
}

void inserirInicio(struct Lista *pLista, int valor){
    struct Nodo *novo;
    novo = (struct Nodo *) malloc(sizeof(struct Nodo));
    novo->info = valor;

    if (estaVazia(pLista)){
        inserirListaVazia(pLista, novo);
    }else{
        novo->ant = NULL;
        novo->prox = pLista->prim;
        pLista->prim->ant = novo;
        pLista->prim = novo;
    }
}

void inserirFim(struct Lista *pLista, int valor) {
    struct Nodo *novo;
    novo = (struct Nodo *) malloc(sizeof(struct Nodo));
    novo->info = valor;

    if (estaVazia(pLista)) {
        inserirListaVazia(pLista, novo);
    } else {
        struct Nodo *p;
        p = pLista->prim;
        while (p->prox != NULL){
            p = p->prox;
        }

        novo->ant = p;
        novo->prox = NULL;
        p->prox = novo;
    }
}
void mostrarLista(struct Lista *pLista){
    struct Nodo *p;
    for(p = pLista->prim; p != NULL; p = p->prox){
        printf("%d\t", p->info);
    }
    printf("\n");
}

int main(){
    struct Lista minhaLista;

    criarLista(&minhaLista);

    int opcao, valor;
    do{
        printf("1 - Inserir no início\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Mostrar lista\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcão:");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:{
                printf("Informe um valor:");
                scanf("%d", &valor);
                inserirInicio(&minhaLista, valor);
                break;
            }
            case 2:{
                printf("Informe um valor:");
                scanf("%d", &valor);
                inserirFim(&minhaLista, valor);
                break;
            }
            case 3:{
                if (estaVazia(&minhaLista)){
                    printf("Lista vazia!\n");
                }else{
                    mostrarLista(&minhaLista);
                }
                break;
            }
            case 6:{
                break;
            }
            default:{
                printf("Opcão inválida!\n");
            }
        }
    } while (opcao != 6);
}