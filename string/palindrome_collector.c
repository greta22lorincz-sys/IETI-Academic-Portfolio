/*
 * Project: Palindrome Word Collector (IETI Lab 6)
 * File: palindrome_collector.c
 * Aim: This program identifies palindrome words from a stream of 
 * characters and stores them in a 2D array for final display.
 */
#include <stdio.h>
#include <string.h>

#define MAX 100
#define L   50

int is_palindrome(char *s) {
    int i = 0, j = strlen(s) - 1;
    while (i < j) {
        if (s[i] != s[j])
            return 0;
        i++;
        j--;
    }
    return 1;
}

int main(void) {
    char pal[MAX][L];
    int n = 0;

    char word[L];
    int k = 0;
    int c;

    printf("enter characters (CTRL+D to finish): "); 
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n') {
            word[k++] = c;
        } else {
            if (k > 0) {
                word[k] = '\0';
                if (is_palindrome(word))
                    strcpy(pal[n++], word);
                k = 0;
            }
        }
    }

    if (k > 0) {
        word[k] = '\0';
        if (is_palindrome(word))
            strcpy(pal[n++], word);
    }

    printf("Palindrome: "); 
    for (int i = 0; i < n; i++) {
        printf("%s ", pal[i]);
    }

    return 0;
}