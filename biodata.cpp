#include <iostream>
#include <string>

using namespace std;

int main() {
    // Mendeklarasikan variabel untuk menyimpan biodata
    string nama;
    int usia;
    string alamat;
    string email;
    string telepon;

    // Menampilkan pesan kepada pengguna
    cout << "Form Biodata" << endl;
    cout << "--------------------" << endl;

    // Mengambil input dari pengguna
    cout << "Masukkan Nama: ";
    getline(cin, nama);

    cout << "Masukkan Usia: ";
    cin >> usia;
    cin.ignore(); 

    cout << "Masukkan Alamat: ";
    getline(cin, alamat);

    cout << "Masukkan Email: ";
    getline(cin, email);

    cout << "Masukkan Telepon: ";
    getline(cin, telepon);

    // Menampilkan biodata yang telah dimasukkan
    cout << "\n Output Biodata Anda" << endl;
    cout << "--------------------" << endl;
    cout << "Nama: " << nama << endl;
    cout << "Usia: " << usia << " tahun" << endl;
    cout << "Alamat: " << alamat << endl;
    cout << "Email: " << email << endl;
    cout << "Telepon: " << telepon << endl;

    return 0;
}
