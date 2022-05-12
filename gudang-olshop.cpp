//Gudang Online Shop
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int menuPrd(); void tambahPrd(); void tampilPrd(); void ubahPrd(); void hapusPrd();

struct dataProduk
{
	string nama;
	string merk;
	string stok;
	int harga;
};
dataProduk produk[100];

struct dataPesanan
{
	string kodePesan;
	int tglPesan;
	string pemesan;
	string namaBarang;
	enum status { dikemas, terkemas, dikirim, diterima } check;
	int tglKirim;
	int tglTerima;
};
dataPesanan pesanan[1];

int hitung = 0;

int main(){
    while (true)
    {
        int select = menuPrd();
		if (select == 1)
            tambahPrd();
        else if (select == 2)
            tampilPrd();
        else if (select == 3)
            ubahPrd();
		else if (select == 4)
			break;
	}
}
int menuPrd()

{
	system("cls");
    int sel;
	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "|                            Produk                            |\n";
	cout << "[==============================================================]\n\n";
	cout << " Menu Utama\n\n";
	cout << " [1] Tambahkan Produk\n";
	cout << " [2] Tampilkan Produk\n";
	cout << " [3] Ubah Produk\n";
	cout << " [4] Keluar\n\n";
	cout << " Pilih	: ";

	cin>>sel;
	return sel;
}

void tambahPrd()
{
	system("cls");
	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "|                        Tambah Produk                         |\n";
	cout << "[==============================================================]\n\n";
	cout << " Tambahkan Produk\n\n";
	cout << " Nama Produk : ";
	cin.ignore(); getline(cin, produk[hitung].nama);
	cout << " Merk Produk : ";
	getline(cin, produk[hitung].merk);
	cout << " Stok Produk : ";
	getline(cin, produk[hitung].stok);
	cout << " Harga Produk : ";
	cin >> produk[hitung].harga;

	++hitung;
}

void tampilPrd()
{
    system("cls");
    cout << "[==============================================================]\n";
    cout << "|                      Gudang Online Shop                      |\n";
    cout << "|                         Isi Produk                           |\n";
    cout << "[==============================================================]\n\n";
    cout << "[==============================================================]\n";
	cout << setw(5) << "| No.";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(15) << "Stok Produk";
	cout << setw(11) << "Harga" <<"  | ";
	cout << endl;
    cout << "[==============================================================]\n";

    for(int i = 0; i < hitung; i++){
        cout << "|" << setw(4) << i+1;
        cout << setw(15) << produk[i].nama;
        cout << setw(15) << produk[i].merk;
        cout << setw(15) << produk[i].stok;
        cout << setw(7) << "Rp. " << produk[1].harga;
        cout << setw(7) << "| "<< endl;
		cout << "[==============================================================]\n";
        }
    system("pause");
}

void ubahPrd()
{
    int a,b;
    system("cls");
    cout << "[==============================================================]\n";
    cout << "|                      Gudang Online Shop                      |\n";
    cout << "|                         Ubah Produk                          |\n";
    cout << "[==============================================================]\n\n";
    cout << " Urutan produk yang ingin diedit	: ";
	cin >> a;
	cin.ignore(1, '\n');

	b = a - 1;

	if (b < hitung)
	{
		cout << "\n Nama Produk : ";
		getline(cin, produk[b].nama);
		cout << " Merk Produk : ";
		getline(cin, produk[b].merk);
		cout << " Stok Produk : ";
		getline(cin, produk[b].stok);
		cout << " Harga Produk : ";
		cin >> produk[b].harga;
	}

	else
	{
		cout << "\n Produk tidak ditemukan" << endl;
		system("pause");
	}
}

int menuPesanan()
{
	system("cls");
	int sel;
    cout << "[==============================================================]\n";
    cout << "|                      Gudang Online Shop                      |\n";
    cout << "|                           Pesanan                            |\n";
    cout << "[==============================================================]\n\n";
	
	cout << " Menu Utama\n\n";
	cout << " [1] Tambahkan Pesanan\n";
	cout << " [2] Tampilkan Pesanan\n";
	cout << " [3] Ubah Pesanan\n";
	cout << " [4] Keluar\n\n";
	cout << " Pilih	: ";

	cin>>sel;
	return sel;
}
void hapusPrd(){};
void tambahPsn();
void tampilPsn(){};
void ubahPsn(){};
