/*
 * Project: Punctuation Frequency Analyzer (IETI Lab 6)
 * File: punctuation_counter.c
 * Aim: This program analyzes a dynamically allocated string to count 
 * the frequency of spaces, commas, and periods.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    printf("enter the maximum number of characters: "); 
    int n; 
    scanf("%d", &n); 
    getchar(); 
    
    char *str= malloc(n*sizeof(char)); 
    if(!str){
        printf("insufficient memory.\n"); 
        exit(1); 
    }
    
    printf("enter the string: "); 
    fgets(str, n, stdin); 
    
    int num_s=0, num_c=0, num_p=0; 
    char *p= str; 
    while(*p){
        switch(*p){
            case '.' :
            num_p++;
            break; 
            
            case ' ': 
            num_s++; 
            break; 
            
            case ',' :
            num_c++; 
            break; 
            
        }
        
        p++; 
    }
    
    printf("number of spaces: %d, number of commas: %d, number of periods: %d", num_s, num_c, num_p); 
    free(str); 
    return 0;
}