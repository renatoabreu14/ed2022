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

void inserirOrdenado(struct Lista *pLista, int valor){
    if (estaVazia(pLista)) {
        inserirInicio(pLista, valor);
    } else {
        struct Nodo *p;
        p = pLista->prim;
        while((p != NULL) && (p->info < valor)){
            p = p->prox;
        }
        if (p == NULL){
            inserirFim(pLista, valor);
        }else if (p->ant == NULL){
            inserirInicio(pLista, valor);
        }else{
            struct Nodo *novo;
            novo = (struct Nodo *) malloc(sizeof(struct Nodo));
            novo->info = valor;

            novo->prox = p;
            novo->ant = p->ant;
            p->ant->prox = novo;
            p->ant = novo;
        }
    }
}

void removerInicio(struct Lista *pLista){
    struct Nodo *p = pLista->prim;
    pLista->prim = p->prox;
    if (pLista->prim != NULL){
        pLista->prim->ant = NULL;
    }
    free(p);
}

void removerFim(struct Lista *pLista){
    struct Nodo *p = pLista->prim;
    while (p->prox != NULL){
        p = p->prox;
    }
    if (p->ant != NULL){
        p->ant->prox = NULL;
    }else{
        pLista->prim = NULL;
    }
    free(p);
}

void removerPorValor(struct Lista *pLista, int valor){
    struct Nodo *p = pLista->prim;
    while ((p != NULL) && (p->info != valor)){
        p = p->prox;
    }
    if (p != NULL){
        if (p->ant == NULL){
            removerInicio(pLista);
        }else if (p->prox == NULL){
            removerFim(pLista);
        }else{
            p->prox->ant = p->ant;
            p->ant->prox = p->prox;
            free(p);
        }
    }else{
        printf("Valor não encontrado!\n");
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
        printf("3 - Inserir ordenado\n");
        printf("4 - Mostrar lista\n");
        printf("5 - Remover início\n");
        printf("6 - Remover fim\n");
        printf("7 - Remover por valor\n");
        printf("8 - Sair\n");
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
                printf("Informe um valor:");
                scanf("%d", &valor);
                inserirOrdenado(&minhaLista, valor);
                break;
            }
            case 4:{
                if (estaVazia(&minhaLista)){
                    printf("Lista vazia!\n");
                }else{
                    mostrarLista(&minhaLista);
                }
                break;
            }
            case 5:{
                if (estaVazia(&minhaLista)){
                    printf("Lista vazia!\n");
                }else{
                    removerInicio(&minhaLista);
                }
                break;
            }
            case 6:{
                if (estaVazia(&minhaLista)){
                    printf("Lista vazia!\n");
                }else{
                    removerFim(&minhaLista);
                }
                break;
            }
            case 7:{
                printf("Informe um valor:");
                scanf("%d", &valor);
                removerPorValor(&minhaLista, valor);
                break;
            }
            case 8:{
                break;
            }
            default:{
                printf("Opcão inválida!\n");
            }
        }
    } while (opcao != 8);
}