/*
 * Project: Set Union Generator (Dynamic Memory)
 * File: set_union.c
 * Aim: This program dynamically allocates two integer sets (A and B) and computes 
 * their union, ensuring no duplicates appear in the resulting set.
 */

#include <stdlib.h>
#include <stdio.h>

int already_exists(int *v, int n, int x){
    for(int i = 0; i < n; i++)
        if(v[i] == x)
            return 1;
    return 0;
}

int main(){
    printf("Enter the number of elements in set A: ");
    int na;
    scanf("%d", &na);

    printf("Enter the number of elements in set B: ");
    int nb;
    scanf("%d", &nb);

    int *a = malloc(na * sizeof(int));
    int *b = malloc(nb * sizeof(int));
    int *uni = malloc((na + nb) * sizeof(int));

    if(!a || !b || !uni){
        printf("Error: insufficient memory.");
        return 1;
    }

    printf("Enter the elements of set A:\n");
    for(int i = 0; i < na; i++){
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the elements of set B:\n");
    for(int i = 0; i < nb; i++){
        printf("b[%d] = ", i);
        scanf("%d", &b[i]);
    }

    int k = 0;
    for(int i = 0; i < na; i++)
        uni[k++] = a[i];

    for(int i = 0; i < nb; i++)
        if(!already_exists(uni, k, b[i]))
            uni[k++] = b[i];

    printf("The union of the two sets is: ");
    for(int i = 0; i < k; i++)
        printf("%d ", uni[i]);

    free(a);
    free(b);
    free(uni);

    return 0;
}