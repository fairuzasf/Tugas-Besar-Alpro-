#include "header_mesin.h"

int main() {
    int pilihan;
    int x, y, skor;
    char nama[50];
    char jawab;
    Hadiah arrHadiah[100];
    int jumlahHadiah = 0;
	Gerak arrGerak[100];
	int jumlahGerak = 0;
    int panjang;
    int lebar;
    
    do {
        // Menampilkan teks menu
        printf("\nMenu:\n");
        printf("1. Tambah hadiah\n");
        printf("2. Tambah gerak O\n");
        printf("3. Simulasi Lite O\n");
        printf("4. Input panjang & lebar papan\n");
        printf("5. Keluar\n");
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
                // Proses Sorting 
                    int i = jumlahHadiah - 1; 
                    /* Pola urutan scanning papan dengan menggeser elemen data lama ke arah kanan array selama:
                    Posisi koordinat Y lama nilainya lebih besar dari Y baru
                    Koordinat Y bernilai kembar, namun posisi X lama lebih besar dari x baru */
                    while (i >= 0 && (arrHadiah[i]. y > y || (arrHadiah[i].y == y && arrHadiah[i].x > x))) {
                        arrHadiah[i + 1] = arrHadiah[i]; // Proses pergeseran urutan elemen 
                        i--; 
                    }
                    // Sisipkan data inputan baru dari pengguna ke dalam indeks array yang sudah kosong terurut
                    arrHadiah[i + 1].x = x;
                    arrHadiah[i + 1].y = y;
                    arrHadiah[i + 1].skor = skor; 
                    strcpy(arrHadiah[i + 1].nama, nama);
                    // Menaikkan total counter jumlah data hadiah aktif
                    jumlahHadiah++; 

                    // 2. Menulis ulang hasil array yang sudah terurut ke file fisik 
                    FILE *arsip = fopen("thadiah.txt", "w");
                    if (arsip != NULL) {
                        for (int j = 0; j < jumlahHadiah; j++) {
                            fprintf(arsip, "%d %d %s %d\n", arrHadiah[j].x, arrHadiah[j].y, arrHadiah[j].nama, arrHadiah[j].skor);
                        }
                        // Mencetak penanda token batas akhir dengan (EOP-Mark) 
                        fprintf(arsip, "## ## ## ##\n");
                        fclose(arsip);
                        printf("Berhasil mencatat hadiah '%s' di koordinat (%d, %d) secara terurut.\n", nama, x, y);
                    }else {
                        printf("Gagal membuka file thadiah.txt untuk ditulis!\n");
                    }
				
	    }
            break;
            case 2:
		printf("Ingin mengisi: ");
		scanf(" %c", &jawab);
				
                if (jawab == 'Y' || jawab == 'y') {
                    printf("x : ");
                    scanf("%d", &x);
                    printf("y : ");
                    scanf("%d", &y);

                    tulisGerak(arrGerak, &jumlahGerak, x, y);
					
				}
                break;
            case 3:

                break;
            case 4:
		baca_hadiah(arrHadiah, &jumlahHadiah);
     		baca_gerak(arrGerak, &jumlahGerak);
                printf("Masukkan panjang papan: ");
                scanf("%d", &panjang);
                printf("Masukkan lebar papan: ");
                scanf("%d", &lebar);
                tampilkanPapan(arrHadiah, jumlahHadiah, arrGerak[0].x, arrGerak[0].y, 
		panjang, lebar, 0);
            break;
            case 5:
                system("exit");
                break;
            default:
                printf("Pilihan tidak valid. Silakan masukkan angka 1-5.\n");
        }

    } while (pilihan != 5);

    return 0;
}
