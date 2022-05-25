//Gudang Online Shop
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int menu(); int menuProduk(),menuPesanan();
void tambahPrd(),tampilPrd(),ubahPrd(),hapusPrd(),urutPrd(),cariPrd(),swap(int *a, int *b);
void tambahPsn(),tampilPsn(),ubahPsn(),hapusPsn(),urutPsn(),cariPsn();
void header();

struct dataProduk
{
	int no;
	string nama;
	string merk;
	int stok;
	int harga;
	void writeToFile2(){
		ofstream outfile;
		outfile.open("dbProduk.txt", ios::app);
		outfile << no << nama << endl << merk << endl << stok << endl << harga  << endl;
		outfile.close();
	}
};
dataProduk produk[100];
void coutPrd(int i, dataProduk produk[100]);

struct dataPesanan{
	string kodePesanan;
	int tglPesan;
	string pemesan;
	int noProduk;
	int jmlProduk;
	string status;
	void writeToFile(){
		ofstream outfile;
		outfile.open("dbPesanan.txt", ios::app);
		outfile << kodePesanan << endl << tglPesan << endl << pemesan << endl << noProduk << endl << jmlProduk << endl << status << endl;
		outfile.close();
	}
};
dataPesanan pesanan[100];
void coutPsn(int i, dataPesanan pesanan[100]);

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
	ifstream data;
	int i = 0;

	data.open("dbProduk.txt");

	if(!data.fail()){
		while(!data.eof()){
			data >> produk[i].no
				>> produk[i].nama
				>> produk[i].merk
				>> produk[i].stok
				>> produk[i].harga;
			if(!data.eof()) i++;
		}
	}
    system("cls");
	header();
	coutPrd(i, produk);
	data.close();
	cout << " 1. Urutkan produk berdasarkan harga\n";
	cout << " 2. cari data produk\n";
	cout << " 3. kembali\n";
	int pilih;
	cin >> pilih;
	if (pilih == 1) {
		urutPrd();
	}
	else if(pilih == 2){
		cariPrd();
	}
	else if(pilih == 3){
		return;
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
			cin >> produk[k].stok;
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
		if(!data.eof()) i++;
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
    coutPrd(i, produk);
	system("pause");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void cariPrd(){
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
	cout << " Cari Produk\n\n";
	cout << " Masukkan Nama Produk yang akan dicari: ";
	string nama;
	cin.ignore(); getline(cin, nama);
	for(int k=0;k<i;k++){
		if(produk[k].nama == nama){
			cout << " No Produk: " << produk[k].no << endl;
			cout << " Nama Produk: " << produk[k].nama << endl;
			cout << " Merk Produk: " << produk[k].merk << endl;
			cout << " Stok Produk: " << produk[k].stok << endl;
			cout << " Harga Produk: " << produk[k].harga << endl;
		}
	}
	system("pause");
}

int menuPesanan()
{
	system("cls");
	int sel;
	header();
	
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
	cout<<"Jumlah Produk : ";
	cin >> pesanan.jmlProduk;
	cout<<"Status Pesanan : ";
	cin.ignore(); getline(cin, pesanan.status);
	pesanan.writeToFile();
	
	int no = pesanan.noProduk;
	int jml = pesanan.jmlProduk;
	fstream dataPrd;
	dataPrd.open("dbProduk.txt", ios::in);
	dataPrd.seekg(0, ios::beg);
	int j = 0;
	while(!dataPrd.eof()){
		dataPrd >> produk[j].no
				>> produk[j].nama
				>> produk[j].merk
				>> produk[j].stok
				>> produk[j].harga;
		if(!dataPrd.eof()) j++;
	}
	dataPrd.close();
	for(int k=0;k<j;k++){
		if(produk[k].no == no){
			produk[k].stok = produk[k].stok - jml;
		}
	}
	dataPrd.open("dbProduk.txt", ios::out);
	for(int k=0;k<j;k++){
		dataPrd << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	dataPrd.close();
}

void tampilPsn(){
	ifstream data;
	int i=0;
	
	data.open("dbPesanan.txt");

	if(!data.fail()){
		while(!data.eof()){
			data >> pesanan[i].kodePesanan
				>> pesanan[i].tglPesan
				>> pesanan[i].pemesan
				>> pesanan[i].noProduk
				>> pesanan[i].jmlProduk
				>> pesanan[i].status;
			if(!data.eof()) i++;
		}
	}
	system("cls");
	header();
	coutPsn(i,pesanan);
	data.close();
	cout << " 1. Urutkan pesanan\n";
	cout << " 2. Cari data pesanan\n";
	cout << " 3. Kembali\n";
	int pilih;
	cin >> pilih;
	if (pilih == 1) urutPsn();
	else if (pilih == 2) cariPsn();
	else if (pilih == 3) return;
	system("pause");
}

void ubahPsn(){
	system("cls");
	header();
	
	fstream dataPsn;
	dataPsn.open("dbPesanan.txt", ios::in);
	dataPsn.seekg(0, ios::beg);
	int i = 0;
	while(!dataPsn.eof()){
		dataPsn >> pesanan[i].kodePesanan
			>> pesanan[i].tglPesan
			>> pesanan[i].pemesan
			>> pesanan[i].noProduk
			>> pesanan[i].jmlProduk
			>> pesanan[i].status;
		if(!dataPsn.eof()) i++;
	}
	dataPsn.close();
	
	fstream dataPrd;
	dataPrd.open("dbProduk.txt", ios::in);
	dataPrd.seekg(0, ios::beg);
	int j = 0;
	while(!dataPrd.eof()){
		dataPrd >> produk[j].no
				>> produk[j].nama
				>> produk[j].merk
				>> produk[j].stok
				>> produk[j].harga;
		if(!dataPrd.eof()) j++;
	}
	dataPrd.close();
	
	cout << " Ubah Pesanan\n\n";
	cout << " Masukkan Kode Pesanan yang akan diubah: ";
	string kode;
	cin >> kode;
	int xa,xb,ya,yb;
	for(int k=0;k<i;k++){
		if(pesanan[k].kodePesanan == kode){
			xa = pesanan[k].noProduk;
			xb = pesanan[k].jmlProduk;
			cout<<" Tanggal Pesan (YYYYMMDD) Baru: ";
			cin >> pesanan[k].tglPesan;
			cout<<" Nama Pemesan Baru : ";
			cin.ignore(); getline(cin, pesanan[k].pemesan);
			cout<<" No Produk Baru: ";
			cin >> pesanan[k].noProduk;
			ya = pesanan[k].noProduk;
			cout<<" Jumlah Produk Baru: ";
			cin >> pesanan[k].jmlProduk;
			yb = pesanan[k].jmlProduk;
			cout<<" Status Pesanan Baru: ";
			cin.ignore(); getline(cin, pesanan[k].status);
		}
	}
	for(int k=0;k<j;k++){
		if(produk[k].no == xa){
			produk[k].stok = produk[k].stok + xb;
		}
		if(produk[k].no == ya){
			produk[k].stok = produk[k].stok - yb;
		}
	}
	
	dataPsn.open("dbPesanan.txt", ios::out);
	for(int k=0;k<i;k++){
		dataPsn << pesanan[k].kodePesanan << endl
			<< pesanan[k].tglPesan << endl
			<< pesanan[k].pemesan << endl
			<< pesanan[k].noProduk << endl
			<< pesanan[k].jmlProduk << endl
			<< pesanan[k].status << endl;
	}
	dataPsn.close();
	dataPrd.open("dbProduk.txt", ios::out);
	for(int k=0;k<j;k++){
		dataPrd << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	dataPrd.close();
	
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
			>> pesanan[i].jmlProduk
			>> pesanan[i].status;
		if(!data.eof()) i++;
	}
	data.close();
	fstream dataPrd;
	dataPrd.open("dbProduk.txt", ios::in);
	dataPrd.seekg(0, ios::beg);
	int j = 0;
	while(!dataPrd.eof()){
		dataPrd >> produk[j].no
				>> produk[j].nama
				>> produk[j].merk
				>> produk[j].stok
				>> produk[j].harga;
		if(!dataPrd.eof()) j++;
	}
	dataPrd.close();
	
	cout << " Hapus Pesanan\n\n";
	cout << " Masukkan kode pesanan yang akan dihapus: ";
	string kode;
	cin >> kode;
	
	int no, jml;
	for(int k=0;k<i;k++){
		if(pesanan[k].kodePesanan == kode){
			no = pesanan[k].noProduk;
			jml = pesanan[k].jmlProduk;
			for(int a=k;a<i;a++){
				pesanan[a].kodePesanan = pesanan[a+1].kodePesanan;
				pesanan[a].tglPesan = pesanan[a+1].tglPesan;
				pesanan[a].pemesan = pesanan[a+1].pemesan;
				pesanan[a].noProduk = pesanan[a+1].noProduk;
				pesanan[a].jmlProduk = pesanan[a+1].jmlProduk;
				pesanan[a].status = pesanan[a+1].status;
			}
		}
	}
	for(int k=0;k<j;k++){
		if(produk[k].no == no){
			produk[k].stok = produk[k].stok + jml;
		}
	}
	
	data.open("dbPesanan.txt", ios::out);
	for(int j=0;j<i-1;j++){
		data << pesanan[j].kodePesanan << endl
			<< pesanan[j].tglPesan << endl
			<< pesanan[j].pemesan << endl
			<< pesanan[j].noProduk << endl
			<< pesanan[j].jmlProduk << endl
			<< pesanan[j].status << endl;
	}
	data.close();
	dataPrd.open("dbProduk.txt", ios::out);
	for(int k=0;k<j;k++){
		dataPrd << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	dataPrd.close();
	
	system("pause");
}

void cariPsn(){
	system("cls");
	header();
	fstream data;
	data.open("dbPesanan.txt", ios::in);
	data.seekg(0, ios::beg);
	int i=0;
	while(!data.eof()){
		data >> pesanan[i].kodePesanan
			>> pesanan[i].tglPesan
			>> pesanan[i].pemesan
			>> pesanan[i].noProduk
			>> pesanan[i].jmlProduk
			>> pesanan[i].status;
		if(!data.eof()) i++;
	}
	data.close();
	cout << " Cari Pesanan\n\n";
	cout << " Masukkan Kode Pesanan yang akan dicari: ";
	string kode;
	cin.ignore(); getline(cin, kode);
	for(int k=0;k<i;k++){
		if(pesanan[k].kodePesanan == kode){
			cout << " Kode Pesanan: " << pesanan[k].kodePesanan << endl;
			cout << " Tanggal Pesan: " << pesanan[k].tglPesan << endl;
			cout << " Pemesan: " << pesanan[k].pemesan<< endl;
			cout << " Produk: " << pesanan[k].noProduk << endl;
			cout << " Jumlah Produk: " << pesanan[k].jmlProduk << endl;
			cout << " Status Pesanan: " << pesanan[k].status << endl;
		}
	}
	system("pause");
}

void urutPsn(){
	system("cls");
	cout<<"[1] Kode Pesanan\n[2] Tanggal Pesan\n[3] Status\n";
	cout<<"Urutkan berdasarkan: ";
	int urut;
	cin>>urut;
}

void header(){
	cout << "+==============================================================+\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "|                                                              |\n";
	cout << "+==============================================================+\n\n";
}

void coutPrd(int i, dataProduk produk[100]){
	cout << "+==============================================================+\n";
	cout << setw(5) << "| No";
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
}

void coutPsn(int i, dataPesanan pesanan[100]){
	cout << "+===========================================================================================+\n";
	cout<<setiosflags(ios::left)<<setfill(' ')<<setw(14)<<"Kode Pesanan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<"Tanggal Pesan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Pemesan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Produk"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(11)<<"Jml Produk"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Status"<<endl;
	cout << "+===========================================================================================+\n";
	for(int k=0;k<i;k++){
		cout<<setiosflags(ios::left)<<setfill(' ')<<setw(14)<<pesanan[k].kodePesanan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<pesanan[k].tglPesan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].pemesan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].noProduk
			<<setiosflags(ios::left)<<setfill(' ')<<setw(11)<<pesanan[k].jmlProduk
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].status<<endl;
	}
	cout << "+===========================================================================================+\n";
}
