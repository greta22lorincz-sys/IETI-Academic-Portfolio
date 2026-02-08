/*
 * Project: Dynamic Phonebook Manager 
 * File: phonebook_manager.c
 * Description:
 *   This program manages a phone agenda using structures, allowing
 *   searching, adding new contacts, and alphabetical sorting.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char tel[20];   
} PERSON;

void read_people(PERSON *p, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for person %d\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", p[i].name);   

        printf("Phone number: ");
        scanf(" %19s", p[i].tel);      
    }
}

PERSON* add_person(PERSON *p, int *n, const char *name) {
    PERSON *temp = realloc(p, (*n + 1) * sizeof(PERSON));
    if (!temp) {
        fprintf(stderr, "Memory reallocation failed.\n");
        free(p);
        exit(EXIT_FAILURE);
    }
    p = temp;

    strcpy(p[*n].name, name);

    printf("Enter phone number: ");
    scanf(" %19s", p[*n].tel);

    (*n)++;
    return p;
}

void sort_people(PERSON *p, int n) {
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(p[i].name, p[i + 1].name) > 0) {
                PERSON aux = p[i];
                p[i] = p[i + 1];
                p[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);
}

int main(void) {
    printf("PHONE AGENDA\n");

    int n;
    printf("Enter the number of people in the agenda: ");
    scanf("%d", &n);

    PERSON *p = malloc(n * sizeof(PERSON));
    if (!p) {
        fprintf(stderr, "Insufficient memory.\n");
        return EXIT_FAILURE;
    }

    read_people(p, n);

    char name[50];
    printf("\nEnter the name of the searched person: ");
    scanf(" %[^\n]", name);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(p[i].name, name) == 0) {
            printf("Phone number: %s\n", p[i].tel);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("That person does not appear in the agenda.\n");
        printf("Do you want to add them? (YES/NO): ");

        char choice[5];
        scanf("%s", choice);

        if (strcmp(choice, "YES") == 0)
            p = add_person(p, &n, name);
        else
            printf("Person will not be added.\n");
    }

    sort_people(p, n);

    printf("\nAgenda in alphabetical order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s — %s\n", i + 1, p[i].name, p[i].tel);
    }

    free(p);
    return EXIT_SUCCESS;
}
