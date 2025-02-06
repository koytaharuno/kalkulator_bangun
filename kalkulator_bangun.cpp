#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

// Struct untuk menyimpan data bangun
struct Bangun
{
    string nama;
    float hasil;
    string input_values; // Menyimpan nilai yang diinput user
};

// Fungsi untuk menyimpan hasil ke file
void simpanHasil(const Bangun &bangun)
{
    ofstream file("riwayat_perhitungan.txt", ios::app);
    if (file.is_open())
    {
        file << fixed << setprecision(2);
        file << "Perhitungan: " << bangun.nama << " - Input: " << bangun.input_values << " - Hasil: " << bangun.hasil << endl;
        file.close();
    }
    else
    {
        cout << "Gagal membuka file untuk menyimpan hasil!" << endl;
    }
}

// Fungsi untuk menghitung luas persegi
float luasPersegi(float *sisi)
{
    return (*sisi) * (*sisi);
}

// Fungsi untuk menghitung luas segitiga
float luasSegitiga(float *alas, float *tinggi)
{
    return 0.5 * (*alas) * (*tinggi);
}

// Fungsi untuk menghitung luas lingkaran
float luasLingkaran(float *radius)
{
    return M_PI * (*radius) * (*radius);
}

// Fungsi untuk menghitung volume kubus
float volumeKubus(float *sisi)
{
    return (*sisi) * (*sisi) * (*sisi);
}

// Fungsi untuk menghitung volume balok
float volumeBalok(float *panjang, float *lebar, float *tinggi)
{
    return (*panjang) * (*lebar) * (*tinggi);
}

// Fungsi untuk menghitung volume bola
float volumeBola(float *radius)
{
    return (4.0 / 3.0) * M_PI * pow(*radius, 3);
}

int main()
{
    string rumus[] = {
        "1. Luas Persegi",
        "2. Luas Segitiga",
        "3. Luas Lingkaran",
        "4. Volume Kubus",
        "5. Volume Balok",
        "6. Volume Bola"};

    int pilihan;
    char ulang;

    do
    {
        system("cls");
        cout << "\n=== Kalkulator Bangun Datar dan Ruang ===\n";
        for (const string &r : rumus)
        {
            cout << r << endl;
        }

        cout << "\nPilih rumus yang ingin dihitung (1-6): ";
        cin >> pilihan;
        Bangun bangun;
        stringstream input_stream;

        switch (pilihan)
        {
        case 1:
        {
            float sisi;
            cout << "Masukkan panjang sisi persegi: ";
            cin >> sisi;
            bangun.nama = "Luas Persegi";
            input_stream << "Sisi = " << fixed << setprecision(2) << sisi;
            bangun.input_values = input_stream.str();
            bangun.hasil = luasPersegi(&sisi);
            break;
        }
        case 2:
        {
            float alas, tinggi;
            cout << "Masukkan alas segitiga: ";
            cin >> alas;
            cout << "Masukkan tinggi segitiga: ";
            cin >> tinggi;
            bangun.nama = "Luas Segitiga";
            input_stream << "Alas = " << fixed << setprecision(2) << alas << ", Tinggi = " << tinggi;
            bangun.input_values = input_stream.str();
            bangun.hasil = luasSegitiga(&alas, &tinggi);
            break;
        }
        case 3:
        {
            float radius;
            cout << "Masukkan jari-jari lingkaran: ";
            cin >> radius;
            bangun.nama = "Luas Lingkaran";
            input_stream << "Jari-jari = " << fixed << setprecision(2) << radius;
            bangun.input_values = input_stream.str();
            bangun.hasil = luasLingkaran(&radius);
            break;
        }
        case 4:
        {
            float sisi;
            cout << "Masukkan panjang sisi kubus: ";
            cin >> sisi;
            bangun.nama = "Volume Kubus";
            input_stream << "Sisi = " << fixed << setprecision(2) << sisi;
            bangun.input_values = input_stream.str();
            bangun.hasil = volumeKubus(&sisi);
            break;
        }
        case 5:
        {
            float panjang, lebar, tinggi;
            cout << "Masukkan panjang balok: ";
            cin >> panjang;
            cout << "Masukkan lebar balok: ";
            cin >> lebar;
            cout << "Masukkan tinggi balok: ";
            cin >> tinggi;
            bangun.nama = "Volume Balok";
            input_stream << "Panjang = " << fixed << setprecision(2) << panjang << ", Lebar = " << lebar << ", Tinggi = " << tinggi;
            bangun.input_values = input_stream.str();
            bangun.hasil = volumeBalok(&panjang, &lebar, &tinggi);
            break;
        }
        case 6:
        {
            float radius;
            cout << "Masukkan jari-jari bola: ";
            cin >> radius;
            bangun.nama = "Volume Bola";
            input_stream << "Jari-jari = " << fixed << setprecision(2) << radius;
            bangun.input_values = input_stream.str();
            bangun.hasil = volumeBola(&radius);
            break;
        }
        default:
            cout << "Pilihan tidak valid. Tekan Enter untuk melanjutkan..." << endl;
            cin.ignore();
            cin.get();
            continue;
        }

        cout << bangun.nama << " : " << bangun.hasil << endl;
        simpanHasil(bangun);

        cout << "\nIngin menghitung lagi? (y/n): ";
        cin >> ulang;
    } while (ulang == 'y' || ulang == 'Y');

    cout << "\nTerima kasih telah menggunakan kalkulator!\n";
    return 0;
}
