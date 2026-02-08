/*
 * Project: Set Difference Calculator (A−B and B−A)
 * File: set_difference.c
 * Description:
 *   This program reads two sets A and B and computes:
 *     - A − B (elements in A that are not in B)
 *     - B − A (elements in B that are not in A)
 */

#include <stdio.h>
#include <stdlib.h>

int exists(int *v, int n, int x) {
    for (int i = 0; i < n; i++)
        if (v[i] == x)
            return 1;
    return 0;
}

int main() {
    int na, nb;

    printf("Enter the number of elements in set A: ");
    scanf("%d", &na);

    printf("Enter the number of elements in set B: ");
    scanf("%d", &nb);

    int *a = malloc(na * sizeof(int));
    int *b = malloc(nb * sizeof(int));
    int *diffAB = malloc(na * sizeof(int)); // A - B
    int *diffBA = malloc(nb * sizeof(int)); // B - A

    if (!a || !b || !diffAB || !diffBA) {
        printf("Error: insufficient memory.\n");
        return 1;
    }

    printf("Enter the elements of set A:\n");
    for (int i = 0; i < na; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &a[i]);
    }

    printf("Enter the elements of set B:\n");
    for (int i = 0; i < nb; i++) {
        printf("B[%d] = ", i);
        scanf("%d", &b[i]);
    }

    // A - B
    int k = 0;
    for (int i = 0; i < na; i++)
        if (!exists(b, nb, a[i]))
            diffAB[k++] = a[i];

    printf("Difference A - B: ");
    for (int i = 0; i < k; i++)
        printf("%d ", diffAB[i]);
    printf("\n");

    // B - A
    int j = 0;
    for (int i = 0; i < nb; i++)
        if (!exists(a, na, b[i]))
            diffBA[j++] = b[i];

    printf("Difference B - A: ");
    for (int i = 0; i < j; i++)
        printf("%d ", diffBA[i]);
    printf("\n");

    free(a);
    free(b);
    free(diffAB);
    free(diffBA);

    return 0;
}