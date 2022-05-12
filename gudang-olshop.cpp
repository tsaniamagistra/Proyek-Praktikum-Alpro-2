//Gudang Online Shop
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int menu(); void tambah(); void tampil(); void ubah(); void hapus(); void pesanan();

struct databarang
{
	string nama;
	string merk;
	string stok;
	int harga;
};

databarang barang[100];

int hitung = 0;

int main(){
    while (true)
    {
        int select = menu();
        if (select == 1)
            tambah();
        else if (select == 2)
            tampil();
        else if (select == 3)
            ubah();
        else if (select == 4)
			pesanan();
		else if (select == 5)
			break;
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
	cout << " [1] Tambahkan Produk\n";
	cout << " [2] Tampilkan Produk\n";
	cout << " [3] Ubah Produk\n";
	cout << " [4] Daftar Pesanan\n";
	cout << " [5] Keluar\n\n";
	cout << " Pilih	: ";

	cin>>sel;
	return sel;
}

void tambah()
{
	system("cls");

	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "|                        Tambah Produk                         |\n";
	cout << "[==============================================================]\n\n";
	cout << " Tambahkan Produk\n\n";
	cout << " Nama Produk : ";
	cin.ignore(); getline(cin, barang[hitung].nama);
	cout << " Merk Produk : ";
	getline(cin, barang[hitung].merk);
	cout << " Stok Produk : ";
	getline(cin, barang[hitung].stok);
	cout << " Harga Produk : ";
	cin >> barang[hitung].harga;

	++hitung;
}

void tampil()
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
        cout << setw(15) << barang[i].nama;
        cout << setw(15) << barang[i].merk;
        cout << setw(15) << barang[i].stok;
        cout << setw(7) << "Rp. " << barang[1].harga;
        cout << setw(7) << "| "<< endl;
		cout << "[==============================================================]\n";
        }
    system("pause");
}

void ubah()
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
		getline(cin, barang[b].nama);
		cout << " Merk Produk : ";
		getline(cin, barang[b].merk);
		cout << " Stok Produk : ";
		getline(cin, barang[b].stok);
		cout << " Harga Produk (ecer) : ";
		cin >> barang[b].harga;
	}

	else
	{
		cout << "\n Produk tidak ditemukan" << endl;
		system("pause");
	}
}

void pesanan()
{
	system("cls");
    cout << "[==============================================================]\n";
    cout << "|                      Gudang Online Shop                      |\n";
    cout << "|                           Pesanan                            |\n";
    cout << "[==============================================================]\n\n";
	
}
