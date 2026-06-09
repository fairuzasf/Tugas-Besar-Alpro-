#include "header_mesin.h"

int main() {
    int pilihan;
    int x, y, skor;
    char nama[50];
    char jawab;
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

            printf("Ingin mengisi: ");
            scanf(" %c", &jawab);
            if (jawab == 'Y' || jawab == 'y') {
                printf("x : ");
                scanf("%d", &x);
                printf("y : ");
                scanf("%d", &y);
                printf("nama : ");
                scanf("%s", nama);
                printf("skor : ");
                scanf("%d", &skor);
                tulisHadiah(arrHadiah, &jumlahHadiah, x, y, nama, skor);
	    }
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
