#include <stdio.h>
/*
int main() {
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n*n; i++){
        printf("%d", i);
        if(i % n == 0) printf("\n");
        else printf(" ");
    }
}*/

int main() {
    int n, a = 0;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if(j != 0) printf(" ");
            printf("%d", i+a);
            a += n;
        }
        a = 0;
        printf("\n");
    }
}