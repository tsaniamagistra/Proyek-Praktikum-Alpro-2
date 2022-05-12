//Gudang Online Shop
#include<iostream>
#include<fstream>
#include<string>
<<<<<<< HEAD
#include<iomanip>

using namespace std;

char menu(); void tambah(); void tampil(); void cari(); void edit(); void hapus();

struct gudangolshop
{
	string nama;
	string merk;
	string stok;
	int harga;
};

gudangolshop gd[100];

int hitung = 0;

int main(){
    while (true)
    {
        char select = menu();
        if (select == '1')
            tambah();
        else if (select == '2')
            tampil();
=======

using namespace std;

char menu();

int main()
{
	while (true)
	{
		char select = menu();

>>>>>>> fde23cca71b8ef2c1f8036b9b7632f8bb7638b02
	}
	return 0;
}

char menu()
{
	system("cls");
<<<<<<< HEAD
    string sel;
=======

>>>>>>> fde23cca71b8ef2c1f8036b9b7632f8bb7638b02
	cout << "[==============================================================]\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "[==============================================================]\n\n";
	cout << " Menu Utama\n\n";
	cout << " [1] Tambahkan Produk\n";
	cout << " [2] Tampilkan Produk\n";
	cout << " [3] Ubah Produk\n";
	cout << " [4] Keluar\n\n";
	cout << " Pilih	: ";
<<<<<<< HEAD

	getline(cin, sel);
	return sel[0];
}

void tambah()
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
	cout << " Harga Produk : ";
	cin >> gd[hitung].harga;

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
        cout << setw(15) << gd[i].nama;
        cout << setw(15) << gd[i].merk;
        cout << setw(15) << gd[i].stok;
        cout << setw(7) << "Rp. " << gd[1].harga;
        cout << setw(7) << "| "<< endl;
		cout << "[==============================================================]\n";
        }
    system("pause");
}
=======
	string sel;
	getline(cin, sel);
	return sel[0];
}
>>>>>>> fde23cca71b8ef2c1f8036b9b7632f8bb7638b02
