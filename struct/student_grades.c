/*
 * Project: Student Grade Manager (IETI Lab 6)
 * File: student_grades.c
 * Description:
 *   This program reads a list of students, their exam grades,
 *   and computes the average grade for each student.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char lastName[30];
    char firstName[40];
    int grades[10];
    int examCount;
    float average;
} Student;

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student *v = malloc(n * sizeof(Student));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nEnter data for student %d:\n", i + 1);

        printf("Last name: ");
        scanf("%s", v[i].lastName);

        printf("First name: ");
        scanf("%s", v[i].firstName);

        printf("Number of exams (<10): ");
        scanf("%d", &v[i].examCount);

        int sum = 0;
        for (int j = 0; j < v[i].examCount; j++) {
            printf("Grade for exam [%d]: ", j + 1);
            scanf("%d", &v[i].grades[j]);
            sum += v[i].grades[j];
        }

        v[i].average = (float)sum / v[i].examCount;
    }

    printf("\nStudent averages:\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s %s — Average: %.2f\n",
               i + 1,
               v[i].firstName,
               v[i].lastName,
               v[i].average);
    }

    free(v);
    return 0;
}