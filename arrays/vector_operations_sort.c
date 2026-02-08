/* 
 * Project: Array Operations & Sorting Algorithms (IETI Lab 6)
 * File: vector_operations_sort.c
 * Aim: This program demonstrates dynamic memory management in C and 
 * implementation of core algorithms: Bubble Sort, finding the minimum value, 
 * calculating conditional sums, and products of array elements.
 */

#include <stdio.h>
#include <stdlib.h>


void read_array(int *v, int n) {
    printf("Enter the elements of the vector: \n"); 
    for(int i = 0; i < n; i++) {
        printf("v[%d] = ", i); 
        scanf("%d", &v[i]); 
    }
}


void display_array(int *v, int n) {
    printf("Vector elements: "); 
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]); 
    printf("\n"); 
}


void calculate_sums(int *v, int n) {
    int even_sum = 0, odd_sum = 0; 
    for(int i = 0; i < n; i++) {
        if(v[i] % 2 == 0)
            even_sum += v[i]; 
        else 
            odd_sum += v[i]; 
    }
    printf("Sum of even elements: %d \n", even_sum); 
    printf("Sum of odd elements: %d \n", odd_sum); 
}


int find_minimum(int *v, int n) {
    int min_val = v[0]; 
    for(int i = 1; i < n; i++)
        if(v[i] < min_val)
            min_val = v[i]; 
    return min_val; 
}


int calculate_product(int *v, int n) {
    int product = 1; 
    for(int i = 0; i < n; i++)
        product *= v[i]; 
    return product; 
}


void bubble_sort_descending(int *v, int n) {
    int sorted; 
    do {
        sorted = 1;
        for(int i = 0; i < n - 1; i++) {
            if(v[i] < v[i + 1]) {
                int temp = v[i]; 
                v[i] = v[i + 1]; 
                v[i + 1] = temp; 
                sorted = 0; 
            }
        }
    } while(sorted == 0); 
}

int main(void) {
    int n;
    printf("Enter the number of elements in the vector: "); 
    if(scanf("%d", &n) != 1 || n <= 0) {
        printf("Error: Invalid size.\n");
        return 1;
    }
    
   
    int *v = (int*)malloc(n * sizeof(int)); 
    if(!v) {
        printf("Error: Insufficient memory.\n"); 
        return 1; 
    }
    
    read_array(v, n); 
    display_array(v, n); 
    calculate_sums(v, n); 
    
    printf("Minimum value in vector: %d \n", find_minimum(v, n)); 
    printf("Product of values in vector: %d\n", calculate_product(v, n)); 
    
    printf("\nSorting in descending order: \n"); 
    bubble_sort_descending(v, n); 
    display_array(v, n); 
    
    
    free(v); 
    return 0; 
}