#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi kontak
struct Kontak {
    string nama;
    string nomor;
    string email;
};

// Fungsi untuk menampilkan semua kontak
void tampilkanKontak(const vector<Kontak>& daftarKontak) {
    if (daftarKontak.empty()) {
        cout << "Belum ada kontak yang disimpan." << endl;
        return;
    }

    cout << "Daftar Kontak:" << endl;
    for (size_t i = 0; i < daftarKontak.size(); ++i) {
        cout << i + 1 << ". Nama: " << daftarKontak[i].nama << ", Nomor: " << daftarKontak[i].nomor << ", Email: " << daftarKontak[i].email << endl;
    }
}

// Fungsi untuk menambah kontak baru
void tambahKontak(vector<Kontak>& daftarKontak) {
    Kontak kontakBaru;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, kontakBaru.nama);
    cout << "Masukkan Nomor Telepon: ";
    getline(cin, kontakBaru.nomor);
    cout << "Masukkan Email: ";
    getline(cin, kontakBaru.email);

    daftarKontak.push_back(kontakBaru);
    cout << "Kontak berhasil ditambahkan!" << endl;
}

// Fungsi untuk mengedit kontak
void editKontak(vector<Kontak>& daftarKontak) {
    if (daftarKontak.empty()) {
        cout << "Belum ada kontak yang bisa diedit." << endl;
        return;
    }

    int index;
    tampilkanKontak(daftarKontak);
    cout << "Masukkan nomor kontak yang ingin diedit: ";
    cin >> index;

    if (index < 1 || index > daftarKontak.size()) {
        cout << "Kontak tidak ditemukan." << endl;
        return;
    }

    Kontak& kontak = daftarKontak[index - 1];
    cout << "Mengedit kontak: " << kontak.nama << endl;

    cout << "Masukkan Nama baru (kosongkan jika tidak diubah): ";
    cin.ignore();
    string namaBaru;
    getline(cin, namaBaru);
    if (!namaBaru.empty()) {
        kontak.nama = namaBaru;
    }

    cout << "Masukkan Nomor baru (kosongkan jika tidak diubah): ";
    string nomorBaru;
    getline(cin, nomorBaru);
    if (!nomorBaru.empty()) {
        kontak.nomor = nomorBaru;
    }

    cout << "Masukkan Email baru (kosongkan jika tidak diubah): ";
    string emailBaru;
    getline(cin, emailBaru);
    if (!emailBaru.empty()) {
        kontak.email = emailBaru;
    }

    cout << "Kontak berhasil diedit!" << endl;
}

// Fungsi untuk menghapus kontak
void hapusKontak(vector<Kontak>& daftarKontak) {
    if (daftarKontak.empty()) {
        cout << "Belum ada kontak yang bisa dihapus." << endl;
        return;
    }

    int index;
    tampilkanKontak(daftarKontak);
    cout << "Masukkan nomor kontak yang ingin dihapus: ";
    cin >> index;

    if (index < 1 || index > daftarKontak.size()) {
        cout << "Kontak tidak ditemukan." << endl;
        return;
    }

    daftarKontak.erase(daftarKontak.begin() + (index - 1));
    cout << "Kontak berhasil dihapus!" << endl;
}

// Fungsi utama
int main() {
    vector<Kontak> daftarKontak;
    int pilihan;

    do {
        cout << "\n--- Manajer Kontak ---" << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Tampilkan Semua Kontak" << endl;
        cout << "3. Edit Kontak" << endl;
        cout << "4. Hapus Kontak" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahKontak(daftarKontak);
                break;
            case 2:
                tampilkanKontak(daftarKontak);
                break;
            case 3:
                editKontak(daftarKontak);
                break;
            case 4:
                hapusKontak(daftarKontak);
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}
