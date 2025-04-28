/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    int id, urgensi, urutanMasuk;
} Pasien;

typedef struct {
    Pasien data[MAX];
    int size, counterMasuk;
} PriorityQueue;

void InitPQ(PriorityQueue* q) {
    q->size = 0;
    q->counterMasuk = 0;
}

void masuk(PriorityQueue* q, int id, int urgensi) {
    if (q->size >= MAX) {
        printf("Antrian penuh!\n");
        return;
    }

    Pasien baru;
    baru.id = id;
    baru.urgensi = urgensi;
    baru.urutanMasuk = q->counterMasuk++;

    q->data[q->size++] = baru;

    for (int i = q->size - 1; i > 0; i--) {
        Pasien* a = &q->data[i];
        Pasien* b = &q->data[i - 1];
        if (a->urgensi > b->urgensi || (a->urgensi == b->urgensi && a->urutanMasuk < b->urutanMasuk)) {
            Pasien temp = *a;
            *a = *b;
            *b = temp;
        } else break;
    }
}

void layani(PriorityQueue * q) {
    if (q->size == 0) {
        printf("HORE\n");
        return;
    }
    printf("%d\n", q->data[0].id);

    for (int i = 1; i < q->size; i++) {
        q->data[i - 1] = q->data[i];
    }
    q->size--;
}

int main() {
    int Q;
    scanf("%d", &Q);
    PriorityQueue q;
    InitPQ(&q);

    for (int i = 0; i < Q; i++) {
        char perintah[7];
        scanf("%s", perintah);

        if (strcmp(perintah, "MASUK") == 0) {
            int id, urg;
            scanf("%d %d", &id, &urg);
            masuk(&q, id, urg);
        } else if (strcmp(perintah, "LAYANI") == 0) {
            layani(&q);
        }
    }
    return 0;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pasien {
    int id, urgensi, urutanMasuk;
    struct Pasien* next;
} Pasien;

typedef struct {
    Pasien* head;
    int counterMasuk;
} PriorityQueue;

Pasien* tambahPasien(int id, int urgensi, int urutan) {
    Pasien* p = (Pasien*)malloc(sizeof(Pasien));
    p->id = id;
    p->urgensi = urgensi;
    p->urutanMasuk = urutan;
    p->next = NULL;
    return p;
}

void initPQ(PriorityQueue* pq) {
    pq->head = NULL;
    pq->counterMasuk = 0;
}

void masuk(PriorityQueue* pq, int id, int urgensi) {
    Pasien* baru = tambahPasien(id, urgensi, pq->counterMasuk++);

    if (!pq->head || urgensi > pq->head->urgensi || (urgensi == pq->head->urgensi && baru->urutanMasuk < pq->head->urutanMasuk)) {
        baru->next = pq->head;
        pq->head = baru;
        return;
    }

    Pasien* curr = pq->head;
    while (curr->next && (curr->next->urgensi > urgensi || (curr->next->urgensi == urgensi && curr->next->urutanMasuk < baru->urutanMasuk))) {
        curr = curr->next;
    }
    baru->next = curr->next;
    curr->next = baru;
}

void layani(PriorityQueue* pq) {
    if (!pq->head) {
        printf("HORE\n");
        return;
    }

    printf("%d\n", pq->head->id);
    Pasien* temp = pq->head;
    pq->head = pq->head->next;
    free(temp);
}

int main() {
    int Q;
    scanf("%d", &Q);

    PriorityQueue pq;
    initPQ(&pq);

    for (int i = 0; i < Q; i++) {
        char perintah[7];
        scanf("%s", perintah);

        if (strcmp(perintah, "MASUK") == 0) {
            int id, urg;
            scanf("%d %d", &id, &urg);
            masuk(&pq, id, urg);
        } else if (strcmp(perintah, "LAYANI") == 0) layani(&pq);
    }
   return 0; 
}