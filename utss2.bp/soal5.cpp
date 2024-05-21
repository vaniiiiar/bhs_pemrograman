#include <iostream>
using namespace std;
int main() {
    
    int angka1, angka2;

    cout << "Masukan angka pertama: ";
    cin >> angka1;

    cout << "Masukan angka kedua: ";
   	cin >> angka2;

    
    int penjumlahan = angka1 + angka2;
    int pengurangan = angka1 - angka2;
    int perkalian = angka1 * angka2;
    int pembagian = angka1 / angka2;

    cout << "Penjumlahan: " << penjumlahan << endl;
    cout << "Pengurangan: " << pengurangan << endl;
    cout << "Perkalian: " << perkalian << endl;
    cout << "Pembagian: " << pembagian << endl;

    return 0;
}