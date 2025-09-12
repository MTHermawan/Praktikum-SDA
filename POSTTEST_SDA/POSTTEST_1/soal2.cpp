#include <iostream>
using namespace std;

int main()
{
    int matriks[3][3] = { {1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9} };

    int jumlahBarisKedua = 0;
    int panjangBaris = sizeof(matriks) / sizeof(matriks[0]);
    int panjangKolom = sizeof(matriks[0]) / sizeof(matriks[0][0]);

    for (int i = 0; i < panjangKolom; i++)
        jumlahBarisKedua += matriks[1][i];
    
    for (int i = 0; i < panjangBaris; i++)
    {
        for (int j = 0; j < panjangKolom; j++)
        {
            cout << matriks[i][j];
            if (j < panjangKolom - 1)
                cout << " ";
        }
        cout << endl;
    }

    cout << "Hasil penjumlahan baris kedua matriks di atas adalah " << jumlahBarisKedua;

    return 0;
}