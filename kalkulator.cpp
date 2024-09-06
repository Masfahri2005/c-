#include <iostream>

using namespace std;

// Fungsi untuk kalkulasi
void kalkulator() {
    double num1, num2;
    char operasi;
    double hasil;

    // Menampilkan instruksi
    cout << "Selamat datang di Kalkulator C++!" << endl;
    cout << "Masukkan operasi matematika dalam format: angka1 operator angka2" << endl;
    cout << "Contoh: 5 + 3 atau 10 / 2" << endl;

    // Meminta input dari pengguna
    cout << "Masukkan perhitungan: ";
    cin >> num1 >> operasi >> num2;

    // Melakukan perhitungan berdasarkan operator
    switch(operasi) {
        case '+':
            hasil = num1 + num2;
            cout << "Hasil: " << hasil << endl;
            break;
        case '-':
            hasil = num1 - num2;
            cout << "Hasil: " << hasil << endl;
            break;
        case '*':
            hasil = num1 * num2;
            cout << "Hasil: " << hasil << endl;
            break;
        case '/':
            if (num2 != 0) {
                hasil = num1 / num2;
                cout << "Hasil: " << hasil << endl;
            } else {
                cout << "Error: Tidak bisa membagi dengan nol!" << endl;
            }
            break;
        default:
            cout << "Operator tidak valid. Gunakan +, -, *, atau /." << endl;
    }
}

int main() {
    char ulangi;

    do {
        kalkulator();
        cout << "Ingin melakukan perhitungan lagi? (y/n): ";
        cin >> ulangi;
    } while (ulangi == 'y' || ulangi == 'Y');

    cout << "Terima kasih telah menggunakan kalkulator ini!" << endl;
    return 0;
}
