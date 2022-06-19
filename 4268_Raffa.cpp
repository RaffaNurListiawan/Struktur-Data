#include <iostream>
#include <stdlib.h>

using namespace std;

// global variable declaration
string *nama;
string *nim;

int jumlah_mhs;

void InputMahasiswa();
void InputNilaiMatkul();
void urutkanNIM();
void tampilkanMahasiswa();
void cariMhs();

int main() {
	int menu;
	string exit;
	bool isExit = false;
	
	do {
		system("clear");
		cout<<"==============="<<endl;
		cout<<"   Aplikasi    "<<endl;
		cout<<"==============="<<endl;
		cout<<"1. Input data mahasiswa"<<endl;
		cout<<"2. Hitung IPK"<<endl;
		cout<<"3. Urutkan Mahasiswa berdasarkan NIM"<<endl;
		cout<<"4. Tampilkan daftar mahasiswa"<<endl;
		cout<<"5. Cari Mahasiswa"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Pilih salah satu menu diatas [1/2/3/4/5]: ";
		cin>>menu;
	
		switch (menu) {
			case 1:
				InputMahasiswa();
				break;
			case 2:
				InputNilaiMatkul();
				break;
			case 3:
				urutkanNIM();
				break;
			case 4:
				tampilkanMahasiswa();
				break;
			case 5:
				cariMhs();
				break;
			case 6:
				goto keluar;
			default:
				cout<<"Menu tidak ada"<<endl;
				break;
		}
		
		cout<<endl;
		cout<<"Ingin keluar ? [y/n] :  ";
		cin>>exit;

		isExit = exit == "y" ? true : false;
			
	} while (!isExit);
	
	keluar:

	delete [] nama;
	delete [] nim;

	return 0;
}

void cariMhs() {
	system("clear");
	string nama_yang_dicari;
	bool ketemu = false;
	int posisi;

	cout<<"Cari Mahasiswa"<<endl;
	cout<<"Nama Mahasiswa yang Dicari : ";
	cin>>nama_yang_dicari;

	for(int i = 0; i < jumlah_mhs; i++) {
		if(*(nama+i) == nama_yang_dicari) {
			ketemu = true;
			posisi = i;
			break;
		}
	}

	if(ketemu) {
		cout<<"Nama ditemukan, '"<<nama_yang_dicari<<"' ditemukan di posisi "<< posisi <<" indeks array"<<endl;
	} else {
		cout<<"Nama tidak ditemukan"<<endl;
	}
}

void InputMahasiswa() {

	cout<<"Masukkan jumlah mahasiswa : ";
	cin>>jumlah_mhs;

	nama = new string[jumlah_mhs]; // memory allocation
	nim = new string[jumlah_mhs]; // memory allocation

	for (int i = 0; i < jumlah_mhs; i++ ) {
		cout<<endl;

		cout<<"Input data mahasiswa - "<<i+1<<" : "<<endl;
		cout<<"Nama\t : ";
		cin>>*(nama+i);
		cout<<"NIM\t : ";
		cin>>*(nim+i);
	}
	
}

void HitungIpk(int* jumlah_matkul, int nilai_matkul[99]) {
	float ipk , jumlah_nilai;
	
	for (int i = 0; i < (*jumlah_matkul); i++) {
		jumlah_nilai += nilai_matkul[i]; 
	}

    ipk = jumlah_nilai / (*jumlah_matkul);
	
	cout<<"IPK\t : "<< ipk  <<endl;
}

