//Gudang Online Shop
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int menu(); int menuProduk(),menuPesanan();
void tambahPrd(),tampilPrd(),ubahPrd(),hapusPrd(),urutPrd(),swap(int *a, int *b);
void tambahPsn(),tampilPsn(),ubahPsn(),hapusPsn();
void header();
struct dataProduk
{
	int no;
	string nama;
	string merk;
	string stok;
	int harga;
	void writeToFile2(){
		ofstream outfile;
		outfile.open("dbProduk.txt", ios::app);
		outfile << no << nama << endl << merk << endl << stok << endl << harga  << endl;
		outfile.close();
	}
};
dataProduk produk[100];

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
				else if (q == 4) hapusPrd();
				else if (q == 5) break;
			}
		}
        else if (select == 2){
			while (true){
				int q = menuPesanan();
				if (q == 1) tambahPsn();
				else if (q == 2) tampilPsn();
				else if (q == 3) ubahPsn();
				else if (q == 4) hapusPsn();
				else if (q == 5) break;
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
	header();
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
	header();
	cout << " Menu Utama\n\n";
	cout << " [1] Tambahkan Produk\n";
	cout << " [2] Tampilkan Produk\n";
	cout << " [3] Ubah Produk\n";
	cout << " [4] Hapus Produk\n";
	cout << " [5] Keluar\n\n";
	cout << " Pilih	: ";

	cin>>sel;
	return sel;
}

void tambahPrd(){
	dataProduk produk;
	system("cls");
	header();
	cout << " Tambah Produk\n";
	cout << " No	: "; cin >> produk.no;
	cout << " Nama	: "; cin >> produk.nama;
	cout << " Merk	: "; cin >> produk.merk;
	cout << " Stok	: "; cin >> produk.stok;
	cout << " Harga	: "; cin >> produk.harga;
	produk.writeToFile2();
}

void tampilPrd()
{
	ifstream tampil;
	int i = 0;

	tampil.open("dbProduk.txt");

	if(!tampil.fail()){
		while(!tampil.eof()){
			tampil >> produk[i].no
				>> produk[i].nama
				>> produk[i].merk
				>> produk[i].stok
				>> produk[i].harga;
			if(!tampil.eof()) i++;
		}
	}
    system("cls");
	header();
    cout << "+==============================================================+\n";
	cout << setw(4) << "| No";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(15) << "Stok Produk";
	cout << setw(11) << "Harga" <<"   | ";
	cout << endl;
    cout << "+==============================================================+\n";

	for(int k=0;k<i;k++){
		cout << "| " 
			<< setiosflags(ios::left) << setfill(' ') << setw(7) << produk[k].no
			<< setiosflags(ios::left) << setfill(' ') << setw(15) << produk[k].nama
			<< setiosflags(ios::left) << setfill(' ') << setw(18) << produk[k].merk
			<< setiosflags(ios::left) << setfill(' ') << setw(12) << produk[k].stok
			<< setiosflags(ios::left) << setfill(' ') << setw(9) << produk[k].harga << "|\n";
	}
	cout << "+==============================================================+\n";
	tampil.close();
	cout << "Urutkan berdasarkan : ";
	int pilih;
	cin >> pilih;
	if (pilih == 1) {
		urutPrd();
	}
	if (pilih != 1){
		cout << "Tidak ada data yang dapat diurutkan";
	}
	system("pause");
}

void ubahPrd(){
	system("cls");
	header();

	fstream data;
	data.open("dbProduk.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){
		data >> produk[i].no
			>> produk[i].nama
			>> produk[i].merk
			>> produk[i].stok
			>> produk[i].harga;
		if(!data.eof()) i++;
	}
	data.close();
	cout << " Ubah Produk\n\n";
	cout << " Masukkan No Produk yang akan diubah: ";
	int no;
	cin >> no;
	for(int k=0;k<i;k++){
		if(produk[k].no == no){
			cout << " Nama Produk Baru: ";
			cin.ignore(); getline(cin, produk[k].nama);
			cout << " Merk Produk Baru: ";
			getline(cin, produk[k].merk);
			cout << " Stok Produk Baru: ";
			getline(cin, produk[k].stok);
			cout << " Harga Produk Baru: ";
			cin >> produk[k].harga;
		}
	}
	data.open("dbProduk.txt", ios::out);
	for(int k=0;k<i;k++){
		data << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	data.close();
	cout << " Data Produk Berhasil Diubah\n";
}

void hapusPrd(){
	system("cls");
	header();
	fstream data;
	data.open("dbProduk.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){
		data >> produk[i].no
			>> produk[i].nama
			>> produk[i].merk
			>> produk[i].stok
			>> produk[i].harga;
		if(!data.eof()) i++;
	}
	data.close();
	cout << " Hapus Produk\n\n";
	cout << " Masukkan No Produk yang akan dihapus: ";
	int no;
	cin >> no;
	for(int k=0;k<i;k++){
		if(produk[k].no == no){
			for(int a=k;a<i;a++){
				produk[a].no = produk[a+1].no;
				produk[a].nama = produk[a+1].nama;
				produk[a].merk = produk[a+1].merk;
				produk[a].stok = produk[a+1].stok;
				produk[a].harga = produk[a+1].harga;
			}
		}
	}
	data.open("dbProduk.txt", ios::out);
	for(int k=0;k<i-1;k++){
		data << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	data.close();
	system("pause");
}

//urut menurut harga tertinggi
void urutPrd(){
	int k,j,min_idx,n;
	system("cls");
	header();
	fstream data;
	data.open("dbProduk.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){
		data >> produk[i].no
			>> produk[i].nama
			>> produk[i].merk
			>> produk[i].stok
			>> produk[i].harga;
		i++;
	}
	data.close();
	n = 100;
	for (k = 0; k < n-1; k++){
		min_idx = k;
        for (j = k+1; j < n; j++)
			if (produk[j].harga < produk[min_idx].harga)
				min_idx = j;
        swap(&produk[min_idx].harga, &produk[i].harga);
    }
	tampilPrd();
	system("pause");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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
	cout << " [4] Hapus Pesanan\n";
	cout << " [5] Keluar\n\n";
	cout << " Pilih	: ";

	cin>>sel;
	return sel;
}

struct dataPesanan{
	string kodePesanan;
	int tglPesan;
	string pemesan;
	int noProduk;
	string status;
	void writeToFile(){
		ofstream outfile;
		outfile.open("dbPesanan.txt", ios::app);
		outfile << kodePesanan << endl << tglPesan << endl << pemesan << endl << noProduk << endl << status << endl;
		outfile.close();
	}
};
dataPesanan pesanan[100];

void tambahPsn(){	
	dataPesanan pesanan;
	
	system("cls");
	cout<<"Kode Pesanan : "; 
	cin.ignore(); getline(cin, pesanan.kodePesanan);
	cout<<"Tanggal Pesan (YYYYMMDD) : ";
	cin >> pesanan.tglPesan;
	cout<<"Nama Pemesan : ";
	cin.ignore(); getline(cin, pesanan.pemesan);
	cout<<"No Produk : ";
	cin >> pesanan.noProduk;
	cout<<"Status Pesanan : ";
	cin.ignore(); getline(cin, pesanan.status);
	
	pesanan.writeToFile();
}

void tampilPsn(){
	ifstream fin;
	int i=0;
	
	fin.open("dbPesanan.txt");

	if(!fin.fail()){
		while(!fin.eof()){
			fin >> pesanan[i].kodePesanan
				>> pesanan[i].tglPesan
				>> pesanan[i].pemesan
				>> pesanan[i].noProduk
				>> pesanan[i].status;
			if(!fin.eof()) i++;
		}
	}
	system("cls");
	cout<<setiosflags(ios::left)<<setfill(' ')<<setw(14)<<"Kode Pesanan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<"Tanggal Pesan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Pemesan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Produk"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Status"<<endl;
	for(int k=0;k<i;k++){
		cout<<setiosflags(ios::left)<<setfill(' ')<<setw(14)<<pesanan[k].kodePesanan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<pesanan[k].tglPesan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].pemesan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].noProduk
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].status<<endl;
	}
	cout<<endl;
	
	fin.close();
	
	system("pause");
}


