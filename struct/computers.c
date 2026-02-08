/*
 * Project: Computer Inventory Manager
 * File: computers.c
 * Description:
 *   This program reads information about several computers, sorts them
 *   in descending order by manufacturing year, and then displays those
 *   that meet specific hardware requirements.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char processor[30];
    int hard_disk;
    int ram;
    int year;
} COMPUTER;

void readComputers(COMPUTER *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nComputer %d:\n", i + 1);

        printf("Processor = ");
        scanf("%s", v[i].processor);

        printf("Hard disk (GB) = ");
        scanf("%d", &v[i].hard_disk);

        printf("RAM (GB) = ");
        scanf("%d", &v[i].ram);

        printf("Year = ");
        scanf("%d", &v[i].year);
    }
}

void displayComputers(COMPUTER *v, int n) {
    printf("\nComputers (after sorting):\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Processor: %s, Hard disk: %d GB, RAM: %d GB, Year: %d\n",
               i + 1, v[i].processor, v[i].hard_disk, v[i].ram, v[i].year);
    }
}

int main(void) {
    int n;

    printf("Number of computers: ");
    scanf("%d", &n);

    COMPUTER *v = malloc(n * sizeof(COMPUTER));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }


    readComputers(v, n);

    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].year < v[i + 1].year) {
                COMPUTER aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);

    displayComputers(v, n);

   
    printf("\nComputers in ascending order by year with RAM > 1 GB and HDD >= 256 GB:\n");
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].hard_disk >= 256 && v[i].ram > 1) {
            printf("Processor: %s, Hard disk: %d GB, RAM: %d GB, Year: %d\n",
                   v[i].processor, v[i].hard_disk, v[i].ram, v[i].year);
        }
    }

    free(v);
    return 0;
}
