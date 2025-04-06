#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_DATA 100

// struktur data KTP
typedef struct {
    char nik[17];
    char nama[61];
    char tempat_lahir[51];
    char tanggal_lahir[11];
    char jenis_kelamin[10];
    char gol_darah[3];
    char alamat[256];
    char rt[4];
    char rw[4];
    char kelurahan[51];
    char kecamatan[51];
    char agama[15];
    char status_perkawinan[15];
    char pekerjaan[31];
    char kewarganegaraan[4];
} KTP;

KTP dataKTP[MAX_DATA];
int jumlahData = 0;

// fungsi ubah string jadi uppercase
void toUpperCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }
}

// fungsi tambah data
void tambahData() {
    if (jumlahData >= MAX_DATA) {
        printf("Data sudah penuh!\n");
        return;
    }

    KTP temp;
    printf("Masukkan NIK (16 digit): ");
    scanf("%16s", temp.nik);
    getchar();
    printf("Masukkan Nama: ");
    fgets(temp.nama, sizeof(temp.nama), stdin);
    temp.nama[strcspn(temp.nama, "\n")] = 0;
    printf("Masukkan Tempat Lahir: ");
    fgets(temp.tempat_lahir, sizeof(temp.tempat_lahir), stdin);
    temp.tempat_lahir[strcspn(temp.tempat_lahir, "\n")] = 0;
    printf("Masukkan Tanggal Lahir (dd-mm-yyyy): ");
    scanf("%10s", temp.tanggal_lahir);
    getchar();
    printf("Masukkan Jenis Kelamin (LAKI-LAKI/PEREMPUAN): ");
    fgets(temp.jenis_kelamin, sizeof(temp.jenis_kelamin), stdin);
    temp.jenis_kelamin[strcspn(temp.jenis_kelamin, "\n")] = 0;
    printf("Masukkan Golongan Darah (O, A, B, AB): ");
    scanf("%2s", temp.gol_darah);
    getchar();
    printf("Masukkan Alamat: ");
    fgets(temp.alamat, sizeof(temp.alamat), stdin);
    temp.alamat[strcspn(temp.alamat, "\n")] = 0;
    printf("Masukkan RT: ");
    scanf("%3s", temp.rt);
    getchar();
    printf("Masukkan RW: ");
    scanf("%3s", temp.rw);
    getchar();
    printf("Masukkan Kelurahan/Desa: ");
    fgets(temp.kelurahan, sizeof(temp.kelurahan), stdin);
    temp.kelurahan[strcspn(temp.kelurahan, "\n")] = 0;
    printf("Masukkan Kecamatan: ");
    fgets(temp.kecamatan, sizeof(temp.kecamatan), stdin);
    temp.kecamatan[strcspn(temp.kecamatan, "\n")] = 0;
    printf("Masukkan Agama: ");
    scanf("%14s", temp.agama);
    getchar();
    printf("Masukkan Status Perkawinan: ");
    fgets(temp.status_perkawinan, sizeof(temp.status_perkawinan), stdin);
    temp.status_perkawinan[strcspn(temp.status_perkawinan, "\n")] = 0;
    printf("Masukkan Pekerjaan: ");
    fgets(temp.pekerjaan, sizeof(temp.pekerjaan), stdin);
    temp.pekerjaan[strcspn(temp.pekerjaan, "\n")] = 0;
    printf("Masukkan Kewarganegaraan (WNI/WNA): ");
    scanf("%3s", temp.kewarganegaraan);
    getchar();

    toUpperCase(temp.nama);
    toUpperCase(temp.tempat_lahir);
    toUpperCase(temp.jenis_kelamin);
    toUpperCase(temp.gol_darah);
    toUpperCase(temp.alamat);
    toUpperCase(temp.kelurahan);
    toUpperCase(temp.kecamatan);
    toUpperCase(temp.agama);
    toUpperCase(temp.status_perkawinan);
    toUpperCase(temp.pekerjaan);
    toUpperCase(temp.kewarganegaraan);

    dataKTP[jumlahData++] = temp;
    printf("Data berhasil ditambahkan!\n");
}

