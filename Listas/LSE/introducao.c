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

int main(){
    int valor, opcao;
    struct Lista minhaLista;
    criarLista(&minhaLista);
    struct Lista minhaLista2;
    criarLista(&minhaLista2);

    do{
        printf("0 - Inserir elemento no início da segunda lista\n");
        printf("1 - Inserir elemento no início\n");
        printf("2 - Inserir elemento em ordem (só se a lista estiver ordenada)\n");
        printf("3 - Remover elemento no início\n");
        printf("4 - Remover elemento por valor\n");
        printf("5 - Remover elemento por posicão\n");
        printf("6 - Mostrar a lista 1\n");
        printf("7 - Mostrar a lista 2\n");
        printf("8 - Mostrar posicão do elemento\n");
        printf("9 - Sair\n");
        printf("Informe a opcao: \n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:{
                printf("Informe um número inteiro:");
                scanf("%d", &valor);
                inserirInicio(&minhaLista2, valor);
                break;
                break;
            }
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
            case 4:{
                printf("Informe um número inteiro:");
                scanf("%d", &valor);
                if (!removerPorValor(&minhaLista, valor)){
                    printf("Valor não encontrado!\n");
                }
                break;
            }
            case 5:{
                printf("Informe posicão que deseja excluir:");
                scanf("%d", &valor);
                if (!removerPorPosicao(&minhaLista, valor)){
                    printf("Posicão não encontrada!\n");
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
                printf("Informe um número inteiro:");
                scanf("%d", &valor);
                int posicao = posicaoDoElemento(&minhaLista, valor);
                if (posicao == -1){
                    printf("Elemento não encontrado!\n");
                }else{
                    printf("O elemento foi encontrado na posicao: %d\n", posicao);
                }
                break;
            }
            case 9:{
                break;
            }
            default:{
                printf("Opcão inválida!\n");
                break;
            }
        }

    }while(opcao != 9);
}