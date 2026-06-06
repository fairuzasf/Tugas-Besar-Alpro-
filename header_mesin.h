#ifndef header_mesin_h
#define header_mesin_h

#include <stdio.h>
#include <stdbool.h>
#include <time.h>

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
          
int baca_angka(FILE *arsip);	//ini buat baca dr file karakter perkarakter angka jadi satu. ex: inputan buat x itu 1,0 dijadiin 10
void baca_string(FILE *arsip, char *s); //klo ini buat baca dr file karakter huruf ex: a,a jadi aa

#endif