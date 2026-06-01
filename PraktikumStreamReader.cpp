#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

// Konstanta untuk nama file database
const string NAMA_FILE = "gudang.txt";

class TokoElektronik {
private:
    // Atribut private berupa array kapasitas 3 elemen untuk representasi etalase
    array<string, 3> etalase;

public:
    TokoElektronik() {
        etalase[0] = "Laptop Lenovo LOQ";
        etalase[1] = "Laptop HP Victus";
        etalase[2] = "Smartphone Poco F7 Pro";
    }
    string ambilProduk(size_t nomorRak) {
        try {
            // Wajib menggunakan fungsi .at() untuk mengakses indeks array
            return etalase.at(nomorRak);
        } catch (const out_of_range& e) {
            // Menangkap error bawaan out_of_range dan melempar (throw) pesan error kustom
            string pesanError = "Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!";
            throw runtime_error(pesanError);
        }
    }
    
    void initFile() {
    ifstream file(NAMA_FILE);
    if (!file) {
        ofstream newFile(NAMA_FILE);
        newFile.close();
    }
}

void readGudang() {
    ifstream file(NAMA_FILE);
    string line;
    int no = 1;
    bool isEmpty = true;
    
    cout << "\n=== DAFTAR BARANG DI GUDANG (.txt) ===" << endl;
    while (getline(file, line)) {
        cout << no++ << ". " << line << endl;
        isEmpty = false;
    }

    if (isEmpty) {
        cout << "(Data gudang kosong. Silakan gunakan menu Create.)" << endl;
    }
    cout << "======================================\n" << endl;
    file.close();
}

void createBarang() {
    ofstream file(NAMA_FILE, ios::app);
    string namaBarang;
    cout << "Masukkan nama barang elektronik baru: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, namaBarang);
    
    file << namaBarang << endl;
    cout << "[SUKSES] Barang berhasil ditambahkan ke gudang!\n";
    file.close();
}