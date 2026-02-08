/* 
 * Project: Minimum Pairwise Sum Analysis (IETI Lab 6)
 * File: min_pairwise_sum.c
 * Aim: This program computes the sum of the minimum values between 
 * corresponding pairs of elements from two different vectors.
 */

#include <stdio.h>
#include <stdlib.h>

int* allocate_vector(int n){
    int *v = malloc(n * sizeof(int)); 
    if(!v){
        printf("Error: Insufficient memory.\n"); 
        exit(1); 
    }
    return v; 
}

void read_vector(int *v, int n){
    printf("Enter the elements of the vector: \n"); 
    for(int i = 0; i < n; i++){
        printf("v[%d]= ", i); 
        scanf("%d", &v[i]); 
    }
}

int get_min(int a, int b){
    if(a < b) return a; 
    return b; 
}

void calculate_min_sum(int *a, int *b, int n){
    int result = 0; 
    for(int i = 0; i < n; i++)
      result += get_min(a[i], b[i]); 
      
    printf("The value of the expression is: %d\n", result); 
}

void free_vector(int *v){
    free(v); 
}

int main() {
    int n; 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
    
    int *a = allocate_vector(n); 
    int *b = allocate_vector(n); 
    
    printf("For the first vector: \n");
    read_vector(a, n); 
    printf("For the second vector: \n");
    read_vector(b, n); 
    
    calculate_min_sum(a, b, n); 
    
    free_vector(a); 
    free_vector(b); 
    
    return 0; 
}