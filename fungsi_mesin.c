#include "header_mesin.h"

char CC;
int EOP;

// Fungsi untuk maju satu karakter
void ADV(FILE *arsip) {
    int ch = fgetc(arsip);
    if (ch == EOF) {
        EOP = 1;
        CC = '\0';
    } else {
        EOP = 0;
        CC = ch;
    }
}
// Fungsi untuk memulai mesin
void START(FILE *arsip) {
    ADV(arsip);
}
//Fungsi untuk menjalankan animasi
void wait(float x) {
	time_t start;
	time_t current;
	time(&start);
	do{
	    time(&current);
	} while (difftime(current,start) < x); 
} 

// Fungsi tambahan untuk mengabaikan spasi, enter, dan tab
void AbaikanBlank(FILE *arsip) {
    while (!EOP && (CC == ' ' || CC == '\n' || CC == '\r' || CC == '\t')) {
        ADV(arsip);
    }
}
// Fungsi untuk membaca integer per karakter
int baca_angka(FILE *arsip) {
    AbaikanBlank(arsip);
    if (EOP) {
        return -1;
    } else if (CC == '#') {
        ADV(arsip);
        if (CC == '#') {
            EOP = 1;
            return -1;
        }
    }
    int hasil = 0;
    int tanda = 1;
    if (CC == '-') {
        tanda = -1;
        ADV(arsip);
    }
    while (!EOP && CC >= '0' && CC <= '9') {
        hasil = (hasil * 10) + (CC - '0');
        ADV(arsip);
    }
    return hasil * tanda;
}
// Fungsi untuk membaca kata/string
void baca_string(FILE *arsip, char *str) {
    AbaikanBlank(arsip);
    if (EOP) return;
    int i = 0;
    while (!EOP && CC != ' ' && CC != '\n' && CC != '\r' && CC != '\t') {
        str[i++] = CC;
        ADV(arsip);
    }
    str[i] = '\0';
}
// --- FUNGSI UTAMA PEMBACAAN FILE ---
void baca_hadiah(Hadiah arrHadiah[], int *jumlahHadiah) {
    FILE *arsip = fopen("thadiah.txt", "r");
    *jumlahHadiah = 0;
    if (arsip != NULL) {
        START(arsip);
        while (!EOP) {
            arrHadiah[*jumlahHadiah].x = baca_angka(arsip);
            if (EOP) break;
            arrHadiah[*jumlahHadiah].y    = baca_angka(arsip);
            baca_string(arsip, arrHadiah[*jumlahHadiah].nama);
            arrHadiah[*jumlahHadiah].skor = baca_angka(arsip);
            (*jumlahHadiah)++;
        }
        fclose(arsip);
    } else {
        printf("File thadiah.txt belum ada atau kosong.\n");
    }
}
void baca_gerak(Gerak arrGerak[], int *jumlahGerak) {
    FILE *arsip = fopen("tgerak.txt", "r");
    *jumlahGerak = 0;
    if (arsip != NULL) {
        START(arsip);
        while (!EOP) {
            arrGerak[*jumlahGerak].x = baca_angka(arsip);
            if (EOP) break;
            arrGerak[*jumlahGerak].y = baca_angka(arsip);
            (*jumlahGerak)++;
        }
        fclose(arsip);
    } else {
        printf("File tgerak.txt belum ada atau kosong.\n");
    }
}
// --- FUNGSI PENULISAN FILE ---
void tulisGerak(Gerak arrGerak[], int *jumlahGerak, int x, int y) {
    baca_gerak(arrGerak, jumlahGerak); // Memanggil fungsi yang diperbarui

    arrGerak[*jumlahGerak].x = x;
    arrGerak[*jumlahGerak].y = y;
    (*jumlahGerak)++;

    FILE *arsip = fopen("tgerak.txt", "w");
    if (arsip != NULL) {
        for (int i = 0; i < *jumlahGerak; i++) {
            fprintf(arsip, "%d %d\n", arrGerak[i].x, arrGerak[i].y);
        }
        fprintf(arsip, "## ##\n");
        fclose(arsip);
        printf("Berhasil mencatat gerak ke koordinat (%d, %d).\n", x, y);
    } else {
        printf("Gagal membuka file tgerak.txt untuk ditulis!\n");
    }
}

void cetakTabelHadiah(Hadiah arrHadiah[], int jumlahHadiah) { 
    printf("Isi hadiah saat ini\n"); 
    printf("------------------------------------------\n"); 
    printf("|%-4s|%-4s|%-6s|%-6s|\n","x","y", "nama", "skor"); //buat header tabell
        for (int i = 0; i< jumlahHadiah; i++) { //loop buatt nyetak tiap baris data hadiah di tabel
            printf("|%-4d|%-4d|%-6s|%-6d|\n", 
        arrHadiah[i].x, 
        arrHadiah[i].y, 
        arrHadiah[i].nama, 
        arrHadiah[i].skor); 
} 
    printf("--------------------------------------------------------\n"); 
}

