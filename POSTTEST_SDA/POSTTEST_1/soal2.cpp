#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string temp;
    int matriks[3][3];

    int jumlahBarisKedua = 0;
    int panjangBaris = sizeof(matriks) / sizeof(matriks[0]);
    int panjangKolom = sizeof(matriks[0]) / sizeof(matriks[0][0]);

    // Menginputkan angka matriks
    for (int i = 0; i < panjangBaris; i++)
    {
        for (int j = 0; j < panjangKolom; j++)
        {
            int nilai = 0;
            int urutanElemen = ((i * panjangKolom) + j) + 1;
            while (true)
            {
                try
                {
                    cout << "Masukkan nilai ke-" << urutanElemen << " : ";
                    getline(cin, temp);

                    nilai = stoi(temp);
                    break;
                }
                catch (exception &e)
                {
                    cerr << "Input angka tidak valid!";
                }
                cout << endl << endl;
            }
            matriks[i][j] = nilai;
        }
    }
    cout << "------------------------------" << endl;

    // Melakukan penjumlahan kolom pada elemen baris kedua matriks
    for (int i = 0; i < panjangKolom; i++)
        jumlahBarisKedua += matriks[1][i];

    // Menampilkan matriks
    for (int i = 0; i < panjangBaris; i++)
    {
        for (int j = 0; j < panjangKolom; j++)
        {
            int digitBaris = 0;
            for (int k = 0; k < panjangBaris; k++)
            {
                int digitElemen = to_string(matriks[k][j]).length();
                if (digitElemen > digitBaris)
                    digitBaris = digitElemen;
            }

            cout << setw(digitBaris) << left << matriks[i][j];
            if (j < panjangKolom - 1)
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Menampilkan hasil penjumlahan
    cout << "Hasil penjumlahan kolom pada elemen baris kedua matriks adalah " << jumlahBarisKedua;

    return 0;
}