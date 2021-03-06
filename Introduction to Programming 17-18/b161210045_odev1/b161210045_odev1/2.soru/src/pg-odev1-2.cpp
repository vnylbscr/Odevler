#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string.h>
#include <algorithm>
#include <iomanip>
using namespace std;


									/****************************************************************************
										**					SAKARYA ÜNİVERSİTESİ
							**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
									**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
								**				          PROGRAMLAMAYA GİRİŞİ DERSİ
											**
							**				ÖDEV NUMARASI…...: PG-GİRİS 1.ODEV 2.SORU
							**				ÖĞRENCİ ADI...............:MERT GENÇ
							**				ÖĞRENCİ NUMARASI.:B161210045
							**				DERS GRUBU…………:2.OGRETİM D GRUBU 
							****************************************************************************/


int main()
{
	setlocale(LC_ALL, "Turkish");
	// DEGİSKEN TANIMLAMASI//
	char kelime[50];
	int enbuyuk = 0, d, j;
	int i = 0;
	int sesliharfsayisi = 0;
	int atekrarsayisi = 0;
	int etekrarsayisi = 0;
	int itekrarsayisi = 0;
	int otekrarsayisi = 0;
	int utekrarsayisi = 0;

	//VERİLER ALINIYOR//
	cout << "Kelimeyi giriniz (Turkçe karakter kullanmayiniz) : " << endl;
	gets_s(kelime);
	//FOR DONGUSUYLE GIRILEN KELIMENIN UZUNLUGU KADAR SORGULAMA YAPILIYOR//
	for (i = 0; i <= kelime[i]; i++)

	{
		if (kelime[i] == 'a' || kelime[i] == 'A')
		{
			sesliharfsayisi++;
			atekrarsayisi++;
		}
		else if (kelime[i] == 'e' || kelime[i] == 'E')
		{
			sesliharfsayisi++;
			etekrarsayisi++;
		}
		else if (kelime[i] == 'i' || kelime[i] == 'I')
		{
			sesliharfsayisi++;
			itekrarsayisi++;
		}
	
		else if (kelime[i] == 'o' || kelime[i] == 'O')
		{
			sesliharfsayisi++;
			otekrarsayisi++;
		}
		else if (kelime[i] == 'u' || kelime[i] == 'U')
		{
			sesliharfsayisi++;
			utekrarsayisi++;
		}

	}
	// BU DEGISKENI ASAGIDA TANIMLAMAMIN SEBEBI YUKARDAKI KOSULLARDAN SONRA DEGERLERININ DEGISECEK OLMASI//
	int sayilar[5] = { atekrarsayisi,etekrarsayisi,itekrarsayisi,otekrarsayisi,utekrarsayisi };
	// EN COK KULLANILAN SESLI HARFI BULMASINI SAGLAYAN DONGU//
	for (d = 0; d < 5; d++)
	{
		for (j = 0; j < 5; j++)
		{
			if (sayilar[d] < sayilar[j])
			{
				enbuyuk = sayilar[j];
				sayilar[d] = sayilar[j];
				sayilar[d] = enbuyuk;
			}
		}
	}
	//VERILERI EKRANA YAZIYORUZ//
	cout << "sesli harf sayisi:" << sesliharfsayisi << endl;
	cout << "H" << " " << "TS" << " ";
	for (int k = 0; k < enbuyuk; k++)
	{
		cout << " " << setw(2) << k + 1;
	}
	cout << endl;
	cout << "a:" << " " << atekrarsayisi;
	for (int p = 0; p < atekrarsayisi; p++)
	{
		cout << " " << setw(1) << " a ";
	}
	cout << endl;
	cout << "e:" << " " << etekrarsayisi;
	for (int p = 0; p < etekrarsayisi; p++)
	{
		cout << " " << setw(1) << " e ";
	}
	cout << endl;
	cout << "i:" << " " << itekrarsayisi;
	for (int p = 0; p < itekrarsayisi; p++)
	{
		cout << " " << setw(1) << " i ";
	}
	cout << endl;
	cout << "o:" << " " << otekrarsayisi;
	for (int p = 0; p < otekrarsayisi; p++)
	{
		cout << " " << setw(1) << " o ";
	}
	cout << endl;
	cout << "u:" << " " << utekrarsayisi;
	for (int p = 0; p < utekrarsayisi; p++)
	{
		cout << " " << setw(1) << " u ";
	}
	cout << endl;
	return 0;
}