void tampilkanPapan(Hadiah arrHadiah[], int jumlahHadiah, 
    int kOx, int kOy, int panjang, int lebar, int skor){ //kox itu koordinat posisi (o)x sekarang, koy itu koordinat posisi sekarang (O)y
    int i, j, h, ketemu;

    // ini garis atas papann 
    printf("|");
    for (j = 0; j < lebar; j++) {
        printf("-");
    }
    printf("|\n");

    // ini buat loop baris
    for (i = 0; i < panjang; i++) {
        printf("|");
        // dilanjut ini loop kolomnya
        for (j = 0; j < lebar; j++) {
            // ini buat cek O, klo dia sesuai sm kox & koy cetak
            if (j == kOx && i == kOy) {
                printf("  O  ");
            } else {
                // kalo bukan o, hadiah yang di cek udah ada atau belum, kalo ada cetak nama & skornya
                ketemu = 0;
                for (h = 0; h < jumlahHadiah; h++) {
                    if (arrHadiah[h].x == j && arrHadiah[h].y == i) {
                        printf("%s%d", arrHadiah[h].nama, arrHadiah[h].skor);
                        ketemu = 1;
                        break;
                    }
                }
                // kalo gada langsung cetak spasi
                if (!ketemu) printf("     ");
            }
        }
        printf("|\n"); //ini garis vertikal kanan
    }

    // buat garis bawah papan
    printf("|");
    for (j = 0; j < lebar; j++) printf("-");
    printf("|\n");

    // ini skor O 
    printf("Skor O: %d\n", skor);
}
// Fungsi Simulasi LITE O
void simulasi(Hadiah arrHadiah[], int jumlahHadiah, Gerak arrGerak[], int jumlahGerak, int panjang, int lebar) {
    // Menyimpan total skor yang berhasil dikumpulkan 0
    int skorTotal = 0;
    int dimakan[100];
    
    // Inisialisasi seluruh status hadiah menjadi belum dimakan 
    for(int i = 0; i < jumlahHadiah; i++) {
        dimakan[i] = 0;
    }

    // Menjalankan seluruh gerakan O sesuai isi file satu per satu
    for(int g = 0; g < jumlahGerak; g++) {
        // Mengambil posisi 0 saat langkah ke-g
        int kOx = arrGerak[g].x;
        int kOy = arrGerak[g].y;

        // Mengecek apakah posisi O sama dengan posisi hadiah 
        // Jika sama, hadiah dianggap dimakan 
        for(int h = 0; h < jumlahHadiah; h++) {
            if(dimakan[h] == 0 && arrHadiah[h].x == kOx && arrHadiah[h].y == kOy) {
                // Menambahkan skor hadiah ke total skor
                skorTotal += arrHadiah[h].skor;
                dimakan[h] = 1; // Tandai hadiah telah habis dikonsumsi
            }
        }

        // Membersihkan layar agar memunculkan efek animasi
        system("cls"); // Membersihkan layar terminal Windows untuk animasi
        // Menampilkan posisi 0 saat ini 
        printf("Posisi O : (%d,%d)\n\n", kOx, kOy);
      
        // Mencetak garis batas atas papan
        for(int x = 0; x <= lebar + 2; x++) printf("- ");
        printf("\n");

        // Perulangan untuk mencetak seluruh papan 
        // Perulangan baris (koordinat y)
        for(int y = 0; y <= panjang; y++) {
            printf("| "); // Batas kiri papan

            // Perulangan kolom (koordinat x)
            for(int x = 0; x <= lebar; x++) {
                int tercetak = 0;

                // Cek apakah posisi saat ini ditempati 0
                if(x == kOx && y == kOy) {
                    printf("O ");
                    tercetak = 1;
                }

                // Jika belum ada yang dicetak, cek apakah ada hadiah di posisi tersebut
                if(!tercetak) {
                    for(int h = 0; h < jumlahHadiah; h++) {
                        if(dimakan[h] == 0 && arrHadiah[h].x == x && arrHadiah[h].y == y) {
                            printf("%s%d ", arrHadiah[h].nama, arrHadiah[h].skor);
                            tercetak = 1;
                            break;
                        }
                    }
                }

                // Jika tidak ada 0 maupun hadiah, tampilkan titik sebagai sel kosong 
                if(!tercetak) {
                    printf(". ");
                }
            }
            printf("|\n"); // Cetak batas kanan papan
        }

        // Mencetak garis batas bawah papan
        for(int x = 0; x <= lebar + 2; x++) printf("- ");
        printf("\n");
        // Menampilkan skor sementara 
        printf("\nSkor O : %d\n", skorTotal);

        wait(1); // Efek jeda waktu animasi 1 detik per langkah
    }
}