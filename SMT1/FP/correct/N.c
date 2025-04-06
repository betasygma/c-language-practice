#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int banding(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int hash[1000001] = {0};

int fungsiHash(int x, int y, int z) {
    return abs(x * 31 + y * 97 + z * 73) % 1000001;
}

int unikGa(int x, int y, int z) {
    int nilaiHash = fungsiHash(x, y, z);
    if (hash[nilaiHash]) return 0;
    hash[nilaiHash] = 1;
    return 1;
}

int hitungTriplet(int *arr, int n) {
    qsort(arr, n, sizeof(int), banding);
    memset(hash, 0, sizeof(hash));
    
    int jumlahTriplet = 0;

    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == arr[k]) {
                if (unikGa(arr[i], arr[j], arr[k])) {
                    if (arr[i] == 0) jumlahTriplet++;
                    else jumlahTriplet += 2;
                }
                i++;
                j--;
            }
            else if (sum < arr[k]) i++;
            else j--;
        }
    }
    return jumlahTriplet;
}

int main() {
    int n;
    scanf("%d", &n);

    int bea[n], leo[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &bea[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &leo[i]);
    }
 
    int tripletBea = hitungTriplet(bea, n);
    int tripletLeo = hitungTriplet(leo, n);
    
    if (tripletBea < tripletLeo) printf("i see no god up here, other than me(ow)\n");
    else if (tripletBea > tripletLeo) printf("thats pretty lame, and thats the way things go\n");
    else printf("a worthy opponent, i think i might wanna do it all over again\n");
    
    return 0;
}