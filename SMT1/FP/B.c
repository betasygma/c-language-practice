#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int a, x, y; // kode, harga, stok
    char *n; // nama
} Menu;

Menu *menu;
int indeksMenu = 0, kapasitasMenu = 10;
long long totalPenghasilan = 0;

int nyariIndex(int kode);
void nambahMenu(int kode, char *nama, int harga, int stok);
void hapusMenu(int kode);
void infoMenu(int kode);
void orderMenu(int kode, int jumlah);
void validasiMemori();
char *bacaNama();

int main() {
    menu = (Menu *)malloc(sizeof(Menu) * kapasitasMenu);
    
    char command[7];
    while (1) {
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            int kode, harga, stok;
            char *nama = NULL;

            scanf("%d", &kode);
            getchar();
            nama = bacaNama();
            scanf("%d%d", &harga, &stok);

            nambahMenu(kode, nama, harga, stok);
            free(nama);
        } else if (strcmp(command, "REMOVE") == 0) {
            int kode;
            scanf("%d", &kode);
            hapusMenu(kode);
        } else if (strcmp(command, "INFO") == 0) {
            int kode;
            scanf("%d", &kode);
            infoMenu(kode); 
        } else if (strcmp(command, "ORDER") == 0) {
            int kode, jumlah;
            scanf("%d%d", &kode, &jumlah);
            orderMenu(kode, jumlah);
        } else if (strcmp(command, "CLOSE") == 0) {
            printf("Earnings: Rp%lld\n", totalPenghasilan);
            printf("Informatics canteen is closing... thanks for the visit!\n");
            
            for (int i = 0; i < indeksMenu; i++) {
                free(menu[i].n);
            }
            free(menu);
            break;
        }
    }
    return 0;
}

int nyariIndex(int kode) {
    for (int i = 0; i < indeksMenu; i++)
        if (menu[i].a == kode) return i;
    return -1;
}

void nambahMenu(int kode, char *nama, int harga, int stok) {
    if (nyariIndex(kode) != -1) {
        printf("Menu is already exists\n");
        return;
    }
    validasiMemori();
    menu[indeksMenu].a = kode;
    menu[indeksMenu].n = strdup(nama);
    menu[indeksMenu].x = harga;
    menu[indeksMenu].y = stok;    
    indeksMenu++;
    printf("Menu added\n");
}

void hapusMenu(int kode) {
    int indeks = nyariIndex(kode);
    if (indeks == -1) {
        printf("Menu does not exist\n");
        return;
    }
    free(menu[indeks].n);
    for (int i = indeks; i < indeksMenu - 1; i++) {
        menu[i] = menu[i + 1];
    }
    indeksMenu--;
    printf("Menu removed\n");
}

void infoMenu(int kode) {
    int indeks = nyariIndex(kode);
    if (indeks == -1) {
        printf("Menu does not exist\n");
        return;
    }
    printf("#%d %s\nPrice : Rp%d\nStock : %dx\n", menu[indeks].a, menu[indeks].n, menu[indeks].x, menu[indeks].y);
}

void orderMenu(int kode, int jumlah) {
    int indeks = nyariIndex(kode);
    if (indeks == -1) {
        printf("Menu does not exist\n");
        return;
    }
    if (jumlah == 0) printf("So you want to order or what\n");
    else if (jumlah > menu[indeks].y) printf("Apologize, the stock is not enough\n");
    else {
        menu[indeks].y -= jumlah;
        long long bayar = (long long)menu[indeks].x * jumlah;
        totalPenghasilan += bayar;
        printf("Ordered %dx %s for Rp%lld\n", jumlah, menu[indeks].n, bayar);
    }
}

void validasiMemori() {
    if (indeksMenu == kapasitasMenu) {
        kapasitasMenu *= 2;
        menu = (Menu *)realloc(menu, kapasitasMenu * sizeof(Menu));
    }
}

char *bacaNama() {
    int uk = 10;
    char *nama = (char *)malloc(uk);

    int pos = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (pos == uk - 1) {
            uk *= 2;
            nama = (char *)realloc(nama, uk);
        }
        nama[pos++] = c;
    }
    nama[pos] = '\0';
    return nama;
}