// fungsi cari data
void cariData() {
    char nik[17];
    printf("Masukkan NIK yang ingin dicari: ");
    fgets(nik, sizeof(nik), stdin);
    nik[strcspn(nik, "\n")] = 0;

    if (strlen(nik) != 16) printf("NIK harus terdiri dari 16 digit!\n"); return;

    for (int i = 0; i < jumlahData; i++) {
        if (stricmp(dataKTP[i].nik, nik) == 0) {
            printf("NIK: %s\n", dataKTP[i].nik);
            printf("Nama: %s\n", dataKTP[i].nama);
            printf("Tempat/Tgl Lahir: %s, %s\n", dataKTP[i].tempat_lahir, dataKTP[i].tanggal_lahir);
            printf("Jenis Kelamin: %s\n", dataKTP[i].jenis_kelamin);
            printf("Golongan Darah: %s\n", dataKTP[i].gol_darah);
            printf("Alamat: %s\n", dataKTP[i].alamat);
            printf("RT/RW: %s/%s\n", dataKTP[i].rt, dataKTP[i].rw);
            printf("Kel/Desa: %s\n", dataKTP[i].kelurahan);
            printf("Kecamatan: %s\n", dataKTP[i].kecamatan);
            printf("Agama: %s\n", dataKTP[i].agama);
            printf("Status Perkawinan: %s\n", dataKTP[i].status_perkawinan);
            printf("Pekerjaan: %s\n", dataKTP[i].pekerjaan);
            printf("Kewarganegaraan: %s\n", dataKTP[i].kewarganegaraan);
            printf("Berlaku Hingga: SEUMUR HIDUP\n");
            printf("------------------------------\n");
            return;
        }
    }
    printf("Data dengan NIK tersebut tidak ditemukan!\n");
}

// fungsi tampilkan data
void tampilkanData() {
    if (jumlahData == 0) printf("Tidak ada data tersimpan.\n"); return;
    
    for (int i = 0; i < jumlahData; i++) {
        printf("NIK: %s\n", dataKTP[i].nik);
        printf("Nama: %s\n", dataKTP[i].nama);
        printf("Tempat/Tgl Lahir: %s, %s\n", dataKTP[i].tempat_lahir, dataKTP[i].tanggal_lahir);
        printf("Jenis Kelamin: %s\n", dataKTP[i].jenis_kelamin);
        printf("Golongan Darah: %s\n", dataKTP[i].gol_darah);
        printf("Alamat: %s\n", dataKTP[i].alamat);
        printf("RT/RW: %s/%s\n", dataKTP[i].rt, dataKTP[i].rw);
        printf("Kel/Desa: %s\n", dataKTP[i].kelurahan);
        printf("Kecamatan: %s\n", dataKTP[i].kecamatan);
        printf("Agama: %s\n", dataKTP[i].agama);
        printf("Status Perkawinan: %s\n", dataKTP[i].status_perkawinan);
        printf("Pekerjaan: %s\n", dataKTP[i].pekerjaan);
        printf("Kewarganegaraan: %s\n", dataKTP[i].kewarganegaraan);
        printf("Berlaku Hingga: SEUMUR HIDUP\n");
        printf("------------------------------\n");
    }
}

// fungsi hapus data
void hapusData() {
    char nik[17];
    printf("Masukkan NIK yang ingin dihapus: ");
    scanf("%16s", nik);
    getchar();
    
    for (int i = 0; i < jumlahData; i++) {
        if (strcmp(dataKTP[i].nik, nik) == 0) {
            for (int j = i; j < jumlahData - 1; j++) {
                dataKTP[j] = dataKTP[j + 1];
            }
            jumlahData--;
            printf("Data berhasil dihapus!\n");
            return;
        }
    }
    printf("Data dengan NIK tersebut tidak ditemukan!\n");
}

int main() {
    int pilihan;
    do {
        printf("\nMENU:\n");
        printf("1. Tambah Data\n");
        printf("2. Cari Data Berdasarkan NIK\n");
        printf("3. Tampilkan Semua Data\n");
        printf("4. Hapus Data Berdasar NIK\n");
        printf("5. Keluar\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();
        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: cariData(); break;
            case 3: tampilkanData(); break;
            case 4: hapusData(); break;
            case 5: printf("Keluar dari program.\n"); break;
            default: printf("Pilihan tidak valid!\n");
        }
    } while (pilihan != 5);
    return 0;
}
