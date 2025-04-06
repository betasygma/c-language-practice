#include <stdio.h>

int main() {
    int matrix[3][3], det;

    // input matriks
    printf ("Enter the matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            scanf ("%d", &matrix[i][j]);
    }

    // hitung determinan
    int posDiag[3] = {1, 1, 1}, negDiag[3] = {1, 1, 1};
    for (int i = 0; i < 3; i++) {
        int p = 0, n = 2;
        for (int j = 0; j < 3; j++) {
            posDiag[i] *= matrix[j][(p + i) % 3];
            negDiag[i] *= matrix[j][(n + i) % 3];
            p++;
            n--;
        }
    }
    for (int i = 0; i < 3; i++) {
        det += posDiag[i] - negDiag[i];
    }

    // output matriks
    printf ("The matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf ("%d", matrix[i][j]);
            if (j == 2) printf ("\n");  // newline antarbaris
            else printf (" ");  // space antarkolom
        }
    }

    // output determinan & apa matriks bisa di-invers atau tidak 
    printf ("Matrix determinant: %d\n", det);
    printf ((det == 0) ? "Matrix cannot be inverted\n" : "Matrix is invertible\n");
    
    return 0;
}