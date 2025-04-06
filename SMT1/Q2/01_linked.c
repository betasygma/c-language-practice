#include <stdio.h>
#include <stdlib.h>
#define FALSE 0
#define TRUE 1 /* Semua bilangan non-nol jadi true */

/* struct node buat singly linked list */
struct sNode {
	int data;			// data yang disimpan di node
	struct sNode *next;	// pointer ke node selanjutnya
};

/* definisiin jadi tNode dan Node biar mudah pakainya */
typedef struct sNode tNode;	// alias buat struct sNode
typedef tNode *Node;		// alias buat pointer ke struct sNode
int flag = FALSE;			// flag buat penanda data udah di-sort

void insert(Node *start, int data);	// fungsi buat insert data ke dalem linked list
void bubbleSort(Node start);		// fungsi buat ngurutin linked list pakai bubble sort
void swap(Node a, Node b);			// fungsi buat nukar data dua node
void print(Node start);				// fungsi buat nyetak data linked list

int main() {
	/* inisialsasi buat linked list */
	int initArr[] = {10, 1, 120, 45, 5, 0, 15, 20, 20, 100}; /* Initial value in list, min 5 */
	Node start = NULL;

	/* masukin elemen array ke dalem linked list */
	for(int i = 0; i < 10; i++) {
		insert(&start, initArr[i]);
	}

	/* cetak linked list sebelum sorting */
	print(start);

	/* tambahin input akhir ke linked list */
	printf("Input: ");
	int input;
	scanf("%d", &input);
	insert(&start, input);

	/* sorting linked list pake bubble sort */
	bubbleSort(start);

	/* cetak linked list setelah sorting */
	print(start);
	return 0;
}

/* fungsi buat insert data ke dalem linked list */
void insert(Node *start, int data) {
	Node temp = malloc(sizeof(Node));	// alokasi memori buat node baru
	// ----------------------------
	temp->data = data;		// masukin data ke node baru
	temp->next = *start;	// node baru nunjuk ke node sebelumnya
	// ----------------------------
	*start = temp;			// node baru dijadiin head dari linked list 
}

/* fungsi buat nyetak data linked list */
void print(Node start) {
	Node temp = start;	// mulai dari node pertama
	while(temp != NULL) {
		/* nyetak data node */
		if(temp->next != NULL)
			printf("%d, ", temp->data);	// tambahin koma kalo masih ada node selanjutnya
	// ----------------------------
		else {
			printf("%d", temp->data);	// ga ada koma buat node terakhir

			/* cetak status linked list */
			if(flag == FALSE) printf(" -> before sorting\n");	// status sebelum sorting
			else printf(" -> after sorting\n");					// status setelah sorting
		}
	// ----------------------------
		temp = temp->next;	// pindah ke node berikutnya
	}
}

/* fungsi buat ngurutin linked list pakai bubble sort */
void bubbleSort(Node start) {
	int swapped = 0;	// tanda ada swap pas iterasi
	Node temp;			// pointer sementara buat traversal
	Node temp1 = NULL;	// node terakhir yang udah urut

	/* kalo linked list kosong, keluar dari fungsi */
	if(start == NULL) return;

	do {
		swapped = 0;	// reset tanda swap
		temp = start;	// mulai dari node pertama

		/* lewati linked list sampe node terakhir yang belum urut */
		while(temp->next != temp1) {
	// ----------------------------
			/* kalo ada data ga urut, tukar */
			if(temp->data > temp->next->data) {
				swap(temp, temp->next);	// tukar data dua node
				swapped = 1;			// tandai kalo ada swap
			}
			temp = temp->next;	// pindah ke node selanjutnya
	// ----------------------------
		}
		/* kurangi area sorting (temp1 itu node terakhir yang udah urut) */
		temp1 = temp;
	}
	while(swapped);	// ulangi sampe ga ada swap lagi
	
	/* tandai kalo linked list udah di-sorting */
	flag = TRUE;
}

/* fungsi buat nukar data dua node */
void swap(Node a, Node b) {
	// ----------------------------
	int temp = a->data;	// simpen sementara data node a
	a->data = b->data;	// pindah data node b ke node a
	b->data = temp;		// pindah data sementara (node a lama) ke node b
	// ----------------------------
}
