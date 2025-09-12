#include <iostream>
using namespace std;

void TukarNilai(int &nilai1, int &nilai2)
{
    int temp = nilai1;
    nilai1 = nilai2;
    nilai2 = temp;
}

int main()
{
    string temp;
    int nilai1 = 6;
    int nilai2 = 8;

    cout << "Nilai sebelum ditukar: " << endl;
    cout << "Nilai 1\t: " << nilai1 << endl;
    cout << "Nilai 2\t: " << nilai2 << endl << endl;

    TukarNilai(nilai1, nilai2);
    cout << "Nilai setelah ditukar: " << endl;
    cout << "Nilai 1\t: " << nilai1 << endl;
    cout << "Nilai 2\t: " << nilai2 << endl;

    return 0;
}