/*
 * Project: String Property Analyzer (IETI Lab 6)
 * File: string_analyzer.c
 * Aim: This program performs various analyses on a user-provided string, 
 * including digit/letter verification, vowel counting, and string reversal.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define L 100

int is_only_digits(char *s) {
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return 0;
    return 1;
}

int is_only_letters(char *s) {
    for (int i = 0; s[i]; i++)
        if (!isalpha(s[i]))
            return 0;
    return 1;
}

int count_vowels(char *s) {
    int count = 0;
    for (int i = 0; s[i]; i++) {
        char ch = tolower(s[i]);
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            count++;
    }
    return count;
}

void reverse(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        char aux = s[i];
        s[i] = s[j];
        s[j] = aux;
        i++;
        j--;
    }
}

int main(void) {
    char s[L];
    printf("enter string: ");
    fgets(s, L, stdin);
    s[strcspn(s, "\n")] = 0; 

    if (is_only_digits(s))
        printf("the string contains only digits.\n");
    else
        printf("the string does not contain only digits.\n");

    if (is_only_letters(s))
        printf("the string contains only letters.\n");
    else
        printf("the string does not contain only letters.\n");

    printf("number of vowels: %d\n", count_vowels(s));

    reverse(s);
    printf("reversed string: %s\n", s);

    return 0;
}