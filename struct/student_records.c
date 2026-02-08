/*
 * Project: Student Records Manager
 * File: students.c
 * Description:
 *   This program reads information about several students, filters those
 *   from the year 2013 belonging to a specific section, and sorts students
 *   from a chosen section by their average grade.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char lastName[50];
    char firstName[50];
    int year;
    char section[30];
    float average;
} PERSON;

void readPeople(PERSON *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for person %d:\n", i + 1);

        printf("Last name = ");
        scanf("%s", v[i].lastName);

        printf("First name = ");
        scanf("%s", v[i].firstName);

        printf("Section = ");
        scanf("%s", v[i].section);

        printf("Year = ");
        scanf("%d", &v[i].year);

        printf("Average = ");
        scanf("%f", &v[i].average);
    }
}

int main(void) {
    int n;
    printf("Number of people = ");
    scanf("%d", &n);

    PERSON *v = malloc(n * sizeof(PERSON));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }

    // a) Read data
    readPeople(v, n);

    // b) Display people from year 2013 belonging to a given section
    char section[30];
    printf("\nEnter a section to filter (year 2013): ");
    scanf("%s", section);

    printf("\nPeople from year 2013 in section %s:\n", section);
    for (int i = 0; i < n; i++)
        if (v[i].year == 2013 && strcmp(v[i].section, section) == 0)
            printf("%s %s\n", v[i].lastName, v[i].firstName);

    // c) Sort by average for a given section
    printf("\nEnter a section to sort by average: ");
    scanf("%s", section);

    PERSON filtered[n];
    int count = 0;

    for (int i = 0; i < n; i++)
        if (strcmp(v[i].section, section) == 0)
            filtered[count++] = v[i];

    // Sort ascending by average
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < count - 1; i++) {
            if (filtered[i].average > filtered[i + 1].average) {
                PERSON aux = filtered[i];
                filtered[i] = filtered[i + 1];
                filtered[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);

    printf("\nPeople from section %s sorted by average (ascending):\n", section);
    for (int i = 0; i < count; i++)
        printf("%d. %s %s — Average: %.2f\n",
               i + 1,
               filtered[i].firstName,
               filtered[i].lastName,
               filtered[i].average);

    free(v);
    return 0;
}
