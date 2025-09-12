#include <iostream>
using namespace std;

void ReverseArray(int *arr, int arrSize)
{
    int reversedArr[arrSize];
    int reversedSize = 0;

    // Mereplikasi array asli dari belakang di reversed array
    for (int i = arrSize - 1; i >= 0; i--)
    {
        reversedArr[reversedSize] = arr[i];
        reversedSize++;
    }

    // Menerapkan reversed array ke alamat array asli
    for (int i = 0; i < arrSize; i++)
        arr[i] = reversedArr[i];
}

int main()
{
    string temp;

    int jumlahElemen = 7;
    int primaArr[jumlahElemen];
    int primaSize = 0;

    int cekAngkaPrima = 0;

    // Mengulang proses pengisian elemen array bilangan prima sampai 7 elemen
    while (primaSize < jumlahElemen)
    {
        // Mencoba untuk memasukkan dan menyimpan bilangan prima
        while (true)
        {
            try
            {
                cout << "Masukkan elemen bilangan prima ke-" << primaSize + 1 << " : ";
                getline(cin, temp);

                cekAngkaPrima = stoi(temp);
                break;
            }
            catch (exception &e)
            {
                cerr << "Input angka tidak valid!";
            }
            cout << endl;
        }
        
        // Pastikan bilangan prima di atas lebih dari satu (bilangan faktor 2)
        bool isPrima = (cekAngkaPrima > 1);

        // Jika dapat dibagi dengan angka di bawahnya, maka bukan bilangan prima
        for (int pembagi = 2; pembagi < cekAngkaPrima && (isPrima); pembagi++)
        {
            if (cekAngkaPrima % pembagi == 0)
                isPrima = false;
        }

        // Menambahkan bilangan prima ke array
        if (isPrima)
        {
            primaArr[primaSize] = cekAngkaPrima;
            primaSize++;
        }
        else
        {
            cout << cekAngkaPrima << " bukan bilangan prima!" << endl;
        }
    }

    cout << "Elemen Array Sebelum Dibalik : ";
    for (int i = 0; i < primaSize; i++)
    {
        cout << primaArr[i];
        if (i < primaSize - 1)
            cout << ", ";
        else
            cout << "." << endl;
    }

    ReverseArray(primaArr, primaSize);
    cout << "Elemen Array Setelah Dibalik : ";
    for (int i = 0; i < primaSize; i++)
    {
        cout << primaArr[i];
        if (i < primaSize - 1)
            cout << ", ";
        else
            cout << "." << endl;
    }

    return 0;
}