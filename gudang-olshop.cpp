//Gudang Online Shop
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

char menu();

int main()
{
	while (true)
	{
		char select = menu();

	}
	return 0;
}

char menu()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "[==============================================================]\n\n";
	cout << " Menu Utama\n\n";
	cout << " [1] Tambahkan Produk\n";
	cout << " [2] Tampilkan Produk\n";
	cout << " [3] Ubah Produk\n";
	cout << " [4] Keluar\n\n";
	cout << " Pilih	: ";
	string sel;
	getline(cin, sel);
	return sel[0];
}

void add_produk()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "[==============================================================]\n\n";
	cout << " Tambahkan Produk\n\n";
	cout << " Nama Produk : ";
	getline(cin, gd[hitung].nama);
	cout << " Merk Produk : ";
	getline(cin, gd[hitung].merk);
	cout << " Stok Produk : ";
	getline(cin, gd[hitung].stok);
	cout << " Harga Produk (ecer) : ";
	cin >> gd[hitung].harga;

	++hitung;
}
//123
