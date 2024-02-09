#include <iostream>
#include <unistd.h>
#include <limits>

using namespace std;

// Fungsi untuk membersihkan buffer input
void clearInputBuffer() {
    cin.clear(); // Menghapus status error dari cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Mengabaikan karakter sampai newline
}

// Fungsi konversi Celsius ke Fahrenheit dengan pointer
void konversiCtoF(float *celsius, float *fahrenheit) {
    *fahrenheit = (*celsius * 9/5) + 32;
}

// Fungsi konversi Fahrenheit ke Celsius dengan pointer
void konversiFtoC(float *fahrenheit, float *celsius) {
    *celsius = (*fahrenheit - 32) * 5/9;
}

// Fungsi konversi Celsius ke Kelvin dengan pointer
void konversiCtoK(float *celsius, float *kelvin) {
    *kelvin = *celsius + 273.15;
}

// Fungsi konversi Fahrenheit ke Kelvin dengan pointer
void konversiFtoK(float *fahrenheit, float *kelvin) {
    *kelvin = (*fahrenheit + 459.67) * 5/9;
}

// Fungsi konversi Kelvin ke Celsius dengan pointer
void konversiKtoC(float *kelvin, float *celsius) {
    *celsius = *kelvin - 273.15;
}

// Fungsi konversi Kelvin ke Fahrenheit dengan pointer
void konversiKtoF(float *kelvin, float *fahrenheit) {
    *fahrenheit = (*kelvin * 9/5) - 459.67;
}

int main() {
    int menu, n;
    char pilih = '\0';

    do {
        cout << ">>>>> Menu Konversi Suhu : <<<<<\n";
        cout << "1. Konversi Celsius ke Fahrenheit\n";
        cout << "2. Konversi Fahrenheit ke Celsius\n";
        cout << "3. Konversi Celsius ke Kelvin\n";
        cout << "4. Konversi Fahrenheit ke Kelvin\n";
        cout << "5. Konversi Kelvin ke Celsius\n";
        cout << "6. Konversi Kelvin ke Fahrenheit\n";
        cout << "0. Keluar\n";
        cout << "Pilih menu (0-6): ";
        while (!(cin >> menu)) {
                cout << "Input tidak valid. Harap masukkan angka.\n";
                clearInputBuffer(); // Bersihkan buffer input
            }

        if (menu >= 1 && menu <= 6) {
            cout << "Masukkan jumlah suhu yang akan dikonversi: ";
            //Validasi apakah input adalah angka
            while (!(cin >> n)) {
                cout << "Input tidak valid. Harap masukkan angka.\n";
                clearInputBuffer(); // Bersihkan buffer input
            }

            float suhuAwal[n], suhuAkhir[n];

            for (int i = 0; i < n; i++) {
                cout << "Masukkan suhu ke-" << i+1 << ": ";
                // Validasi apakah input adalah angka
                while (!(cin >> suhuAwal[i])) {
                    cout << "Input tidak valid. Harap masukkan angka.\n";
                    clearInputBuffer(); // Bersihkan buffer input
                }
            }

            switch (menu) {
                case 1:
                    for (int i = 0; i < n; i++) {
                        konversiCtoF(&suhuAwal[i], &suhuAkhir[i]);
                    }
                    break;
                case 2:
                    for (int i = 0; i < n; i++) {
                        konversiFtoC(&suhuAwal[i], &suhuAkhir[i]);
                    }
                    break;
                case 3:
                    for (int i = 0; i < n; i++) {
                        konversiCtoK(&suhuAwal[i], &suhuAkhir[i]);
                    }
                    break;
                case 4:
                    for (int i = 0; i < n; i++) {
                        konversiFtoK(&suhuAwal[i], &suhuAkhir[i]);
                    }
                    break;
                case 5:
                    for (int i = 0; i < n; i++) {
                        konversiKtoC(&suhuAwal[i], &suhuAkhir[i]);
                    }
                    break;
                case 6:
                    for (int i = 0; i < n; i++) {
                        konversiKtoF(&suhuAwal[i], &suhuAkhir[i]);
                    }
                    break;
                default:
                    cout << "Harap pilih yang ada di menu" << endl;
                    break;
            }

            cout << "\nHasil Konversi:\n";
            for (int i = 0; i < n; i++) {
                switch (menu) {
                    case 1:
                        cout << suhuAwal[i] << " derajat Celcius" << " -> " << suhuAkhir[i] << " derajat Farenheit" << endl;
                        break;
                    case 2:
                        cout << suhuAwal[i] << " derajat Farenheit" << " -> " << suhuAkhir[i] << " derajat Celcius" << endl;
                        break;
                    case 3:
                        cout << suhuAwal[i] << " derajat Celcius" << " -> " << suhuAkhir[i] << " Kelvin" << endl;
                        break;
                    case 4:
                        cout << suhuAwal[i] << " derajat Farenheit" << " -> " << suhuAkhir[i] << " Kelvin" << endl;
                        break;
                    case 5:
                        cout << suhuAwal[i] << " Kelvin" << " -> " << suhuAkhir[i] << " derajat Celcius" << endl;
                        break;
                    case 6:
                        cout << suhuAwal[i] << " Kelvin" << " -> " << suhuAkhir[i] << " derajat Farenheit" << endl;
                        break;
                }
            }
            cout << "\nTerima Kasih, Ingin Melakukan Konversi Lagi? (y/n) ";
            cin >> pilih;
            clearInputBuffer();

            if (pilih == 'Y' || pilih == 'y'){
                system("cls");
                continue; // Kembali ke awal loop
            } else if (pilih != 'N' && pilih != 'n'){
                cout << "Pilihan menu tidak valid. Silakan coba lagi. (System akan reset otomatis dalam 2 detik)\n";
                sleep(2);
                system ("cls");
            } else {
                cout << "\nTerima Kasih, Semoga harimu menyenangkan.\n";
            }
        } else if (menu != 0) {
            cout << "Pilihan menu tidak valid. Silakan coba lagi. (System akan reset otomatis dalam 2 detik)\n";
            sleep(2);
            system ("cls");
        } else {
            cout << "\nTerima Kasih, Semoga harimu menyenangkan.\n";
        }
    } while (pilih != 'n' && pilih != 'N' && menu != 0);

    return 0;
}
