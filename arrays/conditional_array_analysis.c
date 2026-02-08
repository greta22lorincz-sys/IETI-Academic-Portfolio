/* 
 * Project: Conditional Min/Max Search on Indexed Positions (IETI Lab 6)
 * File: indexed_array_analysis.c
 * Aim: This program performs targeted searches within a vector: finding the 
 * minimum negative value at even indices and the maximum positive value 
 * at odd indices using dynamic memory.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n; 
    printf("Enter the number of elements in the vector: "); 
    scanf("%d", &n); 
    
    int *v = malloc(n * sizeof(int)); 
    if(!v){
        printf("Error: Insufficient memory.\n"); 
        return 1; 
    }
    
    printf("Enter the elements of the array: \n"); 
    for(int i = 0; i < n; i++)
    {
        printf("v[%d] = ", i); 
        scanf("%d", &v[i]); 
    }
    
    int min_neg = 1; 
    int max_pos = -1; 
    
    for(int i = 0; i < n; i += 2) {
       if(v[i] < 0) {
          if(min_neg == 1 || v[i] < min_neg)
             min_neg = v[i]; 
       }
    }

    for(int i = 1; i < n; i += 2) {
      if(v[i] > 0) {
         if(max_pos == -1 || v[i] > max_pos)
           max_pos = v[i]; 
      }
    }
    
    if(min_neg == 1)
        printf("No negative elements found at even positions.\n");
    else 
        printf("Minimum negative element at even positions: %d \n", min_neg); 
      
    if(max_pos == -1)
        printf("No positive elements found at odd positions.\n"); 
    else 
        printf("Maximum positive element at odd positions: %d\n", max_pos); 
    
    free(v); 
    return 0; 
}