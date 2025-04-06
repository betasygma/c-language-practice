#include <stdio.h>

int main()
{

    // deklarasi (m = misi, t = waktu)
    int jumlah_m;
    int m1 = 0, m2 = 0, m3 = 0;
    int total_t = 0, sisa_t;

    // input jumlah misi
    printf("Input jumlah misi dan tingkat kesulitan setiap misi.\nContoh input :\n3\t\t--> jumlah misi yang dimasukkan\n1\t\t--> tingkat kesulitan misi 1 (mudah)\n3\t\t--> tingkat kesulitan misi 2 (sulit)\n2\t\t--> tingkat kesulitan misi 3 (sedang)\n\n");
    scanf("%d", &jumlah_m);

    // cek jumlah misi valid apa enggak
    if ((jumlah_m < 1) || (jumlah_m > 3)) {
        printf("Jumlah misi harus antara 1 dan 3!\n");
        return 0;
    }

    // input tingkat kesulitan
    if (jumlah_m == 1) {
        scanf("%d", &m1);
    }
    else if (jumlah_m == 2) {
        scanf("%d%d", &m1, &m2);
    }
    else if (jumlah_m == 3) {
        scanf("%d%d%d", &m1, &m2, &m3);
    }

    // misi 1
    if (m1 == 1) {
        total_t += 30;
    }
    else if (m1 == 2) {
        total_t += 45;
    }
    else if (m1 == 3) {
        total_t += 90;
    }
    else {
        printf("Kesulitan yang kamu masukkan tidak valid! Program berhenti.\n");
        return 0;
    }

    // misi 2
    if (m2 == 1) {
        total_t += 30;
    }
    else if (m2 == 2) {
        total_t += 45;
    }
    else if (m2 == 3) {
        total_t += 90;
    }
    else {
        printf("Kesulitan yang kamu masukkan tidak valid! Program berhenti.\n");
        return 0;
    }

    // misi 3
    if (m3 == 1) {
        total_t += 30;
    }
    else if (m3 == 2) {
        total_t += 45;
    }
    else if (m3 == 3) {
        total_t += 90;
    }
    else {
        printf("Kesulitan yang kamu masukkan tidak valid! Program berhenti.\n");
        return 0;
    }

    // output total & sisa waktu
    sisa_t = 180 - total_t;
    printf("Total waktu yang dihabiskan: %d menit\n", total_t);
    printf("Sisa waktu: %d menit\n", sisa_t);

    // output aktivitas tambahan
    if (sisa_t >= 30)
    {
        printf("Benerin mobil kayanya asik di AutoWin. Anjay mulus!\n");
    }
    else if (sisa_t >= 15)
    {
        printf("Makan dulu gasih brow di Klenger Noodles. Perut kenyang hidup tenang!\n");
    }
    else
    {
        printf("Jangan sok jago, mampus kan ga cukup waktunya. ang ang ang bye bye real life.\n");
    }

    return 0;
}