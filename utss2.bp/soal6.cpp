#include <iostream>
using namespace std;

// Deklarasi fungsi
void menu();
void tambah();
void kurang();
void kali();
void bagi();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        cout << "Menu Aritmatika" << endl;
        cout << "1. Tambah" << endl;
        cout << "2. Kurang" << endl;
        cout << "3. Kali" << endl;
        cout << "4. Bagi" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih operasi (1-5): ";
        cin >> choice;

        switch(choice) {
            case 1:
                tambah();
                break;
            case 2:
                kurang();
                break;
            case 3:
                kali();
                break;
            case 4:
                bagi();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (choice != 5);
}

void tambah() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    cout << "Hasil penjumlahan: " << a + b << endl;
}

void kurang() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    cout << "Hasil pengurangan: " << a - b << endl;
}

void kali() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    cout << "Hasil perkalian: " << a * b << endl;
}

void bagi() {
    int a, b;
    cout << "Masukkan angka pertama: ";
    cin >> a;
    cout << "Masukkan angka kedua: ";
    cin >> b;
    if (b != 0) {
        cout << "Hasil pembagian: " << a / b << endl;
    } else {
        cout << "Kesalahan: Pembagian dengan nol tidak diperbolehkan." << endl;
    }
}
