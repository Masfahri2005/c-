#include <iostream>
using namespace std;

// fungsi untuk menambahkan rata rata nilai
double hitungRataRata(int nilai[], int jumlahMahasiswa){
    int total = 0;
    for (int i = 0; i < jumlahMahasiswa; i++){
        total += nilai[i];
    }
    return static_cast<double>(total) /jumlahMahasiswa;
}

int main(){
    int jumlahMahasiswa;

    // input jumlah mahasiswa
    cout << "Masukan Jumlah Mahasiswa :";
    cin >> jumlahMahasiswa;

    // array untuk menyimpan sebuah nilai dari mahasiswa
    int nilai[jumlahMahasiswa];

    // input nilai mahasiswa
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i + 1 << ": ";
        cin >> nilai[i];
    }

    // perhitungan rata rata nilai mahasiswa
    double rataRata = hitungRataRata(nilai, jumlahMahasiswa);

    // tampilkan rata rata nilai mahasiswa
    cout << "Rata-rata Nilai Mahasiswa: " << rataRata << endl;
}