void InputNilaiMatkul() {
	
	int jumlah_matkul;
	
	system("clear");
	cout<<"========================"<<endl;
	cout<<" Input nilai matkul mhs"<<endl;
    cout<<"========================"<<endl;
	cout<<"Jumlah matkul : ";
	cin>>jumlah_matkul;
	int nilai_matkul[jumlah_matkul];
	char tmp[jumlah_matkul];
	
	for (int i = 0; i < jumlah_matkul; i++) {
		cout<<"Nilai matkul ke - "<< i + 1 << " [A/B/C/D/E] : ";
		cin>>tmp[i];
		
		if (tmp[i] == 'A') {
			nilai_matkul[i] = 4;
		} else if (tmp[i] == 'B') {
			nilai_matkul[i] = 3;
		} else if (tmp[i] == 'C') {
			nilai_matkul[i] = 2;
		} else if (tmp[i] == 'D') {
			nilai_matkul[i] = 1;
		} else if (tmp[i] == 'E') {
			nilai_matkul[i] = 0;
		}
	}

	system("clear");	

	HitungIpk(&jumlah_matkul, nilai_matkul);
}

void bubbleSort() {
	int i, j, second = 0;
	string temp;

	for(i = 0; i < (jumlah_mhs-1); i++) {
		for (j = 0; j < (jumlah_mhs-1); j++){
			second = j+1;
			if (*(nim+j) > *(nim+second)){
				// pertukaran nama
				temp = *(nama+j);
				*(nama+j) = *(nama+second);
				*(nama+second) = temp;

				// pertukaran nim
				temp = *(nim+j);
				*(nim+j) = *(nim+second);
				*(nim+second) = temp;
			}
			
		}
	}
	cout<<"Berhasil diurutkan dengan Bubble Ascending"<<endl;
}

void selectionSort() {
	int i, maks, j;
	string temp;

	for(i = 0; i < jumlah_mhs; i++) {
		maks = i;
		for(j = i+1; j < jumlah_mhs; j++) {
			if(*(nim+maks) > *(nim+j)){
				// mencari indeks dengan value terendah
				maks = j;
			}
		}
		if (*(nim+i) != *(nim+maks)) {
			// pertukaran nama
			temp = *(nama+i);
			*(nama+i) = *(nama+maks);
			*(nama+maks) = temp;

			// pertukaran nim
			temp = *(nim+i);
			*(nim+i) = *(nim+maks);
			*(nim+maks) = temp;
		}
	}
	cout<<"Berhasil diurutkan dengan Selection Ascending"<<endl;
}

void insertionSort() {
	int i, j, second;
	string temp, temp2;

	for (i = 0; i < jumlah_mhs; i++) {
		temp = *(nim+i);
		temp2 = *(nama+i);
		j = i-1; 

		while (*(nim+j) > temp && j >= 0)
		{
			*(nim+j+1) = *(nim+j);
			*(nama+j+1) = *(nama+j);
			j--;
		}
		second = j+1;
		*(nim+second) = temp;
		*(nama+second) = temp2;
	}
	cout<<"Berhasil diurutkan dengan Insertion Ascending"<<endl;
}

void urutkanNIM() {
	// selection sorting
	int sort;

	sortMenu:
	system("clear");
	cin.ignore();
	cout<<"==========="<<endl;
	cout<<"Mengurutkan"<<endl;
	cout<<"==========="<<endl;
	cout<<"1. Bubble sort"<<endl;
	cout<<"2. Selection sort"<<endl;
	cout<<"3. Insertion sort"<<endl;
	cout<<"pilih salah satu [1-3] : "; cin>>sort;

	switch(sort) {
		case 1:
			bubbleSort();
			break;
		case 2:
			selectionSort();
			break;
		case 3:
			insertionSort();
			break;
		default:
			cout<<"menu yang anda inputkan tidak ada";
			system("pause");
			goto sortMenu;
	}
}

void tampilkanMahasiswa() {
	system("clear");

	cout<<"================"<<endl;
	cout<<"Daftar Mahasiswa"<<endl;
	cout<<"================"<<endl;
	cout<<"|  NIM  |  Nama  |"<<endl;

	for(int i = 0; i < jumlah_mhs; i++ ) {
		cout<<"| "<<*(nim+i)<<" | "<<*(nama+i)<<" | "<<endl;
	}
}