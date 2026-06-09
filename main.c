#include "header_mesin.h"

int main() {
    int pilihan;
     Hadiah arrHadiah[100];
     int jumlahHadiah = 0;

    do {
        // Menampilkan teks menu
        printf("\nMenu:\n");
        printf("1. Tambah hadiah\n");
        printf("2. Tambah gerak O\n");
        printf("3. Simulasi Lite O\n");
        printf("4. Keluar\n");
        printf("Masukkan Menu: ");

        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
            baca_hadiah(arrHadiah, &jumlahHadiah);
        cetakTabelHadiah(arrHadiah, jumlahHadiah);
                printf("\n--- TAMBAH HADIAH ---\n");
                printf("Masukkan koordinat X: ");
                scanf("%d", &x);
                printf("Masukkan koordinat Y: ");
                scanf("%d", &y);
                printf("Masukkan Nama Hadiah : ");
                scanf("%s", nama);
                printf("Masukkan Skor: ");
                scanf("%d", &skor);
                tulisHadiah(arrHadiah, &jumlahHadiah, x, y, nama, skor);

                printf("\n");
                break;

            case 2:

                break;
            case 3:

                break;
            case 4:
                printf("exit");
                break;
            default:
                printf("Pilihan tidak valid. Silakan masukkan angka 1-4.\n");
        }

    } while (pilihan != 4);

    return 0;
}
