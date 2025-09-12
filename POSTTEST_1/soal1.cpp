#include <iostream>
using namespace std;

void ReverseArray(int *arr, int arrSize)
{
    int reversedArr[arrSize];
    int reversedSize = 0;

    for (int i = arrSize - 1; i >= 0; i--)
    {
        reversedArr[reversedSize] = arr[i];
        reversedSize++;
    }

    for (int i = 0; i < arrSize; i++)
        arr[i] = reversedArr[i];
}

int main()
{
    int elementPrima = 7;
    int primaArr[elementPrima];
    int primaSize = 0;

    int cekAngkaPrima = 0;

    while (primaSize < elementPrima)
    {
        int pembagi = 1;
        bool isPrima;

        for (int pembagi = 1; pembagi < cekAngkaPrima; pembagi++)
        {
            isPrima = false;
            if (pembagi > 1)
                isPrima = true;
            else
                continue;

            if (cekAngkaPrima % pembagi == 0)
            {
                isPrima = false;
                break;
            }
        }

        if (isPrima)
        {
            primaArr[primaSize] = cekAngkaPrima;
            primaSize++;
        }

        cekAngkaPrima++;
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