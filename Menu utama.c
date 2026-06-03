#include <stdio.h>

void tulisHadiah() {
    // Membuka file dengan mode "a" (append)
    FILE *fhadiah = fopen("thadiah.txt", "a");
    if (fhadiah == NULL) {
        printf("Gagal membuka file thadiah.txt!\n");
        return;
    }

    int x, y, skor;
    char nama[50];

    printf("--- Tambah Data Hadiah ---\n");
    printf("Masukkan koordinat X : ");
    scanf("%d", &x);
    printf("Masukkan koordinat Y : ");
    scanf("%d", &y);
    printf("Masukkan Nama Hadiah (tanpa spasi) : ");
    scanf("%s", nama);
    printf("Masukkan Skor Hadiah : ");
    scanf("%d", &skor);

    // Menulis ke dalam file dengan format: X Y NAMA SKOR
    fprintf(fhadiah, "%d %d %s %d\n", x, y, nama, skor);
    printf("Data hadiah berhasil disimpan ke thadiah.txt!\n");

    fclose(fhadiah);
}