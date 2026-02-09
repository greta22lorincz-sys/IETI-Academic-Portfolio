/*
 * Project: Merging and Sorting Student Lists
 * File: merged_lists.c
 * Description:
 *   This program reads two lists of students, sorts each list by grade
 *   in ascending order, merges them into a third list, and sorts the
 *   final list again by grade.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[30];
    float grade;
} LIST;

void readList(LIST *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter data for element %d:\n", i + 1);

        printf("ID: ");
        scanf("%d", &v[i].id);

        printf("Name: ");
        scanf("%s", v[i].name);

        printf("Grade: ");
        scanf("%f", &v[i].grade);
    }
}

void sortAscending(LIST *v, int n) {
    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].grade > v[i + 1].grade) {
                LIST aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);
}

int main(void) {
    LIST l1[20], l2[30], l3[50];

    int n1, n2;
    printf("Enter number of elements in l1 (max 20): ");
    scanf("%d", &n1);

    printf("Enter number of elements in l2 (max 30): ");
    scanf("%d", &n2);

    printf("\nReading l1:\n");
    readList(l1, n1);

    printf("\nReading l2:\n");
    readList(l2, n2);

    sortAscending(l1, n1);
    sortAscending(l2, n2);

    int k = 0;
    for (int i = 0; i < n1; i++)
        l3[k++] = l1[i];

    for (int i = 0; i < n2; i++)
        l3[k++] = l2[i];

 
    sortAscending(l3, k);

    printf("\nMerged list sorted ascending by grade:\n");
    for (int i = 0; i < k; i++)
        printf("%d. %s with grade %.2f\n",
               l3[i].id, l3[i].name, l3[i].grade);

    return 0;
}
