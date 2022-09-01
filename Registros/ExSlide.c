#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

struct Endereco{
    char rua[50];
    char cidade [40];
    char cep[10];
};

struct Contato{
    char nome[50];
    int idade;
    char fone[20];
    char email[50];
    struct Endereco endereco;
};

void preencherContato(struct Contato *contato){
    printf("Nome: ");
    fflush(stdin);
    fgets(contato->nome, 50, stdin);
    printf("Idade: ");
    scanf("%d", &contato->idade);
    getchar();
    printf("Fone: ");
    fflush(stdin);
    fgets(contato->fone, 20, stdin);
    printf("Email: ");
    fflush(stdin);
    fgets(contato->email, 50, stdin);

    printf("Rua: ");
    fflush(stdin);
    fgets(contato->endereco.rua, 50, stdin);
    printf("Cidade: ");
    fflush(stdin);
    fgets(contato->endereco.cidade, 40, stdin);
    printf("CEP: ");
    fflush(stdin);
    fgets(contato->endereco.cep, 10, stdin);
}

void mostrarContato(struct Contato contato){
    printf("Nome: %s", contato.nome);
    printf("Idade: %d\n", contato.idade);
    printf("Fone: %s", contato.fone);
    printf("Email: %s", contato.email);
    printf("Endereco:\n");
    printf("Rua: %s", contato.endereco.rua);
    printf("Cidade: %s", contato.endereco.cidade);
    printf("CEP: %s", contato.endereco.cep);
}

int main(){
    struct Contato agenda[TAM];
    int i;

    for (i = 0; i < TAM; i++){
        preencherContato(&agenda[i]);
    }

    for (i = 0; i < TAM; i++){
        mostrarContato(agenda[i]);
    }

    system("pause");
    return 0;
}