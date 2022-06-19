#include <iostream>
#include <stdlib.h>
#define max 10
using namespace std;

//global variable declaration
int jml_mahasiswa, tempnim, maks, ketemu, posisi;
float tempipk;
string tempnama, cari;

//struct datamahasiswa
struct DataMahasiswa {
 string nama;
 int nim;
 float ipk;
};
DataMahasiswa datamhs[100];

//struct stack/tumpukan
struct Tumpukan{
 int atas;
 string data[max];
} T;

//fungsi stack 
void awal();
int kosong();
int penuh();
void input(string data);
void hapus();
void tampil();
void bersih();

// Fungsi data mahasiswa
void inputdatamhs();
void DataMhs(int *jml_mhs);
void menusort();
void bubbleshort();
void selectionsort();
void insertsort();
void search();
void tampildatamhs();

//fungsi main menu utama
int main(){
	int menu, menu2, sort, pil;
	string data;
	menu:
	cout << "===============================\n PROGRAM INPUT DATA MAHASISWA \n===============================\n";
	cout << "= MENU UTAMA =\n=====================\n";
	cout << "1. Data Mahasiswa\n2. Stack\n3. Keluar\n";
	cout << "Masukkan Pilihan : "; cin >> menu;
	system("cls");
	switch (menu){
		case 1:
		menu2:
		cout << "==========================" << endl;
		cout << "= DATA MAHASISWA =" << endl;
		cout << "==========================" << endl;
		cout << "1. Inputkan Data Mahasiswa\n2. Tampilkan Data mahasiswa\n";
		cout << "3. Urutkan Data\n4. Cari Data\n5. Kembali ke menu utama\n";
		cout << "Inputkan Pilihan = ";cin >> menu2;system("cls");
		switch (menu2){
				case 1:
					inputdatamhs();
					system("cls");goto menu2;
				case 2:
					tampildatamhs();
					system("cls");goto menu2;
				case 3:
					menusort();
					system("cls");goto menu2;
				case 4:
					search();
					cout << "Tekan enter untuk kembali ke menu....\n";
					cin.get();
					cin.ignore();
					system("cls");goto menu2;
				case 5:
					goto menu;
				default:
					cout << "Pilihan Salah!!!\n";
					cout << "Tekan enter untuk kembali ke menu....\n";
					cin.get();
					cin.ignore();
					system("cls");goto menu2;
		}
		case 2:
			awal();
			do{
				cout<<"STACK NAMA MAHASISWA\n";
				cout<<"------------------------\n1. Input\n2. Hapus\n3. Tampil\n4. ";
				cout <<"Bersihkan\n5. Kembali ke menu utama\n";
				cout<<"------------------------\nMasukkan pilihan : ";
				cin>>pil;
				switch(pil){
					case 1:cout<<"Masukkan data = ";cin>>data;
					input(data);
					break;
					case 2:hapus();
					break;
					case 3:tampil();
					break;
					case 4:bersih();
				}
			cout<<"\n\n";
			} while (pil!=5);
			system("cls");goto menu;
		case 3:
			goto end;
		default:
			cout << "Pilihan Salah!!!\n";
			cout << "Tekan enter untuk kembali ke menu....\n";
			cin.get();
			cin.ignore();
			system("cls");
			goto menu;
	}
	end:
	cout << endl;
}

void awal(){
	T.atas=-1;
}

int kosong(){
	if(T.atas==-1)
		return 1;
	else
		return 0;
}

int penuh(){
	if(T.atas==max-1)
		return 1;
	else
		return 0;
}

void input(string data){
	if(kosong()==1){
		T.atas++;
		T.data[T.atas]=data;
		cout<<"Data "<<T.data[T.atas]<<" masuk ke stack";
 }
 
 else if(penuh()==0){
	T.atas++;
	T.data[T.atas]=data;
	cout<<"Data "<<T.data[T.atas]<<" masuk ke stack";
 }
 
 else
	cout<<"Tumpukan penuh";
 
}

void hapus(){
	if(kosong()==0){
		cout<<"data teratas sudah terambil";
		T.atas--;
	}
	else{
		cout<<"Data kosong";
	}
}

void tampil(){
	if(kosong()==0){
		for(int i=T.atas;i>=0;i--){
			cout<<"\nTumpukan ke "<<i+1<<" = "<<T.data[i];
		}
	}
	else{
		cout<<"Tumpukan kosong";
	}
}

void bersih(){
	T.atas=-1;
	cout<<"Tumpukan kosong!";
}

