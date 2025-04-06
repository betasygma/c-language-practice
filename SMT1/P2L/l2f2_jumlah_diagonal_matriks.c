#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    int diagutama = 0, diagsamping = 0;
    for (int i = 0; i < n; i++) {
        diagutama += a[i][i];
        diagsamping += a[i][n - 1 - i];
    }

    printf("%d %d\n", diagutama, diagsamping);
    
}