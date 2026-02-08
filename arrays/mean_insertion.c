/* 
 * Project: Arithmetic Mean Vector Extension (IETI Lab 6)
 * File: mean_insertion.c
 * Aim: This program calculates the arithmetic mean of a dynamically 
 * allocated integer vector and inserts that mean into a new float vector.
 */

#include <stdio.h>
#include <stdlib.h>

int* allocate_vector(int n){
    int *v = malloc(n * sizeof(int)); 
    if(!v){
        printf("Insufficient memory.\n"); 
        exit(1); 
    }
    return v; 
}

void read_vector(int *v, int n){
    printf("Enter the vector elements: \n"); 
    for(int i = 0; i < n; i++)
      {
          printf("v[%d] = ", i); 
          scanf("%d", &v[i]); 
      }
}

float arithmetic_mean(int *v, int n){
    int sum = 0; 
    for(int i = 0; i < n; i++)
      sum += v[i]; 
      
    return (float)sum / n; 
}

int main() {
     int n; 
     printf("Enter the number of elements: "); 
     scanf("%d", &n); 
     
     int *v = allocate_vector(n); 
     read_vector(v, n); 
     
     float *v_extended = malloc((n + 1) * sizeof(float)); 
     if(!v_extended)
     {
         printf("Insufficient memory.\n");
         return 1;
     }

     for(int i = 0; i < n; i++)
        v_extended[i] = (float)v[i];

     v_extended[n] = arithmetic_mean(v, n);

     printf("The new vector is: ");
     for(int i = 0; i <= n; i++)
        printf("%.2f ", v_extended[i]);
     printf("\n");
     
     free(v);
     free(v_extended);
     return 0; 
}