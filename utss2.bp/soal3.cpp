#include <iostream>
using namespace std;

int main() {
    int n, i, s, j; // Deklarasi variabel

    cout << "Masukan jumlah baris: ";
    cin >> n; // Input jumlah baris

    // Loop untuk setiap baris
    for (i = 1; i <= n; i++) {
        // Loop untuk mencetak spasi
        for (s = i; s < n; s++) 
            cout << " ";
        // Loop untuk mencetak bintang
        for (j = 1; j <= i; j++) 
            cout << "*";
        // Pindah ke baris berikutnya
        cout << "\n";
    }

    return 0;
}