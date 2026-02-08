#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nume[50];
    char prenume[50];
    int an;
    char sectie[30];
    float media;
} PERS;

void citire(PERS *v, int n) {
    for(int i = 0; i < n; i++) {
        printf("Introduceti datele persoanei %d:\n", i+1);

        printf("Nume = ");
        scanf("%s", v[i].nume);

        printf("Prenume = ");
        scanf("%s", v[i].prenume);

        printf("Sectia = ");
        scanf("%s", v[i].sectie);

        printf("An = ");
        scanf("%d", &v[i].an);

        printf("Media = ");
        scanf("%f", &v[i].media);
    }
}

int main(void)
{
    int n;
    printf("Nr persoane = ");
    scanf("%d", &n);

    PERS *v = malloc(n * sizeof(PERS));
    if(!v){
        printf("Memorie insuficienta.\n");
        exit(1);
    }

    // a) citire
    citire(v, n);

    // b) afisare persoane din anul 2013 de la o sectie
    char sect[30];
    printf("\nIntroduceti o sectie pentru filtrare (an 2013): ");
    scanf("%s", sect);

    printf("\nPersoanele din anul 2013 de la sectia %s:\n", sect);
    for(int i = 0; i < n; i++)
        if(v[i].an == 2013 && strcmp(v[i].sectie, sect) == 0)
            printf("%s %s\n", v[i].nume, v[i].prenume);

    // c) sortare dupa medie pentru o sectie
    printf("\nIntroduceti o sectie pentru sortare dupa medie: ");
    scanf("%s", sect);

    PERS v1[n];
    int j = 0;

    for(int i = 0; i < n; i++)
        if(strcmp(v[i].sectie, sect) == 0)
            v1[j++] = v[i];

    // sortare crescatoare dupa medie
    int sortat;
    do {
        sortat = 1;
        for(int i = 0; i < j - 1; i++) {
            if(v1[i].media > v1[i+1].media) {
                PERS aux = v1[i];
                v1[i] = v1[i+1];
                v1[i+1] = aux;
                sortat = 0;
            }
        }
    } while(!sortat);

    printf("Persoanele de la sectia %s ordonate crescator dupa medie:\n", sect);
    for(int i = 0; i < j; i++)
        printf("%d. %s %s cu media %.2f\n", i+1, v1[i].nume, v1[i].prenume, v1[i].media);

    free(v);
    return 0;
}