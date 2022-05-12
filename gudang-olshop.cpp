//Gudang Online Shop
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int menu(); int menuProduk(),menuPesanan();
void tambahPrd(),tampilPrd(),ubahPrd(),hapus();
void tambahPsn(),tampilPsn(),ubahPsn();

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
        int select = menu();
        if (select == 1){
            while (true){
				int q = menuProduk();
				if (q == 1) tambahPrd();
				else if (q == 2) tampilPrd();
				else if (q == 3) ubahPrd();
				else if (q == 4) break;
			}
		}
        else if (select == 2){
			while (true){
				int q = menuPesanan();
				if (q == 1) tambahPsn();
				else if (q == 2) tampilPsn();
				else if (q == 3) ubahPsn();
				else if (q == 4) break;
			}
		}
        else if (select == 3) break;
	}
	return 0;
}

int menu()
{
	system("cls");
    int sel;
	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "[==============================================================]\n\n";
	cout << " Menu Utama\n\n";
	cout << " [1] Data Produk\n";
	cout << " [2] Data Pesanan\n";
	cout << " [3] Keluar\n\n";
	cout << " Pilih	: ";

	cin>>sel;
	return sel;
}

int menuProduk()
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
		cout << " Harga Produk (ecer) : ";
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

void tambahPsn(){}
void tampilPsn(){}
void ubahPsn(){}
