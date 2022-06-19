#include <iostream>
#include <cstdlib>
#define max 10

using namespace std;

struct Tumpukan
{
	int atas;
	int data[max];
} T;

void awal()
{
	T.atas=-1;
}

int kosong()
{
	if(T.atas==-1)
		return 1;
	else
		return 0;
}

int penuh()
{
	if(T.atas==max-1)
		return 1;
	else
		return 0;
}

void input(int data)
{
	if(kosong()==1)
	{
		T.atas++;
		T.data[T.atas]=data;
		cout<<"Data "<<T.data[T.atas]<<" masuk ke stack";
	}
	else
		cout<<"Tumpukan penuh";
}

void hapus()
{
	if(kosong()==0)
	{
		cout<<"Data teratas sudah terambil";
		T.atas--;
	}
	else
		cout<<"Data kosong";
}

void tampil()
{
	if(kosong()==0)
	{
		for(int i=T.atas;i>=0;i--)
		{
			cout<<"\nTumpukan ke "<<i<<"="<<T.data[i];
		}
	}
	else
		cout<<"Tumpukan kosong";
}
void bersih()
{
	T.atas=-1;
	cout<<"Tumpukan kosong!";
}

int main()
{
	int pil,data;
	awal();
	do
	{
		cout<<"1. Input\n2. Hapus\n3. Tampil\n4. ";
		cin>>pil;
		switch(pil)
		{
			case 1:cout<<"Masukkan data = ";cin>>data;
				input(data);
				break;
			case 2:hapus();
				break;
			case 3:tampil();
				break;
			case 4:bersih();
				break;
			case 5: cout<<"Terimakasih";
		}
	//getchar();
	cout<<endl;
	cout<<endl;
	}
	while(pil!=5);
}