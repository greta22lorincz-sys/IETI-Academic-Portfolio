/*
 * Project: Book Database Manager
 * File: books.c
 * Description:
 *   This program reads information about several books, displays those
 *   published between 2004–2009, and sorts them in ascending order by year.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char author[50];
    char title[50];
    int year;
    char publisher[30];
} BOOK;

void readBooks(BOOK *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);

        printf("Author = ");
        scanf("%s", v[i].author);

        printf("Title = ");
        scanf("%s", v[i].title);

        printf("Publisher = ");
        scanf("%s", v[i].publisher);

        printf("Year of publication = ");
        scanf("%d", &v[i].year);
    }
}

int main(void) {
    int n;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    BOOK *v = malloc(n * sizeof(BOOK));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }

   
    readBooks(v, n);

    
    BOOK filtered[n];
    int count = 0;

    printf("\nBooks published between 2004 and 2009:\n");
    for (int i = 0; i < n; i++) {
        if (v[i].year >= 2004 && v[i].year <= 2009) {
            printf("%s\n", v[i].title);
            filtered[count++] = v[i];
        }
    }

    
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < count - 1; i++) {
            if (filtered[i].year > filtered[i + 1].year) {
                BOOK aux = filtered[i];
                filtered[i] = filtered[i + 1];
                filtered[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);

    printf("\nBooks (2004–2009) sorted by year:\n");
    for (int i = 0; i < count; i++)
        printf("%s (%d)\n", filtered[i].title, filtered[i].year);

    free(v);
    return 0;
}
