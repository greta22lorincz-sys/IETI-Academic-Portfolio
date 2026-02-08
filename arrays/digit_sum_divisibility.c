/*
 * Project: Sum of Digits Divisibility Analysis (IETI Lab 6)
 * File: digit_sum_divisibility.c
 * Aim: This program identifies elements in a dynamically allocated array 
 * where the sum of their digits is divisible by a user-specified value.
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
    for(int i = 0; i < n; i++)
      {
          printf("v[%d]= ", i); 
          scanf("%d", &v[i]); 
          getchar(); 
      }
}

int sum_digits(int n){
    if(n == 0) return 0; 
    if(n < 0) n = -n; 
    int s = 0; 
    while(n){
        s += n % 10; 
        n /= 10; 
    }
    return s; 
}

void free_vector(int *v){
    free(v); 
}

int main() {
    printf("Enter the number of elements: "); 
    int n; 
    scanf("%d", &n); 
    
    int *v = allocate_vector(n); 
    read_vector(v, n); 
    
    printf("Enter the divisor value: "); 
    int val; 
    scanf("%d", &val); 
    
    printf("Elements where the sum of digits is divisible by %d: ", val); 
    for(int i = 0; i < n; i++){
        if(sum_digits(v[i]) % val == 0)
            printf("%d ", v[i]);
    }
    printf("\n");

    free_vector(v); 
    return 0; 
}