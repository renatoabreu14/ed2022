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

void inserirInicio(struct Lista *pLista, int valor) {
    struct Nodo *novo;
    novo = (struct Nodo *) malloc(sizeof(struct Nodo));
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

int removerPorValor(struct Lista *pLista, int valor){

    struct Nodo *anterior, *atual;

    anterior = NULL;
    atual = pLista->prim;

    while ((atual != NULL) && (atual->info != valor)){
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        if (anterior == NULL) {
            pLista->prim = atual->prox;
        } else {
            anterior->prox = atual->prox;
        }
        free(atual);
        return 1;
    }
    return 0;
}

int tamanhoLista(struct Lista *pLista){
    struct Nodo *p;
    int tamanho = 0;
    for (p = pLista->prim; p != NULL; p = p->prox){
        tamanho++;
    }
    return tamanho;
}

int posicaoDoElemento(struct Lista *pLista, int valor){
    struct Nodo *p;
    int posicao = 0;
    for (p = pLista->prim; p != NULL; p = p->prox){
        if (p->info == valor){
            return posicao;
        }
        posicao++;
    }
    return -1;
}

int removerPorPosicao(struct Lista *pLista, int posicao){

    struct Nodo *anterior, *atual;

    if ((posicao < 0) || (posicao > tamanhoLista(pLista)-1)){
        return 0;
    }else{
        anterior = NULL;
        atual = pLista->prim;

        int posAtual = 0;

        while ((atual != NULL) && (posAtual != posicao)){
            anterior = atual;
            atual = atual->prox;
            posAtual++;
        }

        if (atual != NULL) {
            if (anterior == NULL) {
                pLista->prim = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            return 1;
        }
        return 0;
    }
}

void inserirFim(struct Lista *pLista, int valor){
    struct Nodo *novo, *p;
    novo = (struct Nodo*) malloc(sizeof(struct Nodo));
    novo->info = valor;
    p = pLista->prim;
    if (p == NULL) {
        novo->prox = pLista->prim;
        pLista->prim = novo;
    }else {
        while (p->prox != NULL) {
            p = p->prox;
        }
        p->prox = novo;
        novo->prox = NULL;
    }
}

void unirListas(struct Lista *pLista1, struct Lista *pLista2){
    struct Nodo *p;
    p = pLista2->prim;
    if (!estaVazia(pLista2)){
        inserirFim(pLista1, p->info);
        while (p->prox != NULL){
            p = p->prox;
            inserirFim(pLista1, p->info);
        }
    }
}

int main(){
    int valor, opcao;
    struct Lista minhaLista;
    criarLista(&minhaLista);
    struct Lista minhaLista2;
    criarLista(&minhaLista2);

    do{
        printf("0 - Inserir elemento no in??cio da segunda lista\n");
        printf("1 - Inserir elemento no in??cio\n");
        printf("2 - Inserir elemento em ordem (s?? se a lista estiver ordenada)\n");
        printf("3 - Remover elemento no in??cio\n");
        printf("4 - Remover elemento por valor\n");
        printf("5 - Remover elemento por posic??o\n");
        printf("6 - Mostrar a lista 1\n");
        printf("7 - Mostrar a lista 2\n");
        printf("8 - Mostrar posic??o do elemento\n");
        printf("9 - Unir listas\n");
        printf("10 - Sair\n");
        printf("Informe a opcao: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:{
                printf("Informe um n??mero inteiro:");
                scanf("%d", &valor);
                inserirInicio(&minhaLista2, valor);
                break;
                break;
            }
            case 1:{
                printf("Informe um n??mero inteiro:");
                scanf("%d", &valor);
                inserirInicio(&minhaLista, valor);
                break;
            }
            case 2:{
                printf("Informe um n??mero inteiro:");
                scanf("%d", &valor);
                inserirOrdenado(&minhaLista, valor);
                break;
            }
            case 3:{
                removerInicio(&minhaLista);
                break;
            }
            case 4:{
                printf("Informe um n??mero inteiro:");
                scanf("%d", &valor);
                if (!removerPorValor(&minhaLista, valor)){
                    printf("Valor n??o encontrado!\n");
                }
                break;
            }
            case 5:{
                printf("Informe posic??o que deseja excluir:");
                scanf("%d", &valor);
                if (!removerPorPosicao(&minhaLista, valor)){
                    printf("Posic??o n??o encontrada!\n");
                }
                break;
            }
            case 6:{
                if (estaVazia(&minhaLista)){
                    printf("Lista vazia\n");
                }else{
                    mostrarLista(&minhaLista);
                }
                break;
            }
            case 7:{
                if (estaVazia(&minhaLista2)){
                    printf("Lista vazia\n");
                }else{
                    mostrarLista(&minhaLista2);
                }
                break;
            }
            case 8:{
                printf("Informe um n??mero inteiro:");
                scanf("%d", &valor);
                int posicao = posicaoDoElemento(&minhaLista, valor);
                if (posicao == -1){
                    printf("Elemento n??o encontrado!\n");
                }else{
                    printf("O elemento foi encontrado na posicao: %d\n", posicao);
                }
                break;
            }
            case 9:{
                unirListas(&minhaLista, &minhaLista2);
                break;
            }
            case 10:{
                break;
            }
            default:{
                printf("Opc??o inv??lida!\n");
                break;
            }
        }

    }while(opcao != 10);
}