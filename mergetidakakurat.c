#include <stdio.h>

int main() {
    int n1, n2, i;

    printf("Nama : Muhammad Attar Rahman\n");
    printf("NIM  : 2510514001\n");

    printf("masukan jumlah elemen ke 1 : ");
    scanf("%d", &n1);
    printf("masukan jumlah elemen ke 2 : ");
    scanf("%d", &n2);

    int table1[n1], table2[n2], table3[n1 + n2];

    for (i = 0; i < n1; i++) {
        
        printf("masukan isi ke 1 : ");
        scanf("%d", &table1[i]);
    }
    for (i = 0; i < n2; i++) {
        printf("masukan isi ke 2 : ");
        scanf("%d", &table2[i]);
    }

    for (i = 0; i < n1; i++) {
        table3[i] = table1[i];
    }
    for (i = 0; i < n2; i++) {
        table3[n1 + i] = table2[i];
    }

    printf("Hasil Merge tidak urut:\n");
    for (i = 0; i < (n1 + n2); i++) {
        printf("isi ke 3 : %d \n", table3[i]);
    }

    return 0;
}