#include header_mesin.h

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

