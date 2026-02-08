/*
 * Project: Vector Segment Overwrite (IETI Lab 6)
 * File: vector_overwrite.c
 * Description:
 *   This program overwrites a segment of vector 'a' with the contents of
 *   vector 'b', starting at index k. If needed, vector 'a' is extended.
 */

#include <stdio.h>
#include <stdlib.h>


void read_vector(int *v, int n) {
    printf("Enter the vector elements:\n");
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        if (scanf("%d", &v[i]) != 1) {
            fprintf(stderr, "Invalid input.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main(void) {
    int n, m;

    printf("n = ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid size for n.\n");
        return EXIT_FAILURE;
    }

    printf("m = ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        fprintf(stderr, "Invalid size for m.\n");
        return EXIT_FAILURE;
    }

    int *a = malloc((n + m) * sizeof(int));
    if (!a) {
        fprintf(stderr, "Insufficient memory for vector a.\n");
        return EXIT_FAILURE;
    }

   
    int *b = malloc(m * sizeof(int));
    if (!b) {
        fprintf(stderr, "Insufficient memory for vector b.\n");
        free(a);
        return EXIT_FAILURE;
    }

    printf("For vector a:\n");
    read_vector(a, n);

    printf("For vector b:\n");
    read_vector(b, m);

    printf("Insertion position k = ");
    int k;
    if (scanf("%d", &k) != 1 || k < 0) {
        fprintf(stderr, "Invalid index k.\n");
        free(a);
        free(b);
        return EXIT_FAILURE;
    }

    
    if (k > n) {
        printf("Warning: k is greater than n. Filling gap with zeros.\n");
        for (int i = n; i < k; i++)
            a[i] = 0;
    }

    
    for (int i = 0; i < m; i++) {
        a[k + i] = b[i];
    }

    
    if (k + m > n)
        n = k + m;

    printf("The resulting vector is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
    free(b);
    return EXIT_SUCCESS;
}