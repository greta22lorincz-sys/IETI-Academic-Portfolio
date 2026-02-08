/* 
 * Project: Dynamic String Character Search (IETI Lab 6)
 * File: string_search.c
 * Aim: This program allocates a dynamic string, reads input from the user, 
 * and identifies the index of a specific character within that string.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* allocate_string(int n) {
    char *str = malloc(n * sizeof(char));
    if (!str) {
        printf("Insufficient memory.\n");
        exit(1);
    }
    return str;
}

int find_char(char *str, char c) {
    char *p = strchr(str, c);
    if (p == NULL) return -1;
    return (int)(p - str);
}

int main(void) {
    int n;
    printf("Enter the maximum number of characters: ");
    scanf("%d", &n);
    getchar();

    char *str = allocate_string(n);

    printf("Enter the string: ");
    fgets(str, n, stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the character to search for: ");
    char target;
    target = getchar();

    int index = find_char(str, target);
    printf("The requested index is: %d\n", index);

    free(str);
    return 0;
}