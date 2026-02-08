/*
 * Project: Car Owner Database
 * File: car_owners.c
 * Description:
 *   This program reads information about several people, identifies the
 *   unmarried owner of the newest DACIA, and sorts all names alphabetically.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int married;        // 0 = no, 1 = yes
    char carBrand[50];
    int year;
} PERSON;

int main() {
    int n;

    printf("Enter the number of people: ");
    scanf("%d", &n);

    PERSON *v = malloc(n * sizeof(PERSON));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }


    for (int i = 0; i < n; i++) {
        printf("\nEnter data for person %d:\n", i + 1);

        printf("Name: ");
        scanf("%s", v[i].name);

        printf("Married (0 = no, 1 = yes): ");
        scanf("%d", &v[i].married);

        printf("Car brand (uppercase): ");
        scanf("%s", v[i].carBrand);

        printf("Car manufacturing year: ");
        scanf("%d", &v[i].year);
    }

    
    int newestYear = -1;
    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].carBrand, "DACIA") == 0 && v[i].married == 0) {
            if (v[i].year > newestYear) {
                newestYear = v[i].year;
                pos = i;
            }
        }
    }

    if (pos >= 0)
        printf("\nThe unmarried owner of the newest DACIA is: %s\n", v[pos].name);
    else
        printf("\nNo unmarried DACIA owner found.\n");


    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (strcmp(v[i].name, v[i + 1].name) > 0) {
                PERSON aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);

    printf("\nPeople sorted alphabetically by name:\n");
    for (int i = 0; i < n; i++)
        printf("%s ", v[i].name);

    printf("\n");

    free(v);
    return 0;
}
