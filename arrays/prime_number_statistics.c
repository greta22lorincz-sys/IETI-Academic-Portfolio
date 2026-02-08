/* 
 * Project: Prime Number Analysis & Average Calculations (IETI Lab 6)
 * File: prime_statistics.c
 * Aim: This program identifies prime numbers within a dynamically allocated 
 * array and calculates the arithmetic mean for both prime numbers and 
 * even numbers separately.
 */

#include <stdio.h>
#include <stdlib.h>

int is_prime(int n)
{
    if(n < 2) return 0; 
    if(n == 2 || n == 3) return 1; 
    if(n % 2 == 0 || n % 3 == 0) return 0; 
    for(int d = 5; d * d <= n; d += 6)
      if(n % d == 0 || n % (d + 2) == 0)
         return 0; 
    return 1; 
}

void read_array(int *v, int n)
{
    for(int i = 0; i < n; i++)
       {
           printf("v[%d]= ", i); 
           scanf("%d", &v[i]); 
       }
}

int main(void)
{
    printf("Enter the number of elements in the array: "); 
    int n; 
    scanf("%d", &n); 
    
    int *v = malloc(n * sizeof(int)); 
    if(!v){
        printf("Error: Insufficient memory\n"); 
        return 1; 
    }
    
    printf("Enter the values for the array: \n"); 
    read_array(v, n); 
    
    float prime_avg = 0, even_avg = 0; 
    int even_sum = 0, even_count = 0; 
    int prime_sum = 0, prime_count = 0; 
    
    for(int i = 0; i < n; i++){
        if(v[i] % 2 == 0){
            even_count++; 
            even_sum += v[i]; 
        }
        if(is_prime(v[i])){
            prime_sum += v[i]; 
            prime_count++; 
        }
    }
         
    if(prime_count > 0)
        prime_avg = (float)prime_sum / prime_count; 
    
    if(even_count > 0)
        even_avg = (float)even_sum / even_count; 
    
    printf("Arithmetic mean of prime numbers: %.2f\n", prime_avg); 
    printf("Arithmetic mean of even numbers: %.2f\n", even_avg); 
    
    free(v); 
    return 0; 
}