#include <stdio.h>

void numbersAddition(int *a, int *b, int n) { 
    for (int i = 0; i < n/2; i++) {
        int c = b[i];
        b[i] = b[n-1-i];
        b[n-1-i] = c;
    }

    for (int i = 0; i < n; i++) {
        int c = a[i];
        a[i] = c + b[i];
    }
} 
 
int main() { 
    int n; 
    scanf("%d", &n); 
 
    int arr1[n], arr2[n]; 
     
    for(int i = 0; i < n; i++) { 
        scanf("%d", &arr1[i]); 
    } 
    for(int i = 0; i < n; i++) { 
        scanf("%d", &arr2[i]); 
    } 
 
    numbersAddition(arr1, arr2, n); 
    for(int i = 0; i < n; i++) { 
        printf("%d ", arr1[i]); 
    } 
 
    return 0; 
}