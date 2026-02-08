/*
 * Project: Medicine Inventory Manager
 * File: medicines.c
 * Description:
 *   This program reads information about medicines, checks if a medicine
 *   exists in stock, increases the price of a selected medicine by 5%,
 *   displays contraindications for a given diagnosis, and finds the
 *   cheapest medicines for a specific diagnosis.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char diagnosis[30];
    char contraindications[40];
    int prescribedQty;
} DESC;

typedef struct {
    int code;
    char name[25];
    float price;
    int quantity;
    DESC details;
} MED;

void readMedicines(MED *v, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nMedicine %d:\n", i + 1);

        printf("Code: ");
        scanf("%d", &v[i].code);

        printf("Name: ");
        scanf("%s", v[i].name);

        printf("Price: ");
        scanf("%f", &v[i].price);

        printf("Quantity in stock: ");
        scanf("%d", &v[i].quantity);

        printf("Diagnosis: ");
        scanf("%s", v[i].details.diagnosis);

        printf("Contraindications: ");
        scanf("%s", v[i].details.contraindications);

        printf("Prescribed quantity: ");
        scanf("%d", &v[i].details.prescribedQty);
    }
}

int main() {
    int n;
    printf("Number of medicines: ");
    scanf("%d", &n);

    MED *v = malloc(n * sizeof(MED));
    if (!v) {
        printf("Error: insufficient memory.\n");
        return 1;
    }

    
    readMedicines(v, n);

    
    char name[25];
    printf("\nEnter the name of the medicine to search: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].name, name) == 0) {
            printf("The medicine %s exists in stock.\n", name);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("The medicine %s does NOT exist in stock.\n", name);

    
    printf("\nEnter the name of the medicine to increase price by 5%%: ");
    scanf("%s", name);

    found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].name, name) == 0) {
            v[i].price *= 1.05f;
            printf("New price of %s is %.2f\n", name, v[i].price);
            found = 1;
            break;
        }
    }
    if (!found)
        printf("Medicine %s not found for price update.\n", name);

   
    char diag[30];
    printf("\nEnter a diagnosis to show contraindications: ");
    scanf("%s", diag);

    printf("\nContraindications for medicines with diagnosis %s:\n", diag);
    found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].details.diagnosis, diag) == 0) {
            printf("%s: %s\n", v[i].name, v[i].details.contraindications);
            found = 1;
        }
    }
    if (!found)
        printf("No medicines found for this diagnosis.\n");

    
    printf("\nEnter a diagnosis to find the cheapest medicines: ");
    scanf("%s", diag);

    float minPrice = -1;
    for (int i = 0; i < n; i++) {
        if (strcmp(v[i].details.diagnosis, diag) == 0) {
            if (minPrice < 0 || v[i].price < minPrice)
                minPrice = v[i].price;
        }
    }

    if (minPrice < 0) {
        printf("No medicines found for this diagnosis.\n");
    } else {
        printf("\nMedicines with the minimum price (%.2f) for diagnosis %s:\n",
               minPrice, diag);

        for (int i = 0; i < n; i++) {
            if (strcmp(v[i].details.diagnosis, diag) == 0 &&
                v[i].price == minPrice)
                printf("%s\n", v[i].name);
        }
    }

    free(v);
    return 0;
}