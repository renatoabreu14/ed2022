#include <stdio.h>

char situacao(float p1, float p2, float p3, int faltas, int aulas, float *media){
    float mediaF = (faltas / (float)aulas);
    *media = (p1 + p2 + p3) / 3.0;
    if (mediaF > 0.250){
        return 'F';
    }else{
        if (*media < 6){
            return 'R';
        }else{
            return 'A';
        }
    }
}

int main(){
    float p1, p2, p3, media;
    int faltas, aulas;
    scanf("%f", &p1);
    scanf("%f", &p2);
    scanf("%f", &p3);
    scanf("%i", &faltas);
    scanf("%i", &aulas);
    char sit = situacao(p1, p2, p3, faltas, aulas, &media);
    printf("%.1f\n", media);
    switch (sit) {
        case 'F': {
            printf("REPROVADO POR FALTAS\n");
            break;
        }
        case 'R': {
            printf("REPROVADO\n");
            break;
        }
        case 'A': {
            printf("APROVADO\n");
            break;
        }
    }
    return 0;
}