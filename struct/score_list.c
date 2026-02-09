/*
 * Project: Score List Manager
 * File: score_list.c
 * Description:
 *   This program reads a list of people with their scores, searches for a
 *   specific person, sorts the list in descending order by score, and
 *   identifies the people with the highest and lowest scores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int score;
} PERSON;

PERSON* allocate(int n) {
    PERSON *v = malloc(n * sizeof(PERSON));
    if (!v) {
        printf("Error: insufficient memory.\n");
        exit(1);
    }
    return v;
}

void readPeople(PERSON *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for person %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", v[i].name);

        printf("Score: ");
        scanf("%d", &v[i].score);
    }
}

void sortDescending(PERSON *v, int n) {
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].score < v[i + 1].score) {
                PERSON aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);
}

int main(void) {
    int n;
    printf("Enter the number of people: ");
    scanf("%d", &n);

    
    PERSON *v = allocate(n);
    readPeople(v, n);

    
    PERSON *p = v;
    char name[50];
    printf("\nEnter the name of the person to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < n; i++, p++) {
        if (strcmp(p->name, name) == 0) {
            found = 1;
            break;
        }
    }

    if (found)
        printf("The person exists in the list.\n");
    else
        printf("The person does NOT exist in the list.\n");

    
    sortDescending(v, n);

    printf("\nPeople sorted in descending order by score:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s with score %d\n", i + 1, v[i].name, v[i].score);

    
    int minScore = v[0].score, maxScore = v[0].score;
    int imin = 0, imax = 0;

    for (int i = 1; i < n; i++) {
        if (v[i].score > maxScore) {
            maxScore = v[i].score;
            imax = i;
        }
        if (v[i].score < minScore) {
            minScore = v[i].score;
            imin = i;
        }
    }

    printf("\nPerson with the lowest score: %s\n", v[imin].name);
    printf("Person with the highest score: %s\n", v[imax].name);

    return 0;
}
