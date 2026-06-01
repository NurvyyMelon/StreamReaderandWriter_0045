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