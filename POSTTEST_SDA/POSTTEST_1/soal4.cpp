#include <iostream>
using namespace std;

void TukarNilai(int &nilai1, int &nilai2)
{
    int temp = nilai1;
    nilai1 = nilai2;
    nilai2 = temp;
}

int InputAngka(string prompt)
{
    string temp;
    int angka;
    while (true)
    {
        try
        {
            cout << prompt;
            getline(cin, temp);
            angka = stoi(temp);
            break;
        }
        catch (exception &e)
        {
            cerr << "Input angka tidak valid!";
        }
        cout << endl;
    }
    return angka;
}

int main()
{
    string temp;
    int nilai1 = InputAngka("Masukkan nilai ke-1: ");
    int nilai2 = InputAngka("Masukkan nilai ke-2: ");

    cout << "------------------------------" << endl;
    cout << "Nilai sebelum ditukar: " << endl;
    cout << "Nilai variabel ke-1 (" << &nilai1 << ")\t: " << nilai1 << endl;
    cout << "Nilai variabel ke-2 (" << &nilai2 << ")\t: " << nilai2 << endl
         << endl;

    TukarNilai(nilai1, nilai2);
    cout << "Nilai setelah ditukar: " << endl;
    cout << "Nilai variabel ke-1 (" << &nilai1 << ")\t: " << nilai1 << endl;
    cout << "Nilai variabel ke-2 (" << &nilai2 << ")\t: " << nilai2 << endl;

    return 0;
}