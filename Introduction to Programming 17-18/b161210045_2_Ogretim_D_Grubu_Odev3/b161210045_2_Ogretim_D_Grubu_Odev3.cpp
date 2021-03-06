#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <process.h>
#include <cmath>
using namespace std;

void KullanicidanAl(int&x, int&y);
void CekirdekMatrisiAl(int&x, int&y, int a[5][5]);
															/****************************************************************************
															**					SAKARYA ÜNİVERSİTESİ
															**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
															**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
															**				          PROGRAMLAMAYA GİRİŞİ DERSİ
															**
															**				ÖDEV NUMARASI…...: 3.ÖDEV
															**				ÖĞRENCİ ADI...............: MERT GENÇ
															**				ÖĞRENCİ NUMARASI.: B161210045
															**				DERS GRUBU…………: 2.ÖĞRETİM D GRUBU

															****************************************************************************/


struct Islem
{
	int Giris[5][5] = { 3,2,5,1,4,
						6,2,1,0,7,
						3,0,0,2,0,
						1,1,3,2,2,
						0,3,1,0,0 };


	int cSatir; //Cekirdek matrisi kare matris oldugu icin.
	int Cekirdek[5][5] = {};//en fazla 5x5 olacagı icin
	int Sonuc[100][100] = {}; // giris matrisi odevde en fazla 100x100 olacagı dendigi icin sonuc matriside en fazla 100*100 olabilir
	int kaymaMiktari; //kayma miktari
	int sonucMatrisboyutu;
	int k;




};

int main()
{
	Islem islem; //nesne uretiliyor.
	double GirisMatrisBoyutu = sqrt(sizeof(islem.Giris) / 4); /*giris matris boyutu(satir ve sutun sayisi) hesaplanıyor.
	Giris matrisi kare matris oldugu icin satir ve sutun sayisini ayri ayri hesaplamıyoruz tek islemde bitiriyoruz. 4 ise int veri tipi bellekte 4 byte'lık yer kapladıgı icin. */

	KullanicidanAl(islem.cSatir, islem.kaymaMiktari); //Cekirdek matrisinin kac boyutlu oldugunu ve kayma miktarini kullanicidan aliyoruz.
	double cSatir = islem.cSatir;  //double ' a donusturdum cunku kontrol yapmam gerekiyor
	double kaymaMiktari = islem.kaymaMiktari; 
	islem.sonucMatrisboyutu = ((GirisMatrisBoyutu - islem.cSatir) / islem.kaymaMiktari) + 1; //sonuc matrisinin sonucu odevde verilen formule gore hesaplaniyor. 
	double a = ((GirisMatrisBoyutu - islem.cSatir) / islem.kaymaMiktari);
	islem.k = islem.kaymaMiktari;
	if (a==floor(a)) //eger giris matris boyutu - cekirdek boyutu / kayma miktari tam sayi cikmazsa islem yapilamaz. yukarida double yapmamın sebebi buydu. floor fonksiyonu ile en yakin tam sayiya yuvarliyorum.
	{
		CekirdekMatrisiAl(islem.cSatir, islem.cSatir, islem.Cekirdek); // cekirdek matrisi alınıyor.

		int sonuc = 0; // matris carpimini hesaplayan ve sonuc matrisine aktaran sonuc degiskeninin ilk degeri 0.

		for (int p = 0; p < islem.sonucMatrisboyutu; p++) //sonuc matrisi hesaplanıyor..
		{
			for (int k = 0; k < islem.sonucMatrisboyutu; k++) // ilk 2 for sonuc matrisi icin sonraki 2 for ise giris ve cekirdek matrisi icin gerekli.
			{
				for (int i = 0; i < islem.cSatir; i++) 
				{
					for (int j = 0; j < islem.cSatir; j++)
					{
						sonuc += islem.Cekirdek[i][j] * islem.Giris[i + (p*islem.k)][j + islem.kaymaMiktari - islem.k]; //sonuc matrisleri carpiyor.
					}

				}
				islem.kaymaMiktari = islem.kaymaMiktari + islem.k; //her islemden sonra kayma miktarina gore diziye aktariliyor.
				islem.Sonuc[p][k] = sonuc;
				sonuc = 0;
			}
			islem.kaymaMiktari = islem.k;
		}

		// sonuc matrisini ekrana yazıyor.

		for (int i = 0; i < islem.sonucMatrisboyutu; i++)
		{
			for (int j = 0; j < islem.sonucMatrisboyutu; j++)
			{
				cout << islem.Sonuc[i][j] << "  ";

			}
			cout << endl;

		}

	}
	// cekirdek matrisi tastigi zaman hata veriyor ve programdan cikiyor.
	else
	{
		cout << endl;
		cout << "bu islem yapilamaz..."<<endl<<"------------------";
		exit(0);
	}

	return 0;
}
void KullanicidanAl(int& x, int& y) //kullanicidan cekirdek ve kayma miktarini alan fonksiyon. degiskenlerin adresleri ile bu islemi yapmaliyiz yoksa main fonksiyonu bu degiskenleri tanimayacaktir.
{
	cout << "Cekirdek boyutunu giriniz:";
	cin >> x;
	cout << "Kayma miktarini giriniz: ";
	cin >> y;
}
void CekirdekMatrisiAl(int &x, int&y, int a[5][5]) //Cekirdek matrisinin elemanlarini alan fonksiyon. ayni sekilde adresler ile bu islemi yapiyoruz yoksa main fonksiyonu bu degiskeneleri tanimayacaktir.	
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << "Cekirdek" << "[" << i << "]" << "[" << j << "]" << " = ";
			cin >> a[i][j];
		}
	}
}

