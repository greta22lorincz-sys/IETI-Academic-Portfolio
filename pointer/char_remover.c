/*
 * Project: Character Stripper
 * File: char_remover.c
 * Aim: This program removes all occurrences of a specific user-defined 
 * character from a dynamically allocated string.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void remove_characters(char *s, char x) {
    char *p = s; 
    char *q = s; 
    
    while (*p) {
        if (*p != x) {
            *(q++) = *p; 
        }
        p++; 
    }
    *q = '\0';
}

int main() {
    printf("Enter the maximum number of characters: "); 
    int n; 
    if (scanf("%d", &n) != 1) return 1;
    getchar(); 
    
    char *str = malloc(n * sizeof(char)); 
    if (!str) {
        printf("Error: Insufficient memory\n"); 
        return 1; 
    }
   
    printf("Enter the text: ");
    fgets(str, n, stdin); 
    str[strcspn(str, "\n")] = '\0'; 

    printf("Enter the character you wish to delete: "); 
    char x = getchar(); 
 
    remove_characters(str, x); 

    printf("Text after removing '%c': %s\n", x, str); 
    
    free(str); 
    return 0;
}