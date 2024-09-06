#include <iostream>
#include <vector>

using namespace std;

// Fungsi untuk menampilkan papan permainan
void tampilkanPapan(const vector<vector<char>>& papan) {
    cout << " " << papan[0][0] << " | " << papan[0][1] << " | " << papan[0][2] << endl;
    cout << "-----------" << endl;
    cout << " " << papan[1][0] << " | " << papan[1][1] << " | " << papan[1][2] << endl;
    cout << "-----------" << endl;
    cout << " " << papan[2][0] << " | " << papan[2][1] << " | " << papan[2][2] << endl;
}

// Fungsi untuk memeriksa apakah ada pemenang
bool cekPemenang(const vector<vector<char>>& papan, char pemain) {
    // Cek baris dan kolom
    for (int i = 0; i < 3; ++i) {
        if ((papan[i][0] == pemain && papan[i][1] == pemain && papan[i][2] == pemain) ||
            (papan[0][i] == pemain && papan[1][i] == pemain && papan[2][i] == pemain)) {
            return true;
        }
    }
    
    // Cek diagonal
    if ((papan[0][0] == pemain && papan[1][1] == pemain && papan[2][2] == pemain) ||
        (papan[0][2] == pemain && papan[1][1] == pemain && papan[2][0] == pemain)) {
        return true;
    }
    return false;
}

// Fungsi untuk memeriksa apakah papan penuh
bool papanPenuh(const vector<vector<char>>& papan) {
    for (const auto& baris : papan) {
        for (char cell : baris) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> papan(3, vector<char>(3, ' '));
    char pemain = 'X';
    int baris, kolom;

    while (true) {
        tampilkanPapan(papan);
        cout << "Giliran Pemain " << pemain << ". Masukkan baris dan kolom (0, 1, 2): ";
        cin >> baris >> kolom;

        // Validasi input
        if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2 || papan[baris][kolom] != ' ') {
            cout << "Input tidak valid. Coba lagi." << endl;
            continue;
        }

        papan[baris][kolom] = pemain;

        // Cek apakah pemain menang
        if (cekPemenang(papan, pemain)) {
            tampilkanPapan(papan);
            cout << "Selamat! Pemain " << pemain << " menang!" << endl;
            break;
        }

        // Cek apakah papan penuh
        if (papanPenuh(papan)) {
            tampilkanPapan(papan);
            cout << "Permainan berakhir. Tidak ada pemenang!" << endl;
            break;
        }

        // Ganti giliran pemain
        pemain = (pemain == 'X') ? 'O' : 'X';
    }

    return 0;
}
