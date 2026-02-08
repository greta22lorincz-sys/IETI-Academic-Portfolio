/*
 * Project: Set Intersection Calculator (Dynamic Memory)
 * File: set_intersection.c
 * Aim: This program dynamically allocates two integer sets (A and B) and computes 
 * their intersection, displaying all elements common to both sets.
 */

#include <stdlib.h>
#include <stdio.h>

int maximum(int a, int b){
    if(a > b) return a;
    return b;
}

int exists(int *v, int n, int x){
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

    int maxi = maximum(na, nb);
    int *a = malloc(na * sizeof(int));
    int *b = malloc(nb * sizeof(int));
    int *inters = malloc(maxi * sizeof(int));

    if(!a || !b || !inters){
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
        if(exists(b, nb, a[i]))
            inters[k++] = a[i];

    printf("The intersection of the two sets is: ");
    for(int i = 0; i < k; i++)
        printf("%d ", inters[i]);

    free(a);
    free(b);
    free(inters);

    return 0;
}