void bubbleshort(){
	int v,w;
	for (v=0; v<jml_mahasiswa; v++){
		for (w=0; w<jml_mahasiswa-1; w++){
			if (datamhs[w].nim > datamhs[w+1].nim){
				tempnim = datamhs[w].nim;
				datamhs[w].nim=datamhs[w+1].nim;
				datamhs[w+1].nim=tempnim;
				tempnama = datamhs[w].nama;
				datamhs[w].nama=datamhs[w+1].nama;
				datamhs[w+1].nama=tempnama;
				tempipk = datamhs[w].ipk;
				datamhs[w].ipk=datamhs[w+1].ipk;
				datamhs[w+1].ipk=tempipk;
			}
		}
	}
}

void inputdatamhs(){
	cout << "========================" << endl;
	cout << "= Input Data Mahasiswa =" << endl;
	cout << "========================" << endl;
	cout << "Jumlah mahasiswa yang akan diinput = ";
	cin >> jml_mahasiswa;
	DataMhs(&jml_mahasiswa);
}

void menusort(){
	int menusort;
	menusort:
	cout << "=========================" << endl;
	cout << "Metode Pengurutan\n";
	cout << "=========================" << endl;
	cout << "1. Bubble Sort\n";
	cout << "2. Selection Sort\n";
	cout << "3. Insert Sort\n";
	cout << "Pilih : ";
	cin >> menusort;
	cout<<endl;
	switch (menusort){
		case 1:
			bubbleshort();
			break;
		case 2:
			selectionsort();
			break;
		case 3:
			insertsort();
			break;
		default:
		cout << "Pilihan Salah!!!!\n";
		cout << "Tekan enter untuk kembali ke menu....\n";
		cin.get();
		cin.ignore();
		system("cls");
		goto menusort;
	}
}

void selectionsort(){
	int v,w;
	for (v=0; v<jml_mahasiswa; v++){
		maks=v;
		for (w=v+1; w<jml_mahasiswa; w++){
			if(datamhs[w].nim<datamhs[maks].nim){
				maks=w;
			}
		}
		if(datamhs[v].nim != datamhs[maks].nim){
			tempnim=datamhs[v].nim;
			datamhs[v].nim=datamhs[maks].nim;
			datamhs[maks].nim=tempnim;
			tempnama=datamhs[v].nama;
			datamhs[v].nama=datamhs[maks].nama;
			datamhs[maks].nama=tempnama;
			tempipk=datamhs[v].ipk;
			datamhs[v].ipk=datamhs[maks].ipk;
			datamhs[maks].ipk=tempipk;
		}
	}
}

void insertsort(){
	int v,w;
	for (v=0; v<jml_mahasiswa; v++){
		tempnim = datamhs[v].nim;
		tempnama = datamhs[v].nama;
		tempipk = datamhs[v].ipk;
 
		w = v-1;
 
	while(datamhs[w].nim>tempnim && w>=0){
		datamhs[w+1].nim = datamhs[w].nim;
		datamhs[w+1].nama = datamhs[w].nama;
		datamhs[w+1].ipk = datamhs[w].ipk;
		w--;
	}
	datamhs[w+1].nim=tempnim;
	datamhs[w+1].nama=tempnama;
	datamhs[w+1].ipk=tempipk;
	}
}

void DataMhs(int *jml_mhs){
	int jumlahmatkul, nilai, m;
	float jumlahnilai=0;
	for (int i=0; i<jml_mahasiswa; i++){
		cout << "Data Mahasiswa Ke-" << i+1 <<endl;
		cout << "Nama : "; cin >> datamhs[i].nama;
		cout << "NIM : "; cin >> datamhs[i].nim;
		cout << "IPK : "; cin >> datamhs[i].ipk;
	}
}

void tampildatamhs(){
	cout << "==================" << endl;
	cout << "= Data Mahasiswa =" << endl;
	cout << "==================" << endl;
	for(int a=0; a<jml_mahasiswa; a++){
		cout << "Data Mahasiwa Ke-"<<a+1<<endl;
		cout << "Nama : " << datamhs[a].nama << endl;
		cout << "NIM : " << datamhs[a].nim << endl;
		cout << "IPK : " << datamhs[a].ipk << endl;
		cout << endl;
	}
	cout << "Tekan enter untuk kembali ke menu....\n";
	cin.get();
	cin.ignore();
}
void search(){
	int cl;
	cout << "====SEARCH====" << endl;
	cout << "Nama yang dicari = ";
	cin >> cari;
	ketemu = 0;
	for (cl =0; cl <jml_mahasiswa; cl++){
		if(datamhs[cl].nama == cari){
			ketemu = 1;
			posisi = cl;
		}
	}
	if(ketemu == 0){
		cout << "Data tidak ditemukan\n";
	}
	else{
		cout << "''" << cari << "''" << " ditemukan pada data ke-" << posisi+1 << endl;
	}	 
}


