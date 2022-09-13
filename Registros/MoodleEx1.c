#include <stdio.h>
#include <stdlib.h>
#define TAM 2

struct Aluno{
    char matricula[10];
    char nome[30];
    float n1;
    float n2;
    float n3;
};

void lerDados(struct Aluno *aluno){
    printf("Matricula: ");
    fflush(stdin);
    fgets(aluno->matricula, 10, stdin);
    printf("Nome: ");
    fflush(stdin);
    fgets(aluno->nome, 30, stdin);
    printf("Primeira nota: ");
    scanf("%f", &aluno->n1);
    printf("Segunda nota: ");
    scanf("%f", &aluno->n2);
    printf("Terceira nota: ");
    scanf("%f", &aluno->n3);
    getchar();
}

float mediaAluno(struct Aluno aluno){
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

void mostrarAluno(struct Aluno aluno){
    float media = mediaAluno(aluno);
    printf("\nMatrícula: %s", aluno.matricula);
    printf("Nome: %s", aluno.nome);
    printf("Nota1: %.1f\n", aluno.n1);
    printf("Nota2: %.1f\n", aluno.n2);
    printf("Nota3: %.1f\n", aluno.n3);
    printf("Media: %.1f\n", media);
    if (media >= 6.0){
        printf("Aprovado\n");
    }else{
        printf("Reprovado\n");
    }
}

void maiorNotaN1(struct Aluno turma[TAM]){
    float maiorN1 = 0;
    int i, pos;
    for (i = 0; i < TAM; i++){
        if (turma[i].n1 > maiorN1){
            maiorN1 = turma[i].n1;
            pos = i;
        }
    }
    printf("O aluno com maior nota 1");
    mostrarAluno(turma[pos]);
}

void maiorMediaGeral(struct Aluno turma[TAM]){
    float maiorMedia, media = 0;
    int i, pos;
    for (i = 0; i < TAM; i++){
        media = mediaAluno(turma[i]);
        if (media > maiorMedia){
            maiorMedia = media;
            pos = i;
        }
    }
    printf("O aluno com maior media geral");
    mostrarAluno(turma[pos]);
}

void menorMediaGeral(struct Aluno turma[TAM]){
    float maiorMedia, media = 1000;
    int i, pos;
    for (i = 0; i < TAM; i++){
        media = mediaAluno(turma[i]);
        if (media < maiorMedia){
            maiorMedia = media;
            pos = i;
        }
    }
    printf("\nO aluno com menor media geral");
    mostrarAluno(turma[pos]);
}

int main(){
    struct Aluno turma[TAM];
    int i;
    for (i = 0; i < TAM; i++){
        lerDados(&turma[i]);
    }
    maiorNotaN1(turma);
    maiorMediaGeral(turma);
    menorMediaGeral(turma);
    for (i = 0; i < TAM; i++){
        mostrarAluno(turma[i]);
    }
}