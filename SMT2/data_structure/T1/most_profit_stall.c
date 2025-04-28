#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STALLS 100

typedef struct {
    char name[50];
    double income;
    double expenses;
    double profit;
} Stall;

// fungsi buat bandingin profit (sort descending)
int compare(const void *a, const void *b) {
    double profitA = ((Stall *)a)->profit;
    double profitB = ((Stall *)b)->profit;
    if (profitB > profitA) return 1;
    if (profitB < profitA) return -1;
    return 0;
}

int main() {
    Stall stalls[MAX_STALLS];
    int count = 0;
    double totalProfit = 0;
    double maxProfit = -1e9;

    printf("Enter stall data (Name Income Expenses), type 'xxxxxx' to finish:\n");
    while (count < MAX_STALLS) {
        char name[50];
        double income, expenses;
        scanf("%s", name);
        if (strcmp(name, "xxxxxx") == 0) break;
        scanf("%lf %lf", &income, &expenses);

        strcpy(stalls[count].name, name);
        stalls[count].income = income;
        stalls[count].expenses = expenses;
        stalls[count].profit = income - expenses;

        totalProfit += stalls[count].profit;
        if (stalls[count].profit > maxProfit) {
            maxProfit = stalls[count].profit;
        }
        count++;
    }

    // sort berdasar descending profit
    qsort(stalls, count, sizeof(Stall), compare);

    printf("\nBAZAAR PROFIT REPORT:\n");
    printf("------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %.2f\n", stalls[i].name, stalls[i].profit);
    }
    printf("------------------------------------\n");
    printf("Total Stall: %d\n", count);
    printf("Total Profit/Loss: %.2f\n", totalProfit);
    printf("Stall(s) with the highest profit: ");
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (stalls[i].profit == maxProfit) {
            printf("%s ", stalls[i].name);
            found = 1;
        }
    }
    if (!found) printf("None");
    printf("\n");
    return 0;
}