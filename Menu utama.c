#include <stdio.h>

int main() {
    int pilihan;

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

                break;
            case 2:
            
                break;
            case 3:
            
                break;
            case 4:
                
                break;
            default:
                printf("Pilihan tidak valid. Silakan masukkan angka 1-4.\n");
        }

    } while (pilihan != 4);

    return 0;
}
