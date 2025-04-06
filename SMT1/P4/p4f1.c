#include <stdio.h>
#include <string.h>

struct pokemon {
    char namaTrainer[20];
    char namaPokemon[20];
    int hp;
    int attack;
    int defense;
    int speed;
};

int main() {
    int N;
    scanf("%d", &N);

    struct pokemon arr[N];

    for (int i = 0; i < N; i++) {
        scanf("%s%s%d%d%d%d", arr[i].namaTrainer, arr[i].namaPokemon, &arr[i].hp, &arr[i].attack, &arr[i].defense, &arr[i].speed);
    }

    int Navg[N];
    for (int i = 0; i < N; i++) {
        Navg[i] = (arr[i].hp + arr[i].attack + arr[i].defense + arr[i].speed) / 4;
    }

    int Nmax = 0, Nwin;
    for (int i = 0; i < N; i++) {
        if (Navg[i] > Nmax) {
            Nmax = Navg[i]; 
            Nwin = i;
        }
    }
    
    printf("%s wins! %s said ez\n", arr[Nwin].namaPokemon, arr[Nwin].namaTrainer);
    return 0;
}