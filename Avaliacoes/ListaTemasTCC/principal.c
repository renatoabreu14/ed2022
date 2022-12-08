#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 80
#define TAM_DESC 400

struct Informacao{
    char nome[TAM_NOME];
    char descricao[TAM_DESC];
};

struct Elemento{
    struct Informacao info;
    struct Elemento *ant;
    struct Elemento *prox;
};

struct Temas {
    struct Elemento *prim;
};

void criarLista(struct Temas *pLista){
    pLista->prim = NULL;
}

int estaVazia(struct Temas *pLista){
    return (pLista->prim == NULL);
}

void inserirListaVazia(struct Temas *pLista, struct Elemento *novo){
    novo->ant = NULL;
    novo->prox = NULL;
    pLista->prim = novo;
}

void inserirInicio(struct Temas *pLista, struct Informacao info){
    struct Elemento *novo;
    novo = (struct Elemento *) malloc(sizeof(struct Elemento));
    strcpy(novo->info.nome, info.nome);
    strcpy(novo->info.descricao, info.descricao);

    if (estaVazia(pLista)){
        inserirListaVazia(pLista, novo);
    }else{
        novo->ant = NULL;
        novo->prox = pLista->prim;
        pLista->prim->ant = novo;
        pLista->prim = novo;
    }
}

void mostrarLista(struct Temas *pLista){
    struct Elemento *p;
    for(p = pLista->prim; p != NULL; p = p->prox){
        printf("%s\n%s\n\n", p->info.nome, p->info.descricao);
    }
    printf("\n");
}


int main(){
    struct Temas minhaLista;

    criarLista(&minhaLista);

    int opcao;
    struct Informacao info;
    do{
        printf("1 - Inserir tema\n");
        printf("2 - \n");
        printf("3 - \n");
        printf("4 - \n");
        printf("5 - Exibir temas\n");
        printf("6 - Sair\n");
        printf("Escolha uma opcão:");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:{
                printf("Informe o nome do tema:");
                fflush(stdin);
                fgets(info.nome, TAM_NOME, stdin);

                printf("Informe a descricão do tema:");
                fflush(stdin);
                fgets(info.descricao, TAM_DESC, stdin);

                inserirInicio(&minhaLista, info);
                break;
            }
            case 5:{
                mostrarLista(&minhaLista);
                break;
            }
            case 6:{
                break;
            }
            default:{
                printf("Opcão inválida!");
                break;
            }
        }
    } while (opcao != 6);
}
