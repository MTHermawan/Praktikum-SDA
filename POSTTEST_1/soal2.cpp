#include <iostream>
using namespace std;

int main()
{
    int matriks[3][3] = { {1, 2, 3},
                          {4, 5, 6},
                          {7, 8, 9} };

    int jumlahBarisKedua = 0;
    int panjangKolom = sizeof(matriks[0]) / sizeof(matriks[0][0]);

    for (int i = 0; i < panjangKolom; i++)
    {
        jumlahBarisKedua += matriks[1][i];
    }

    cout << "Jumlah baris kedua matriks adalah " << jumlahBarisKedua;

    return 0;
}