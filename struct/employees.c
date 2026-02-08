/*
 * Project: Employee Database Manager
 * File: employees.c
 * Description:
 *   This program reads information about employees, sorts them in
 *   descending order by seniority, identifies employees with the
 *   highest and lowest salaries, and displays employees with
 *   seniority under 3 years and salary above 1000.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char lastName[50];
    char firstName[50];
    float salary;
    int seniority;   
} EMP;

void readEmployees(EMP *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);

        printf("Last name: ");
        scanf("%s", v[i].lastName);

        printf("First name: ");
        scanf("%s", v[i].firstName);

        printf("Monthly salary: ");
        scanf("%f", &v[i].salary);

        printf("Seniority (years): ");
        scanf("%d", &v[i].seniority);
    }
}

int main(void) {
    int n;

    printf("Number of employees = ");
    scanf("%d", &n);

    EMP *v = malloc(n * sizeof(EMP));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }

   
    readEmployees(v, n);


    int sorted;
    do {
        sorted = 1;
        for (int i = 0; i < n - 1; i++) {
            if (v[i].seniority < v[i + 1].seniority) {
                EMP aux = v[i];
                v[i] = v[i + 1];
                v[i + 1] = aux;
                sorted = 0;
            }
        }
    } while (!sorted);

    printf("\nEmployees in descending order by seniority:\n");
    for (int i = 0; i < n; i++)
        printf("%d. %s %s\n", i + 1, v[i].lastName, v[i].firstName);

   
    float minSalary = v[0].salary;
    float maxSalary = v[0].salary;

    for (int i = 0; i < n; i++) {
        if (v[i].salary > maxSalary)
            maxSalary = v[i].salary;
        if (v[i].salary < minSalary)
            minSalary = v[i].salary;
    }

    printf("\nEmployees with the highest salary: ");
    for (int i = 0; i < n; i++)
        if (v[i].salary == maxSalary)
            printf("%s %s, ", v[i].lastName, v[i].firstName);

    printf("\nEmployees with the lowest salary: ");
    for (int i = 0; i < n; i++)
        if (v[i].salary == minSalary)
            printf("%s %s, ", v[i].lastName, v[i].firstName);

    
    printf("\n\nEmployees with seniority under 3 years and salary > 1000:\n");
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].seniority < 3 && v[i].salary > 1000)
            printf("%s %s, ", v[i].lastName, v[i].firstName);
    }

    printf("\n");

    free(v);
    return 0;
}