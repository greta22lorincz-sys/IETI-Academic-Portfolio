/*
 * Project: Dual-Minimum Removal Utility (Dynamic Arrays)
 * File: dual_minimum_removal.c
 * Aim: This program dynamically allocates an integer array, identifies the two 
 * smallest values, removes all occurrences of them, and prints the updated array.
 */

#include <stdio.h>
#include <stdlib.h>

int minimum(int *v, int n){
    int mini = v[0];
    for(int i = 0; i < n; i++)
        if(v[i] < mini)
            mini = v[i];
    return mini;
}

int remove_number(int *v, int n, int x){
    int i = 0, j = 0;
    for(i = 0; i < n; i++)
        if(v[i] != x)
            v[j++] = v[i];
    return j;
}

int main(){
    printf("Enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    if(!v){
        printf("Error: insufficient memory.");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for(int i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }

    int mini1 = minimum(v, n);
    n = remove_number(v, n, mini1);

    int mini2 = minimum(v, n);
    n = remove_number(v, n, mini2);

    printf("The array after modification is: ");
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);

    free(v);
    return 0;
}