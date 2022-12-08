#include <stdio.h>
#include <stdlib.h>

struct No{
    int info;
    struct No *dir;
    struct No *esq;
};

struct Arvore{
    struct No *raiz;
};

void inserirDireita(struct No *pNo, int valor);

void criarArvore(struct Arvore *pArvore){
    pArvore->raiz = NULL;
}

int estaVazia(struct Arvore *pArvore){
    return (pArvore->raiz == NULL);
}

void inserirEsquerda(struct No *pNo, int valor){
    if (pNo->esq == NULL){
        struct No *novo;
        novo = (struct No*) malloc(sizeof(struct No));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->info = valor;
        pNo->esq = novo;
    }else{
        if (valor < pNo->esq->info){
            inserirEsquerda(pNo->esq, valor);
        }else{
            inserirDireita(pNo->esq, valor);
        }
    }
}

void inserirDireita(struct No *pNo, int valor) {
    if (pNo->dir == NULL){
        struct No *novo;
        novo = (struct No*) malloc(sizeof(struct No));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->info = valor;
        pNo->dir = novo;
    }else{
        if (valor < pNo->dir->info){
            inserirEsquerda(pNo->dir, valor);
        }else{
            inserirDireita(pNo->dir, valor);
        }
    }
}

void exibirNo(struct No *pNo){
    if (pNo != NULL){
        printf("No: %d\n", pNo->info);
        exibirNo(pNo->esq);
        exibirNo(pNo->dir);
    }
}

void exibirOrdenado(struct No *pNo){
    if (pNo != NULL){
        exibirOrdenado(pNo->esq);
        printf("No: %d\n", pNo->info);
        exibirOrdenado(pNo->dir);
    }
}

int buscarValor(struct No *pNo, int valor){
    if (pNo != NULL){
        if (pNo->info == valor){
            return 1;
        }else{
            if (valor < pNo->info){
                return buscarValor(pNo->esq, valor);
            }else{
                return buscarValor(pNo->dir, valor);
            }
        }
    }
}

void inserir(struct Arvore *pArvore, int valor){
    if (estaVazia(pArvore)){
        struct No *novo;
        novo = (struct No*) malloc(sizeof(struct No));
        novo->dir = NULL;
        novo->esq = NULL;
        novo->info = valor;
        pArvore->raiz = novo;
    }else{
        if(valor < pArvore->raiz->info){
            inserirEsquerda(pArvore->raiz, valor);
        }else{
            inserirDireita(pArvore->raiz, valor);
        }
    }
}

int main(){
    struct Arvore minhaArvore;
    criarArvore(&minhaArvore);
    int opcao, valor;
    do{
        printf("1 - Inserir no na arvore\n");
        printf("2 - Remover no da arvore\n");
        printf("3 - Exibir nos da arvore\n");
        printf("4 - Exibir nos da arvore (ordenado)\n");
        printf("5 - Buscar valor na arvore (ordenado)\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcao:");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:{
                printf("Informe o valor:");
                scanf("%d", &valor);
                inserir(&minhaArvore, valor);
                break;
            }
            case 2:{
                printf("Informe o valor:");
                scanf("%d", &valor);
                //remover(&minhaArvore.raiz, valor);
                break;
            }
            case 3:{
                exibirNo(minhaArvore.raiz);
                break;
            }
            case 4:{
                exibirOrdenado(minhaArvore.raiz);
                break;
            }
            case 5:{
                printf("Informe o valor:");
                scanf("%d", &valor);
                if (buscarValor(minhaArvore.raiz, valor)){
                    printf("Encontrei!\n");
                }else{
                    printf("NÃO Encontrei!\n");
                }
                break;
            }
            case 6:{
                break;
            }
            default:{
                printf("Opcao invalida!");
            }
        }
    } while (opcao != 6);

}