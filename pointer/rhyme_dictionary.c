/*
 * Project: Dictionary Rhyme Finder 
 * File: dictionary.c
 * Description:
 *   This program manages a dynamic dictionary of words, allowing the user
 *   to add new entries and find rhyming words based on the last k letters.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allocate_matrix(int n, int m) {
    char **a = malloc(n * sizeof(char*));
    if (!a) {
        printf("Error: insufficient memory.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        a[i] = malloc(m * sizeof(char));
        if (!a[i]) {
            printf("Error: insufficient memory.\n");
            exit(1);
        }
    }
    return a;
}

void free_matrix(char **a, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

void read_matrix(char **a, int n, int m) {
    printf("Enter the dictionary words:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%s", a[i]);
    }
}

int word_exists(char **a, int n, char *word) {
    for (int i = 0; i < n; i++)
        if (strcmp(a[i], word) == 0)
            return 1;
    return 0;
}

char** add_word(char **a, int *n, int m, char *word) {
    if (word_exists(a, *n, word))
        return a;

    char **temp = realloc(a, (*n + 1) * sizeof(char*));
    if (!temp) {
        printf("Error: memory reallocation failed.\n");
        free_matrix(a, *n);
        exit(1);
    }
    a = temp;

    a[*n] = malloc(m * sizeof(char));
    if (!a[*n]) {
        printf("Error: insufficient memory.\n");
        exit(1);
    }

    strcpy(a[*n], word);
    (*n)++;

    return a;
}

char* find_rhyme(char **a, int n, char *word, int k) {
    for (int i = 0; i < n; i++) {
        int len1 = strlen(a[i]);
        int len2 = strlen(word);

        if (len1 < k || len2 < k)
            continue;

        int ok = 1;
        for (int j = 0; j < k; j++) {
            if (a[i][len1 - 1 - j] != word[len2 - 1 - j]) {
                ok = 0;
                break;
            }
        }

        if (ok)
            return a[i];
    }
    return NULL;
}

int main() {
    int n, m;

    printf("Enter the number of words in the dictionary: ");
    scanf("%d", &n);

    printf("Enter the maximum number of letters in a word: ");
    scanf("%d", &m);

    char **a = allocate_matrix(n, m);
    read_matrix(a, n, m);

    // Add new words
    char answer[10];
    printf("Do you want to add a word? (YES/NO): ");
    scanf("%s", answer);

    while (strcmp(answer, "YES") == 0) {
        char word[50];
        printf("Enter the word to add: ");
        scanf("%s", word);

        a = add_word(a, &n, m, word);

        printf("Do you want to add another word? (YES/NO): ");
        scanf("%s", answer);
    }

    // Find rhyme
    char word[50];
    printf("Enter the word you want to find a rhyme for: ");
    scanf("%s", word);

    char *rhyme = find_rhyme(a, n, word, 2);

    if (rhyme) {
        printf("The rhyme pair for %s is: %s\n", word, rhyme);
    } else {
        printf("No rhyme found. Do you want to add this word to the dictionary? (YES/NO): ");
        scanf("%s", answer);

        if (strcmp(answer, "YES") == 0)
            a = add_word(a, &n, m, word);
    }

    free_matrix(a, n);
    return 0;
}