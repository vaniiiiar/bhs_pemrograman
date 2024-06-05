#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // untuk format Rupiah

using namespace std;

// Definisikan kelas Produk
class Produk {
public:
    string nama;
    double harga;
    int stok;

    // Konstruktor
    Produk(string n, double h, int s) : nama(n), harga(h), stok(s) {}
};

// Definisikan kelas KeranjangBelanja
class KeranjangBelanja {
public:
    vector<Produk> barang;

    // Fungsi untuk menambahkan produk ke dalam keranjang
    void tambahProduk(const Produk& produk) {
        barang.push_back(produk);
        cout << "Menambahkan " << produk.nama << " ke dalam keranjang." << endl;
    }

    // Fungsi untuk melihat isi keranjang belanja
    void lihatKeranjang() {
        cout << "Isi keranjang belanja:" << endl;
        for (const auto& item : barang) {
            cout << item.nama << " - Rp." << fixed << setprecision(2) << item.harga << endl;
        }
    }

    // Fungsi untuk menghitung total harga belanja
    double getTotal() {
        double total = 0;
        for (const auto& item : barang) {
            total += item.harga;
        }
        return total;
    }
};

// Fungsi untuk menampilkan menu utama aplikasi
void tampilkanMenuUtama() {
    cout << "Selamat datang di aplikasi Uniqlo Fashion!" << endl;
    cout << "Silakan pilih menu yang Anda inginkan:" << endl;
    cout << "1. Lihat Produk" << endl;
    cout << "2. Tambah Produk ke Keranjang" << endl;
    cout << "3. Lihat Keranjang Belanja" << endl;
    cout << "4. Checkout" << endl;
    cout << "5. Keluar" << endl;
}

// Fungsi untuk menampilkan daftar produk
void lihatProduk(const vector<Produk>& produk) {
    cout << "Produk yang tersedia:" << endl;
    for (size_t i = 0; i < produk.size(); ++i) {
        cout << i + 1 << ". " << produk[i].nama << " - Rp." << fixed << setprecision(2) << produk[i].harga << endl;
    }
}

// Fungsi untuk memilih produk
Produk pilihProduk(const vector<Produk>& produk) {
    int pilihan;
    cout << "Masukkan nomor produk yang ingin Anda tambahkan ke keranjang: ";
    cin >> pilihan;

    if (pilihan > 0 && pilihan <= produk.size()) {
        return produk[pilihan - 1];
    } else {
        cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        return pilihProduk(produk);
    }
}

// Fungsi untuk checkout
void checkout(KeranjangBelanja& keranjang) {
    keranjang.lihatKeranjang();
    cout << "Total: Rp." << fixed << setprecision(2) << keranjang.getTotal() << endl;
    cout << "Terima kasih telah berbelanja di Uniqlo Fashion!" << endl;
}

int main() {
    // Inisialisasi produk Uniqlo
    vector<Produk> produkUniqlo = {
        Produk("Kemeja Slim Fit", 299000.0, 20),
        Produk("Celana Chino", 399000.0, 15),
        Produk("Kaos Polos", 99000.0, 30)
    };

    // Inisialisasi keranjang belanja
    KeranjangBelanja keranjang;

    int pilihanMenu;

    do {
        // Tampilkan menu utama
        tampilkanMenuUtama();

        // Ambil input pengguna
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                // Menu untuk melihat produk
                lihatProduk(produkUniqlo);
                break;
            case 2:
                // Menu untuk menambah produk ke keranjang
                lihatProduk(produkUniqlo);
                {
                    Produk produkDipilih = pilihProduk(produkUniqlo);
                    keranjang.tambahProduk(produkDipilih);
                }
                break;
            case 3:
                // Menu untuk melihat keranjang belanja
                keranjang.lihatKeranjang();
                break;
            case 4:
                // Menu untuk checkout
                checkout(keranjang);
                break;
            case 5:
                // Keluar dari program
                cout << "Terima kasih telah menggunakan aplikasi Uniqlo Fashion. Sampai jumpa lagi!." << endl;
                cout << "PESANAN KAMU AKAN DI KIRIM SECEPATNYA " << endl;
                break;
            default:
                // Jika pilihan tidak valid
                cout << "Pilihan tidak valid, silakan coba lagi." << endl;
                break;
        }
    } while (pilihanMenu != 5);

    return 0;
}