//Gudang Online Shop
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int menu(); int menuProduk(),menuPesanan();
void tambahPrd(),tampilPrd(),ubahPrd(),hapusPrd(),urutPrd(),cariPrd();
void tambahPsn(),tampilPsn(),ubahPsn(),hapusPsn(),urutPsn(),cariPsn();
void header();

struct dataProduk //struktur data produk
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
dataProduk produk[100]; //array struktur data produk
void coutPrd(int i, dataProduk produk[100]); //cetak struktur data produk
void bsearch(int i, int k, string nama, dataProduk produk[100]);
void swap(dataProduk *a, dataProduk *b);

struct dataPesanan //struktur data pesanan
{	
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
dataPesanan pesanan[100]; //array struktur data pesanan
void coutPsn(int i, dataPesanan pesanan[100]); //cetak struktur data pesanan
void swap(dataPesanan *a, dataPesanan *b);

int main(){ //main
    while (true) //
    {
        int select = menu(); //memanggil menu
        if (select == 1){ //pilihan menu produk
            while (true){
				int q = menuProduk();
				if (q == 1) tambahPrd();
				else if (q == 2) tampilPrd();
				else if (q == 3) ubahPrd();
				else if (q == 4) hapusPrd();
				else if (q == 5) break;
			}
		}
        else if (select == 2){ //pilihan menu pesanan
			while (true){
				int q = menuPesanan();
				if (q == 1) tambahPsn();
				else if (q == 2) tampilPsn();
				else if (q == 3) ubahPsn();
				else if (q == 4) hapusPsn();
				else if (q == 5) break;
			}
		}
        else if (select == 3) break; //pilihan keluar
	}
	return 0;
}

int menu() //fungsi menu utama
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

int menuProduk() //fungsi menu produk
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

void tambahPrd(){ //fungsi menambah produk
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
	cout << " Data Produk Berhasil Ditambahkan\n";
	system("pause");
}

void tampilPrd() //fungsi menampilkan produk
{
	ifstream data;
	int i = 0;

	data.open("dbProduk.txt"); //membuka file

	if(!data.fail()){ //looping untuk menampilkan data
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
	cout << endl;
	cout << " [1] Urutkan produk\n";
	cout << " [2] Cari data produk\n";
	cout << " [3] Kembali\n";
	cout << " Pilih	: ";
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
	else{
		tampilPrd();
	}
}

void ubahPrd(){ //fungsi mengubah produk
	system("cls");
	header();

	fstream data;
	data.open("dbProduk.txt", ios::in); //membuka file
	data.seekg(0, ios::beg); //mengarahkan pointer ke awal file
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
	for(int k=0;k<i;k++){ //looping untuk mencari produk
		if(produk[k].no == no){ //jika produk ditemukan
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
	for(int k=0;k<i;k++){ //looping untuk menulis ke file
		data << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	data.close();
	cout << " Data Produk Berhasil Diubah\n";
	system("pause");
}

void hapusPrd(){
	system("cls");
	header();
	fstream data;
	data.open("dbProduk.txt", ios::in); //membuka file
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){ //looping untuk mencari produk
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
	for(int k=0;k<i;k++){ //looping untuk mencari produk
		if(produk[k].no == no){ //jika produk ditemukan
			for(int a=k;a<i;a++){ //looping untuk menghapus produk
				produk[a].no = produk[a+1].no;
				produk[a].nama = produk[a+1].nama;
				produk[a].merk = produk[a+1].merk;
				produk[a].stok = produk[a+1].stok;
				produk[a].harga = produk[a+1].harga;
			}
		}
	}
	data.open("dbProduk.txt", ios::out);
	for(int k=0;k<i-1;k++){ //looping untuk menulis ke file
		data << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	data.close();
	cout << " Data Produk Berhasil Dihapus\n";
	system("pause");
}

void urutPrd(){ //fungsi mengurutkan produk
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
	cout << " Urutkan Produk berdasarkan :\n";
	cout << " [1] Harga Paling Murah\n";
	cout << " [2] Harga Paling Mahal\n";
	cout << " [3] Stok Paling Sedikit\n";
	cout << " [4] Stok Paling Banyak\n";
	cout << " Pilih	: ";
	int urut;
	cin >> urut;
	if(urut == 1){ //urutkan berdasarkan harga
		for(int k=0;k<i-1;k++){ 
			for(int a=k+1;a<i;a++){ 
				if(produk[k].harga > produk[a].harga){ //berdasarkan harga paling murah
					swap(&produk[k],&produk[a]);
				}
			}
		}
	}
	else if(urut == 2){ //urutkan berdasarkan harga
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(produk[k].harga < produk[a].harga){ //berdasarkan harga paling mahal
					swap(&produk[k],&produk[a]);
				}
			}
		}
	}
	else if(urut == 3){ //urutkan berdasarkan stok
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(produk[k].stok > produk[a].stok){ //berdasarkan stok paling sedikit
					swap(&produk[k],&produk[a]);
				}
			}
		}
	}
	else if(urut == 4){ //urutkan berdasarkan stok
		for(int k=0;k<i-1;k++){ 
			for(int a=k+1;a<i;a++){ 
				if(produk[k].stok < produk[a].stok){ //berdasarkan stok paling banyak
					swap(&produk[k],&produk[a]);
				}
			}
		}
	}
	else{
		urutPrd(); //jika pilihan tidak ada
	}
	system("cls");
	coutPrd(i, produk); //menampilkan produk yang sudah diurutkan
	cout << endl;
	cout << " [1] Cari data produk\n";
	cout << " [2] Urutkan lagi\n";
	cout << " [3] Kembali\n";
	cout << " Pilih	: ";
	int pilih;
	cin >> pilih;
	if(pilih == 1){
		cariPrd();
	}
	else if(pilih == 2){
		urutPrd();
	}
	else if(pilih == 3){
		return;
	}
	else {
		cout << " Pilihan tidak ada\n";
	}
}

void cariPrd(){ //fungsi mencari produk
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
	cout << " Masukkan nama produk : "; //mencari produk berdasarkan nama
	string nama;
	cin >> nama;
	system("cls");
	header();
	int k=0;
	bsearch (i,k,nama, produk); //mencari produk berdasarkan nama
	system("pause");
}

void bsearch(int i, int k, string nama, dataProduk produk[100]){ //fungsi mencari produk
	if (produk[k].nama == nama){
		cout << " Data Produk dengan nama " << nama << " :\n";
		cout << " No.		: " << produk[k].no << endl
			<< " Nama		: " << produk[k].nama << endl
			<< " Merk		: " << produk[k].merk << endl
			<< " Stok		: " << produk[k].stok << endl
			<< " Harga		: " << produk[k].harga << endl;
	}
	else if (k==i) {
        cout << "Data Tidak Ditemukan" << endl;
    }
    else
    {
        k++;
        bsearch(i,k,nama,produk);
	}
}

int menuPesanan() //fungsi menu pesanan
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

void tambahPsn(){ //fungsi tambah pesanan
	dataPesanan pesanan;
	
	system("cls");
	cout << "Kode Pesanan : "; 
	cin.ignore(); getline(cin, pesanan.kodePesanan);
	cout << "Tanggal Pesan (YYYYMMDD) : ";
	cin >> pesanan.tglPesan;
	cout << "Nama Pemesan : ";
	cin.ignore(); getline(cin, pesanan.pemesan);
	cout << "No Produk : ";
	cin >> pesanan.noProduk;
	cout << "Jumlah Produk : ";
	cin >> pesanan.jmlProduk;
	cout << "Status Pesanan : ";
	cin.ignore(); getline(cin, pesanan.status);
	pesanan.writeToFile(); //menulis data ke file
	
	int no = pesanan.noProduk; //mengambil nomor produk
	int jml = pesanan.jmlProduk; //mengambil jumlah produk
	fstream dataPrd; //membuka file produk
	dataPrd.open("dbProduk.txt", ios::in);
	dataPrd.seekg(0, ios::beg);
	int j = 0;
	while(!dataPrd.eof()){ //looping untuk mencari produk
		dataPrd >> produk[j].no
				>> produk[j].nama
				>> produk[j].merk
				>> produk[j].stok
				>> produk[j].harga;
		if(!dataPrd.eof()) j++;
	}
	dataPrd.close(); 
	for(int k=0;k<j;k++){ //looping untuk mengubah stok produk
		if(produk[k].no == no){
			produk[k].stok = produk[k].stok - jml;
		}
	}
	dataPrd.open("dbProduk.txt", ios::out);
	for(int k=0;k<j;k++){ //looping untuk menulis ulang data produk
		dataPrd << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	dataPrd.close();
	cout << " Data Pesanan Berhasil Ditambahkan\n";
}

void tampilPsn(){ //fungsi tampil pesanan
	ifstream data;
	int i=0;
	
	data.open("dbPesanan.txt");

	if(!data.fail()){ 
		while(!data.eof()){ //looping untuk mengambil data
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
	cout << endl;
	cout << "[1] Urutkan Pesanan \n";
	cout << "[2] Cari Pesanan \n";
	cout << "[3] Kembali \n";
	cout << "Pilih	: ";
	int pilih;
	cin >> pilih;
	if (pilih == 1) urutPsn();
	else if (pilih == 2) cariPsn();
	else if (pilih == 3) return; 
}

void ubahPsn(){ //fungsi ubah pesanan
	system("cls");
	header();
	
	fstream dataPsn;
	dataPsn.open("dbPesanan.txt", ios::in);
	dataPsn.seekg(0, ios::beg);
	int i = 0;
	while(!dataPsn.eof()){ //looping untuk mengambil data pesanan
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
	while(!dataPrd.eof()){ //looping untuk mencari produk
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
	for(int k=0;k<i;k++){ //looping untuk mencari kode pesanan
		if(pesanan[k].kodePesanan == kode){  //jika kode pesanan sama
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
	for(int k=0;k<j;k++){ //looping untuk mengubah stok produk
		if(produk[k].no == xa){ 
			produk[k].stok = produk[k].stok + xb;
		}
		if(produk[k].no == ya){
			produk[k].stok = produk[k].stok - yb;
		}
	}
	
	dataPsn.open("dbPesanan.txt", ios::out);
	for(int k=0;k<i;k++){ //looping untuk menulis ulang data pesanan
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
	system("pause");
}

void hapusPsn(){ //fungsi hapus pesanan
	system("cls");
	header();
	fstream data;
	
	data.open("dbPesanan.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){ //looping untuk mengambil data pesanan
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
	cout << " Masukkan kode pesanan yang akan dihapus: "; //
	string kode;
	cin >> kode;
	
	int no, jml;
	for(int k=0;k<i;k++){ //looping untuk mencari kode pesanan
		if(pesanan[k].kodePesanan == kode){ //jika kode pesanan sama
			no = pesanan[k].noProduk;
			jml = pesanan[k].jmlProduk;
			for(int a=k;a<i;a++){ //looping untuk menghapus data pesanan
				pesanan[a].kodePesanan = pesanan[a+1].kodePesanan;
				pesanan[a].tglPesan = pesanan[a+1].tglPesan;
				pesanan[a].pemesan = pesanan[a+1].pemesan;
				pesanan[a].noProduk = pesanan[a+1].noProduk;
				pesanan[a].jmlProduk = pesanan[a+1].jmlProduk;
				pesanan[a].status = pesanan[a+1].status;
			}
		}
	}
	for(int k=0;k<j;k++){ //looping untuk mengubah stok produk
		if(produk[k].no == no){
			produk[k].stok = produk[k].stok + jml;
		}
	}
	
	data.open("dbPesanan.txt", ios::out);
	for(int j=0;j<i-1;j++){ //looping untuk menulis ulang data pesanan
		data << pesanan[j].kodePesanan << endl
			<< pesanan[j].tglPesan << endl
			<< pesanan[j].pemesan << endl
			<< pesanan[j].noProduk << endl
			<< pesanan[j].jmlProduk << endl
			<< pesanan[j].status << endl;
	}
	data.close();
	dataPrd.open("dbProduk.txt", ios::out);
	for(int k=0;k<j;k++){ //looping untuk menulis ulang data produk
		dataPrd << produk[k].no << endl
			<< produk[k].nama << endl
			<< produk[k].merk << endl
			<< produk[k].stok << endl
			<< produk[k].harga << endl;
	}
	dataPrd.close();
	cout << " Data Pesanan Berhasil Dihapus\n";
	system("pause");
}

void cariPsn(){ //fungsi cari pesanan
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
	cout << "Masukkan kode pesanan yang akan dicari: ";
	string kode; 
	cin >> kode;
	system("cls");
	if (i==0){ //jika data pesanan kosong
		cout << "Data pesanan tidak ditemukan\n";
	}
	else{ 
		cout << "Data pesanan yang dicari:\n";
		for(int k=0;k<i;k++){ 
			if(pesanan[k].kodePesanan == kode){
				cout << "Kode Pesanan	: " << pesanan[k].kodePesanan << endl
					<< "Tanggal Pesan	: " << pesanan[k].tglPesan << endl
					<< "Pemesan		: " << pesanan[k].pemesan << endl
					<< "No. Produk	: " << pesanan[k].noProduk << endl
					<< "Jumlah Produk	: " << pesanan[k].jmlProduk << endl
					<< "Status		: " << pesanan[k].status << endl;
			}
		}
	}
	system("pause");
}

void urutPsn(){
	system("cls");
	cout << " Urutkan Pesanan berdasarkan :\n";
	cout << " [1] Kode Pesanan Ascending\n";
	cout << " [2] Kode Pesanan Desscending\n";
	cout << " [3] Tanggal Pesan Ascending\n";
	cout << " [4] Tanggal Pesan Descending\n";
	cout << " [5] Status Pesanan Ascending\n";
	cout << " [6] Status Pesanan Descending\n";
	cout << " Pilih	: ";
	int urut;
	cin>>urut;
	system("cls");
	header();
	fstream data;
	data.open("dbPesanan.txt", ios::in);
	data.seekg(0, ios::beg);
	int i = 0;
	while(!data.eof()){ //looping untuk mengambil data pesanan
		data >> pesanan[i].kodePesanan
			>> pesanan[i].tglPesan
			>> pesanan[i].pemesan
			>> pesanan[i].noProduk
			>> pesanan[i].jmlProduk
			>> pesanan[i].status;
		if(!data.eof()) i++;
	}
	data.close();
	if(urut == 1){ //jika urutkan berdasarkan kode pesanan ascending
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(pesanan[k].kodePesanan > pesanan[a].kodePesanan){
					swap(&pesanan[k],&pesanan[a]);
				}
			}
		}
	}
	else if(urut == 2){ //jika urutkan berdasarkan kode pesanan descending
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(pesanan[k].kodePesanan < pesanan[a].kodePesanan){
					swap(&pesanan[k],&pesanan[a]);
				}
			}
		}
	}
	else if(urut == 3){ //jika urutkan berdasarkan tanggal pesan ascending
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(pesanan[k].tglPesan > pesanan[a].tglPesan){
					swap(&pesanan[k],&pesanan[a]);
				}
			}
		}
	}
	else if(urut == 4){ //jika urutkan berdasarkan tanggal pesan descending
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(pesanan[k].tglPesan < pesanan[a].tglPesan){
					swap(&pesanan[k],&pesanan[a]);
				}
			}
		}
	}
	else if(urut == 5){ //jika urutkan berdasarkan status ascending
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(pesanan[k].status > pesanan[a].status){
					swap(&pesanan[k],&pesanan[a]);
				}
			}
		}
	}
	else if(urut == 6){ //jika urutkan berdasarkan status descending
		for(int k=0;k<i-1;k++){
			for(int a=k+1;a<i;a++){
				if(pesanan[k].status < pesanan[a].status){
					swap(&pesanan[k],&pesanan[a]);
				}
			}
		}
	}
	else{
		cout<<"Pilihan tidak ada\n";
	}
	system("cls");
	coutPsn(i, pesanan); //menampilkan pesanan yang sudah diurutkan
	cout << endl;
	cout << " [1] Cari data pesanan\n";
	cout << " [2] Urutkan lagi\n";
	cout << " [3] Kembali\n";
	cout << " Pilih	: ";
	int pilih;
	cin >> pilih;
	if(pilih == 1){
		cariPsn();
	}
	else if(pilih == 2){
		urutPsn();
	}
	else if(pilih == 3){
		return;
	}
	else {
		cout << " Pilihan tidak ada\n";
	}
}

void swap(dataProduk *a, dataProduk *b) { //fungsi untuk swap
    dataProduk temp = *a;
    *a = *b;
    *b = temp;
}

void swap(dataPesanan *a, dataPesanan *b) { //fungsi untuk swap
    dataPesanan temp = *a;
    *a = *b;
    *b = temp;
}


void header(){ //fungsi untuk menampilkan header
	cout << "+==============================================================+\n";
	cout << "|                      Gudang Online Shop                      |\n";
	cout << "|                                                              |\n";
	cout << "+==============================================================+\n\n";
}

void coutPrd(int i, dataProduk produk[100]){ //fungsi untuk menampilkan data produk
	cout << "+==============================================================+\n";
	cout << setw(5) << "| No";
	cout << setw(15) << "Nama Produk";
	cout << setw(15) << "Merk Produk";
	cout << setw(18) << "Stok Produk";
	cout << setw(8) << "Harga" <<"  | ";
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

void coutPsn(int i, dataPesanan pesanan[100]){ //fungsi untuk menampilkan data pesanan
	cout << "+=========================================================================================+\n";
	cout<<setiosflags(ios::left)<<setfill(' ')<<setw(14)<<"Kode Pesanan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Tanggal Pesan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<"Pemesan"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<"No Produk"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<"Jml Produk"
		<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<"Status"<<endl;
	cout << "+=========================================================================================+\n";
	for(int k=0;k<i;k++){
		cout<<setiosflags(ios::left)<<setfill(' ')<<setw(14)<<pesanan[k].kodePesanan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].tglPesan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<pesanan[k].pemesan
			<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<pesanan[k].noProduk
			<<setiosflags(ios::left)<<setfill(' ')<<setw(15)<<pesanan[k].jmlProduk
			<<setiosflags(ios::left)<<setfill(' ')<<setw(20)<<pesanan[k].status<<endl;
	}
	cout << "+=========================================================================================+\n";
}
