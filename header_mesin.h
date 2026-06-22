#ifndef header_mesin_h
#define header_mesin_h

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct { 	//Pake typedef agar di main tinggal panggil namanya saja ex: Hadiah, ini biar tipe data beda tp bisa jd satu yaa
    int x;
    int y;
    char nama[50];
    int skor;
} Hadiah;

typedef struct {
int x;
int y;
} Gerak;

void START(FILE *arsip);  	//START buat nnti program mulai baca karakter awal 
void ADV(FILE *arsip);	  	//ADV buat maju satu karakter ke depan jika udah baca file sebelumnya
void wait(float x);		// deklarasi fungsi wait 
void AbaikanBlank(FILE *arsip); // fungsi untuk mengabaikan karakter yang kosong
void baca_hadiah(Hadiah arrHadiah[], int *jumlahHadiah); // fungsi untuk membaca hadiah
void baca_gerak(Gerak arrGerak[], int *jumlahGerak); // fungsi untuk membaca gerak
void tulisGerak(Gerak arrGerak[], int *jumlahGerak, int x, int y); // fungsi untuk menyimpan inputan gerak
void cetakTabelHadiah(Hadiah arrHadiah[], int jumlahHadiah); //fungsi menampilkan data hadiah
void tampilkanPapan(Hadiah arrHadiah[], int jumlahHadiah,  
     int kOx, int kOy, int panjang, int lebar, int skor);   //fungsi untuk menampilkan papan
void animasiMakan(Hadiah arrHadiah[], int *jumlahHadiah, int kOx, int kOy, int *skor);
void simulasi(Hadiah arrHadiah[], int *jumlahHadiah, Gerak arrGerak[], int jumlahGerak, int panjang, int lebar, int *skor);

int baca_angka(FILE *arsip);	//ini buat baca dr file karakter perkarakter angka jadi satu. ex: inputan buat x itu 1,0 dijadiin 10
void baca_string(FILE *arsip, char *s); //klo ini buat baca dr file karakter huruf ex: a,a jadi aa

#define RESET "\033[0m"
#define MERAH "\033[31m"
#define BIRU  "\033[34m"

#endif