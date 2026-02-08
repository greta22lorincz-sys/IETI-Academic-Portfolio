/* 
 * Project: Matrix Transformations & Row Sum Optimization (IETI Lab 6)
 * File: matrix_transformations.c
 * Aim: This program handles 2D array operations including matrix transposition, 
 * element modification based on index positioning, and identifying the 
 * row with the minimum total sum.
 */

#include <stdio.h>

#define MAX_SIZE 10   

int matrix[MAX_SIZE][MAX_SIZE];
int n;  


void read_matrix(void) {
    printf("Enter matrix dimension (n x n): ");
    if (scanf("%d", &n) != 1 || n > MAX_SIZE) {
        printf("Invalid dimension.\n");
        return;
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
}


void display_matrix(void) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}


void modify_matrix(void) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] -= (i + j);

    display_matrix();
}


void display_transpose(void) {
    int transpose[MAX_SIZE][MAX_SIZE];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            transpose[j][i] = matrix[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", transpose[i][j]);
        printf("\n");
    }
}


void find_min_sum_row(void) {
    int min_sum = 9999, row_index = 0;

    for (int i = 0; i < n; i++) {
        int current_row_sum = 0;
        for (int j = 0; j < n; j++)
            current_row_sum += matrix[i][j];

        if (current_row_sum < min_sum) {
            min_sum = current_row_sum;
            row_index = i;
        }
    }
    printf("Row with the minimum sum is index %d (Sum: %d)\n", row_index, min_sum);
}


void calculate_total_sum(void) {
    int total_sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            total_sum += matrix[i][j];

    printf("Total sum of matrix elements: %d\n", total_sum);
}

int main(void) {
    read_matrix();
    
    printf("\nInitial Matrix:\n");
    display_matrix();

    printf("\nModified Matrix (subtracting i+j):\n");
    modify_matrix();

    printf("\nMatrix Transpose:\n");
    display_transpose();

    printf("\nFinding the row with the minimum sum:\n");
    find_min_sum_row();

    printf("\nCalculating total sum:\n");
    calculate_total_sum();

    return 0;
}