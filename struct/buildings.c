/*
 * Project: Building Database Manager
 * File: buildings.c
 * Description:
 *   This program reads information about several buildings, sorts them
 *   in ascending order by construction year, then sorts them in
 *   descending order by surface area, and finally displays buildings
 *   from the last 3 years with surface area greater than 400 m².
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char type[50];
    char location[50];
    int year;
    float surface;   
} BUILDING;

void readBuildings(BUILDING *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nBuilding %d:\n", i + 1);

        printf("Type: ");
        scanf("%s", a[i].type);

        printf("Location: ");
        scanf("%s", a[i].location);

        printf("Year: ");
        scanf("%d", &a[i].year);

        printf("Surface area (m^2): ");
        scanf("%f", &a[i].surface);
    }
}

int main(void) {
    int n;

    printf("Enter the number of buildings: ");
    scanf("%d", &n);

    BUILDING *a = malloc(n * sizeof(BUILDING));
    if (!a) {
        printf("Error: insufficient memory.\n");
        return 1;
    }


    readBuildings(a, n);

    
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].year > a[i + 1].year) {
                BUILDING aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);

    printf("\nBuildings in ascending order by year:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s — Year %d\n", i + 1, a[i].type, a[i].year);

    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i].surface < a[i + 1].surface) {
                BUILDING temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                sorted = 0;
            }
        }
    } while (!sorted);

    int currentYear;
    printf("\nEnter the current year: ");
    scanf("%d", &currentYear);

    printf("\nBuildings from the last 3 years with surface > 400 m^2:\n");
    for (int i = 0; i < n; i++) {
        if (a[i].year >= currentYear - 3 && a[i].surface > 400)
            printf("%s (%d)\n", a[i].type, a[i].year);
    }

    free(a);
    return 0;
}
