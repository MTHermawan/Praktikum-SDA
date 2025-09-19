#include <iostream>
using namespace std;

struct Penerbangan
{
    string kodePenerbangan;
    string tujuan;
    string status;
};

struct Node
{
    Penerbangan penerbangan;
    Node *next;
};

void TambahJadwal(Node *&head, Node *&tail, int &id, string nim);
void SisipkanJadwal(Node *&head, Node *&tail, int &id, string nim);
void HapusJadwalTerawal(Node *&head);
void UpdateStatusJadwal(Node *&head);
void LihatSemuaJadwal(Node *&head);

int main()
{
    string nama = "Hermawan";
    string nim = "060";
    int id = 0;

    string _temp;
    string pilihanMenu;

    Node *head = nullptr;
    Node *tail = nullptr;

    while (true)
    {
        cout << "========================================" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Sistem Jadwal Penerbangan" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Selamat Datang, " << nama << " (" << nim << ")" << endl;
        cout << endl;
        cout << "> 1. Tambah Jadwal Penerbangan" << endl;
        cout << "> 2. Sisipkan Jadwal Penerbangan" << endl;
        cout << "> 3. Hapus Jadwal Terawal" << endl;
        cout << "> 4. Update Status Penerbangan" << endl;
        cout << "> 5. Daftar Jadwal Penerbangan" << endl;
        cout << "> 0. Keluar" << endl;
        cout << endl;

        cout << "Pilih menu\t: ";
        getline(cin, pilihanMenu);
        cout << endl;

        if (pilihanMenu == "1")
            TambahJadwal(head, tail, id, nim);
        else if (pilihanMenu == "2")
            SisipkanJadwal(head, tail, id, nim);
        else if (pilihanMenu == "3")
            HapusJadwalTerawal(head);
        else if (pilihanMenu == "4")
            UpdateStatusJadwal(head);
        else if (pilihanMenu == "5")
            LihatSemuaJadwal(head);
        else if (pilihanMenu == "0")
            break;
    }
    cout << endl
         << "Program berhasil dihentikan!";
    return 0;
}

void AddLastJadwalNode(Node *&head, Node *&tail, Node *&nodeBaru)
{
    if (head == nullptr)
        head = nodeBaru;
    else
        tail->next = nodeBaru;

    tail = nodeBaru;
}

void AddFirstJadwalNode(Node *&head, Node *&tail, Node *&nodeBaru)
{
    if (head == nullptr)
    {
        head = nodeBaru;
        tail = nodeBaru;
        return;
    }

    nodeBaru->next = head;
    head = nodeBaru;
}

void AddSpecificJadwalNode(Node *&head, Node *&tail, int posisi, Node *&nodeBaru)
{
    string strTemp;
    if (posisi < 1)
    {
        cout << "Posisi node tidak bisa kurang dari 1!" << endl;
        getline(cin, strTemp);
        return;
    }
    else if (posisi == 1)
    {
        return AddFirstJadwalNode(head, tail, nodeBaru);
    }

    Node *temp = head;
    int hitung = 1;
    while (temp != nullptr && hitung < posisi - 1)
    {
        temp = temp->next;
        hitung++;
    }

    if (temp == nullptr)
    {
        cout << "Posiis tidak ditemukan!" << endl;
        getline(cin, strTemp);
    }
    else if (temp->next == nullptr)
    {
        AddLastJadwalNode(head, tail, nodeBaru);
    }
    else
    {
        nodeBaru->next = temp->next;
        temp->next = nodeBaru;
    }
}

void TambahJadwal(Node *&head, Node *&tail, int &id, string nim)
{
    string strTemp;
    string inputTujuan;

    cout << "========================================" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Tambah Jadwal Penerbangan Baru" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Masukkan tujuan penerbangan\t: ";
    getline(cin, inputTujuan);
    cout << endl;

    Node *nodeBaru = new Node();
    nodeBaru->penerbangan.kodePenerbangan = "JT-" + nim + (id > 0 ? "-" + to_string(id) : "");
    nodeBaru->penerbangan.tujuan = inputTujuan;
    nodeBaru->penerbangan.status = "Tepat Waktu";
    nodeBaru->next = nullptr;

    AddLastJadwalNode(head, tail, nodeBaru);

    cout << "Jadwal berhasil ditambahkan!" << endl;
    getline(cin, strTemp);

    id++;
}

