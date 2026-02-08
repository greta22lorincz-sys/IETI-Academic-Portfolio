/*
 * Project: Token Classifier (IETI Lab 6)
 * File: token_classifier.c
 * Aim: This program reads input characters and classifies consecutive alphanumeric 
 * sequences as either numeric constants or valid programming identifiers.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define L   50

int is_number(char *s) {
    for (int i = 0; s[i]; i++)
        if (!isdigit(s[i]))
            return 0;
    return 1;
}

int is_identifier(char *s) {
    if (!isalpha(s[0]))
        return 0;
    for (int i = 1; s[i]; i++)
        if (!isalnum(s[i]))
            return 0;
    return 1;
}

int main(void) {
    char numbers[MAX][L];
    char id[MAX][L];
    int num_n = 0, num_id = 0;

    char word[L];
    int k = 0;
    int c;

    printf("enter characters: "); 
    while ((c = getchar()) != EOF) {
        if (isalnum(c)) {
            word[k++] = c;
        } else {
            if (k > 0) {
                word[k] = '\0';

                if (is_number(word))
                    strcpy(numbers[num_n++], word);
                else if (is_identifier(word))
                    strcpy(id[num_id++], word);

                k = 0;
            }
        }
    }

    if (k > 0) {
        word[k] = '\0';
        if (is_number(word))
            strcpy(numbers[num_n++], word);
        else if (is_identifier(word))
            strcpy(id[num_id++], word);
    }

    printf("\nNumbers found:\n");
    for (int i = 0; i < num_n; i++)
        printf("%s ", numbers[i]);

    printf("\nIdentifiers found:\n");
    for (int i = 0; i < num_id; i++)
        printf("%s ", id[i]);

    return 0;
}