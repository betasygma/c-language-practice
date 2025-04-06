include <stdio.h>

int main(){
    int N;
    int angka[5];
    scanf("%d", N);

    for(i = 0; i < N; i++){
        scanf("%d", angka[i]);
    }

    printf("%d\n%d\n%d\n%d\n%d", angka[4], angka[3],angka[2],angka[1],angka[0]);

    return 0;
}