void SisipkanJadwal(Node *&head, Node *&tail, int &id, string nim)
{
    string strTemp;
    string inputTujuan;

    cout << "========================================" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Sisipkan Jadwal Penerbangan Baru" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Masukkan tujuan penerbangan\t: ";
    getline(cin, inputTujuan);
    cout << endl;
    
    Node *nodeBaru = new Node();
    nodeBaru->penerbangan.kodePenerbangan = "JT-" + nim + (id > 0 ? "-" + to_string(id) : "");
    nodeBaru->penerbangan.tujuan = inputTujuan;
    nodeBaru->penerbangan.status = "Tepat Waktu";
    nodeBaru->next = nullptr;

    string digitTerakhir = {nim[2]};
    int posisi = stoi(digitTerakhir) + 2;
    AddSpecificJadwalNode(head, tail, posisi, nodeBaru);

    cout << "Jadwal berhasil disisipkan!" << endl;
    getline(cin, strTemp);

    id++;
}

void HapusJadwalTerawal(Node *&head)
{
    string strTemp;
    Node *temp = head;

    if (head == nullptr)
    {
        cout << "Tidak ada data untuk dihapus!" << endl;
        getline(cin, strTemp);
        return;
    }
    char confirmHapus;

    cout << "Apakah Anda yakin ingin menghapus data jadwal terawal? (y/n) ";
    while (tolower(confirmHapus) != 'n' && tolower(confirmHapus) != 'y')
    {
        getline(cin, strTemp);
        confirmHapus = strTemp[0];
    }

    if (tolower(confirmHapus) == 'n')
    {
        cout << "Proses hapus dibatalkan!" << endl;
        getline(cin, strTemp);
        return;
    }

    head = temp->next;

    temp = nullptr;
    delete temp;
}

void UpdateStatusJadwal(Node *&head)
{
    string strTemp;
    string inputKode;
    Node *temp = head;

    cout << "========================================" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Perbarui Status Jadwal Penerbangan" << endl;
    cout << "----------------------------------------" << endl;
    if (head == nullptr)
    {
        cout << "Tidak ada jadwal penerbangan yang tersedia" << endl;
        getline(cin, strTemp);
        return;
    }

    while (temp != nullptr)
    {
        cout << "Kode Penerbangan: " << temp->penerbangan.kodePenerbangan << endl;
        cout << "Tujuan: " << temp->penerbangan.tujuan << endl;
        cout << "Status: " << temp->penerbangan.status << endl;
        temp = temp->next;
        cout << endl;
    }
    cout << endl;

    cout << "Masukkan kode penerbangan untuk diperbarui\t: ";
    getline(cin, inputKode);

    temp = head;
    while (temp != nullptr && temp->penerbangan.kodePenerbangan != inputKode)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Jadwal tidak ditemukan!" << endl;
        getline(cin, strTemp);
        return;
    }

    cout << "Masukkan status jadwal penerbangan terbaru\t: ";
    getline(cin, temp->penerbangan.status);
    cout << endl;

    cout << "Status penerbangan berhasil diperbarui!" << endl;
    getline(cin, strTemp);
}

void LihatSemuaJadwal(Node *&head)
{
    string strTemp;
    Node *temp = head;

    cout << "========================================" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Daftar Jadwal Penerbangan" << endl;
    cout << "----------------------------------------" << endl;

    if (head == nullptr)
    {
        cout << "Tidak ada jadwal penerbangan yang tersedia!" << endl;
        getline(cin, strTemp);
        return;
    }

    while (temp != nullptr)
    {
        cout << "Kode Penerbangan: " << temp->penerbangan.kodePenerbangan << endl;
        cout << "Tujuan: " << temp->penerbangan.tujuan << endl;
        cout << "Status: " << temp->penerbangan.status << endl;
        temp = temp->next;
        cout << endl;
    }

    cout << "Tekan enter untuk melanjutkan..." << endl;;
    getline(cin, strTemp);
}