#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
};

void SortAscendingMahasiswa(Mahasiswa *mhs, int sizeMahasiswa)
{
    for (int i = 0; i < sizeMahasiswa; i++)
    {
        Mahasiswa key = mhs[i];
        int j = i - 1;

        while (j >= 0 && mhs[j].ipk > key.ipk)
        {
            mhs[j + 1] = mhs[j];
            j--;
        }
        mhs[j+1] = key;
    }
    
}

int main()
{
    Mahasiswa dataMahasiswa[4];
    int sizeDataMahasiswa = 4;

    // Data Mahasiswa yang sudah didefinisikan
    dataMahasiswa[0] = {"Trigusni", "26091D06060", 3.65};
    dataMahasiswa[1] = {"Hermawan", "2409106060", 3.43};
    dataMahasiswa[2] = {"Much", "2409106999", 3.99};
    dataMahasiswa[3] = {"Budi", "2409106000", 3.33};
    
    cout << "Data Mahasiswa sebelum diurutkan: " << endl;
    for (int i = 0; i < sizeDataMahasiswa; i++)
    {
        cout << i+1 << ".";
        cout << "\tNama\t: " << dataMahasiswa[i].nama << endl;
        cout << "\tNIM\t: " << dataMahasiswa[i].nim << endl;
        cout << "\tIPK\t: " << dataMahasiswa[i].ipk << endl;
    }
    cout << "------------------------------" << endl;
    
    SortAscendingMahasiswa(dataMahasiswa, sizeDataMahasiswa);
    cout << "Data Mahasiswa setelah diurutkan: " << endl;
    for (int i = 0; i < sizeDataMahasiswa; i++)
    {
        cout << i+1 << ". ";
        cout << "\tNama\t: " << dataMahasiswa[i].nama << endl;
        cout << "\tNIM\t: " << dataMahasiswa[i].nim << endl;
        cout << "\tIPK\t: " << dataMahasiswa[i].ipk << endl;
    }
    cout << "------------------------------" << endl;

    return 0;
}