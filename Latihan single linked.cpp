#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// 1. Mendeklarasikan struktur data nilai mata kuliah
struct NilaiMatkul {
    char nim[10];
    char nama[50];
    char nilai[2];
};

// 2. Mendeklarasikan struktur data elemen
struct Elemen {
    NilaiMatkul kontainer;
    Elemen* next;
};

// 3. Mendeklarasikan list tunggal (single linked list)
struct List {
    Elemen* first;
};

// 4. Mendeklarasikan prosedur createList
void createList(List* L) {
    L->first = nullptr;
}

// 5. Mendeklarasikan fungsi countElement
int countElement(List L) {
    int hasil = 0;
    if (L.first != nullptr) {
        Elemen* bantu = L.first;
        while (bantu != nullptr) {
            hasil += 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

// 6. Mendeklarasikan prosedur addFirst
void addFirst(string nim, string nama, string nilai, List* L) {
    Elemen* baru = new Elemen;
    
    strcpy(baru->kontainer.nim, nim.c_str());
    strcpy(baru->kontainer.nama, nama.c_str());
    strcpy(baru->kontainer.nilai, nilai.c_str());

    if (L->first == nullptr) {
        baru->next = nullptr;
    } else {
        baru->next = L->first;
    }
    L->first = baru;
}

// 7. Mendeklarasikan prosedur addAfter
void addAfter(Elemen* prev, string nim, string nama, string nilai) {
    if (prev != nullptr) {
        Elemen* baru = new Elemen;
        
        strcpy(baru->kontainer.nim, nim.c_str());
        strcpy(baru->kontainer.nama, nama.c_str());
        strcpy(baru->kontainer.nilai, nilai.c_str());

        baru->next = prev->next;
        prev->next = baru;
    }
}

// 8. Mendeklarasikan prosedur addLast
void addLast(string nim, string nama, string nilai, List* L) {
    if (L->first == nullptr) {
        addFirst(nim, nama, nilai, L);
    } else {
        Elemen* last = L->first;
        while (last->next != nullptr) {
            last = last->next;
        }
        addAfter(last, nim, nama, nilai);
    }
}

// 9. Mendeklarasikan prosedur delFirst
void delFirst(List* L) {
    if (L->first != nullptr) {
        Elemen* hapus = L->first;
        if (countElement(*L) == 1) {
            L->first = nullptr;
        } else {
            L->first = L->first->next;
        }
        delete hapus;
    } else {
        cout << "List Kosong" << endl;
    }
}

// 10. Mendeklarasikan prosedur delAfter
void delAfter(Elemen* prev) {
    if (prev != nullptr) {
        Elemen* hapus = prev->next;
        if (hapus != nullptr) {
            prev->next = hapus->next;
            delete hapus;
        }
    }
}

// 11. Mendeklarasikan prosedur delLast
void delLast(List* L) {
    if (L->first != nullptr) {
        if (countElement(*L) == 1) {
            delFirst(L);
        } else {
            Elemen* last = L->first;
            Elemen* before_last = nullptr;
            while (last->next != nullptr) {
                before_last = last;
                last = last->next;
            }
            delAfter(before_last);
        }
    }
}

// 12. Mendeklarasikan prosedur printElement
void printElement(List L) {
    if (L.first != nullptr) {
        Elemen* bantu = L.first;
        int i = 1;
        while (bantu != nullptr) {
            cout << "Elemen ke-" << i << endl;
            cout << "NIM\t: " << bantu->kontainer.nim << endl;
            cout << "Nama\t: " << bantu->kontainer.nama << endl;
            cout << "Nilai\t: " << bantu->kontainer.nilai << endl;
            cout << "-------" << endl;
            bantu = bantu->next;
            i++;
        }
    } else {
        cout << "List Kosong" << endl;
    }
}

// 13. Mendeklarasikan prosedur delAll
void delAll(List* L) {
    while (countElement(*L) > 0) {
        delLast(L);
    }
}

// 14. Mendeklarasikan fungsi utama (main)
int main() {
    List L;
    createList(&L);
    printElement(L);
    cout << "========" << endl;

    addFirst("136", "Nana", "A", &L);
    addFirst("125", "Adrezo", "A", &L);
    addAfter(L.first->next, "135", "Iza", "A");
    addLast("137", "Raxa", "A", &L);
    
    printElement(L);
    cout << "========" << endl;

    delLast(&L);
    delAfter(L.first->next);
    delFirst(&L);
    
    printElement(L);
    cout << "========" << endl;

    return 0;
}