#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* definisiin struktur dari suatu tree node */
struct treeNode
{
    struct treeNode *left;   /* pointer ke child kiri */
    int data;                /* nyimpen data node */
    struct treeNode *right;  /* pointer ke child kanan */
    struct treeNode *parent; /* pointer ke node parent */
}; /* akhiri struktur treeNode */

/* definisiin TreeNode dan TreeNodePtr  biar mudah pakainya */
typedef struct treeNode TreeNode; // alias buat struct treeNode
typedef TreeNode *TreeNodePtr;    // alias buat pointer ke struct treeNode

/*
 * fungsi: preOrder
 * tujuan: traversal tree dengan metode preorder dan nyetak data.
 * node dicetak pake format "node: data", dan buat leaf, data dicetak dengan penjumlahan sepanjang jalur ke daun itu.
 */
void preOrder(TreeNodePtr treePtr, int sum)
{
    /* kalo ga kosong (punya anak), maka traverse */
    if (treePtr->left != NULL || treePtr->right != NULL)
    {                                         // is a node
        printf("node: %3d\n", treePtr->data); // cetak data node
        // ----------------------------
        // traversal secara rekursif ke subtree kiri
        if (treePtr->left != NULL)
            preOrder(treePtr->left, sum + treePtr->data);

        // traversal secara rekursif ke subtree kanan
        if (treePtr->right != NULL)
            preOrder(treePtr->right, sum + treePtr->data);
        // ----------------------------
    } /* akhiri jika */
    else {                                               // node ga punya anak, maka pasti leaf
        printf("leaf : %d\n", sum + treePtr->data); // cetak sum data dari root sampe ke daun
    }
} /* akhiri fungsi preOrder */

/*
 * fungsi: insertLeft
 * tujuan: nambahin node baru sebagai anak kiri dari node yang diberikan (from).
 * tetapin parent node baru ke node 'from' dan return node baru.
 */
TreeNodePtr insertLeft(TreeNodePtr from, int data)
{
    TreeNodePtr d = malloc(sizeof(TreeNode)); // alokasi memori buat node baru
    d->data = data;                           // tentuin data buat node baru
    // ----------------------------
    d->left = NULL;   // inisialisasi anak kiri NULL
    d->right = NULL;  // inisialisasi anak kanan NULL
    d->parent = from; // tetapin parent node baru ke node 'from'
    from->left = d;   // sambungin node baru jadi anak kiri dari node 'from'
    // ----------------------------
    return d; // return node baru
}

/*
 * fungsi: insertRight
 * tujuan: nambnahin node baru sebagai anak kanan dari node yang diberikan (form).
 * tetapin parent node baru ke node 'from' dan return node baru.
 */
TreeNodePtr insertRight(TreeNodePtr from, int data)
{
    TreeNodePtr d = malloc(sizeof(TreeNode));
    d->data = data; // tentuin data buat node baru
    // ----------------------------
    d->left = NULL;   // inisialisasi anak kiri NULL
    d->right = NULL;  // inisialisasi anak kanan NULL
    d->parent = from; // tetapin parent node baru ke node 'from'
    from->right = d;  // sambungin node baru jadi anak kanan dari node 'from'
    // ----------------------------
    return d; // return node baru
}

/*
 * fungsi: parseFile
 * tujuan: Membaca file input buat mbangun pohon.
 * file akan ngasih informasi gimana node harus dihubungin (kiri/kanan, dan hubungan parent-child).
 * node root akan dibuat pertama kali, terus node lainnya disisipkan ngikutin aturan yang ada di file.
 */
TreeNodePtr parseFile(char *filename, TreeNodePtr cur)
{
    FILE *fptr;
    TreeNodePtr root = NULL; // inisialisasi root NULL

    /* buka file buat dibaca */
    if ((fptr = fopen(filename, "r")) == NULL)
    {
        printf("Error! opening file");
        exit(1); // program keluar kalo file gagal dibuka (return NULL)
    }

    char c[100]; // buffer buat nyimpen tiap baris dari file

    /* baca file baris per baris */
    while (fgets(c, 100, (FILE *)fptr))
    {
        printf("%s", c); // cetak baris saat ini buat debugging

        /* baca digit selanjutnya (yang isinya data node) */
        char digit[5];
        fgets(digit, 5, (FILE *)fptr);

        /* ngapus "\n" kalo ada */
        for (int x = 0; x < 5; x++) {
            if (digit[x] == '\n')
                digit[x] = '\0';
        }

        int data = atoi(digit); // konversi string jadi integer
		int count, cur2;

		/* kasus buat nyisipin node kiri */
        if (c[0] == 'l')
        {
            count = 0;
            cur2 = 2;
            while (1) { /* While (true) */
                if (c[cur2] = '\n') {
                    break;
                }
                cur2 += 1;
                count += 1;
            }
            // get the digit here
            printf("left - data: %d\n", data);
            cur = insertLeft(cur, data);    // sisipin jadi anak kiri dari node saat ini
        }
        else if (c[0] == 'u') /* kasus buat nyisipin node kanan ('u' buat naik, terus 'r' buat kanan) */
        {
            cur2 = 1;
            while (c[cur2] == 'u') {
                cur2 += 1;
            }
            for (int x = 0; x < cur2; x++) {
                cur = cur->parent;  // naik ke parent sesuai banyak 'u' yang ada
            }
            // get the digit here
            cur = insertRight(cur, data);   // sisipin jadi anak kanan dari node saat ini
            // get the digit here
            printf("right - data: %d\n", data);
        }
        else if (c[0] == '0')   /* kasus node root */
        {
            cur = malloc(sizeof(TreeNode));	// alokasi memori buat node root
			cur->parent = NULL;	// root ga punya parent
			cur->left = NULL;	// ga ada anak kiri
			cur->right = NULL;	// ga ada anak kanan
			cur->data = data;	// tentuin data buat root
			count = 0;
			cur2 = 2;

            while (1) { /* while (true) */
                if (c[cur2] = '\n')
                {
                    break;
                }
                cur2 += 1;
                count += 1;
            }
            // get the digit here
            root = cur; // tetapin root pointer ke node baru
            printf("root - data: %d\n", data);  
        }
    }
    fclose(fptr);	// tutup file habis selesai dibaca
	return root;	// return root dari tre
}

/*
 * fungsi main
 * tujuan: manggil fungsi parsefile buat mbangun tree sama nge-traversal preorder
 */
int main()
{
    TreeNodePtr root = NULL;
    root = parseFile("02_file_input.txt", root); // parse file buat mbangun tree
    preOrder(root, 0);                           // lakuin traversal pro=eorder dan cetak pohon
    return 0;
}