void ubahPsn(){
	system("cls");
	header();
	
	fstream data;
	data.open("dbPesanan.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){
		data >> pesanan[i].kodePesanan
			>> pesanan[i].tglPesan
			>> pesanan[i].pemesan
			>> pesanan[i].noProduk
			>> pesanan[i].status;
		if(!data.eof()) i++;
	}
	data.close();
	cout << " Ubah Pesanan\n\n";
	cout << " Masukkan Kode Pesanan yang akan diubah: ";
	string kode;
	cin >> kode;
	for(int k=0;k<i;k++){
		if(pesanan[k].kodePesanan == kode){
			cout<<" Tanggal Pesan (YYYYMMDD) Baru: ";
			cin >> pesanan[k].tglPesan;
			cout<<" Nama Pemesan Baru : ";
			cin.ignore(); getline(cin, pesanan[k].pemesan);
			cout<<" No Produk Baru: ";
			cin >> pesanan[k].noProduk;
			cout<<" Status Pesanan Baru: ";
			cin.ignore(); getline(cin, pesanan[k].status);
		}
	}
	data.open("dbPesanan.txt", ios::out);
	for(int k=0;k<i;k++){
		data << pesanan[k].kodePesanan << endl
			<< pesanan[k].tglPesan << endl
			<< pesanan[k].pemesan << endl
			<< pesanan[k].noProduk << endl
			<< pesanan[k].status << endl;
	}
	data.close();
	cout << " Data Pesanan Berhasil Diubah\n";
}

void hapusPsn(){
	system("cls");
	header();
	fstream data;
	
	data.open("dbPesanan.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){
		data >> pesanan[i].kodePesanan
			>> pesanan[i].tglPesan
			>> pesanan[i].pemesan
			>> pesanan[i].noProduk
			>> pesanan[i].status;
		if(!data.eof()) i++;
	}
	data.close();
	
	cout << " Hapus Pesanan\n\n";
	cout << " Masukkan kode pesanan yang akan dihapus: ";
	string kode;
	cin >> kode;
	
	for(int k=0;k<i;k++){
		if(pesanan[k].kodePesanan == kode){
			for(int a=k;a<i;a++){
				pesanan[a].kodePesanan = pesanan[a+1].kodePesanan;
				pesanan[a].tglPesan = pesanan[a+1].tglPesan;
				pesanan[a].pemesan = pesanan[a+1].pemesan;
				pesanan[a].noProduk = pesanan[a+1].noProduk;
				pesanan[a].status = pesanan[a+1].status;
			}
		}
	}
	
	data.open("dbPesanan.txt", ios::out);
	for(int j=0;j<i-1;j++){
		data << pesanan[j].kodePesanan << endl
			<< pesanan[j].tglPesan << endl
			<< pesanan[j].pemesan << endl
			<< pesanan[j].noProduk << endl
			<< pesanan[j].status << endl;
	}
	data.close();
	system("pause");
}

void header(){
	cout << "+==============================================================+\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "|                                                              |\n";
	cout << "+==============================================================+\n\n";
}