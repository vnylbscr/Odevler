#include "pch.h"
#include <iostream>																
#include <stdlib.h>
#include "time.h"
#include <algorithm>
#include "string"

																	/****************************************************************************
																	**					SAKARYA ÜNİVERSİTESİ
																	**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
																	**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
																	**				          PROGRAMLAMAYA GİRİŞİ DERSİ
																	**
																	**				ÖDEV NUMARASI…...:2.ÖDEV
																	**				ÖĞRENCİ ADI...............: MERT GENÇ
																	**				ÖĞRENCİ NUMARASI.:b161210045
																	**				DERS GRUBU…………:PROGRAMLAMAYA GİRİŞ 2.ÖĞRETİM D GRUBU
																	****************************************************************************/



using namespace std;
void Sirala(char &x, char &y); //fonksiyon prototipi yapılıyor
const int Satir = 5; // Satir ve sutun sabit degiskenleri olusturuluyor.
const int Sutun = 10;


int main()
{

	setlocale(LC_ALL, "Turkish");
	srand(time(NULL));
	bool Tekrarsiz = true;
	char Harf[10][10]; //harf'i 10x10 yapmamın sebebi, 5x10 yapınca bellekle ilgili bir hata veriyor. sanırım bellekteki ayrılan yeri aşıyoruz.
	int random;
	int x;

	for (int i = 1; i <= Satir; i++)
	{
		for (int j = 1; j <= Sutun; j++)
		{
			do
			{
				random = (rand() % 57) + 65; //rand fonksiyonu ile rastgele tamsayı üretiyorum, +65 dememin sebebi sayıların ascii kodlarına denk gelmesi.
				// Bu sayılar başka işaretlere denk geliyor. Bizim istediğimiz ascii kodlarına denk gelmiyor
				if (random == 91 || random == 92 || random == 93 || random == 94 || random == 95 || random == 96)
				{
					random = (rand() % 26) + 97; //Bu şekilde herhangi kücük harf ataması yapıyorum zaten alt kısımda kontrol ediyorum


				}

				// Burada tekrarsız random sayı uretiliyor 

				for (int x = 1; x <= Satir; x++)
				{
					for (int y = 1; y <= Sutun; y++)
					{

						Tekrarsiz = true; //Tekrarsız başta true olarak atandı.
						if (Harf[x][y] == random) // Sayıyı atamadan önce dizide o değer var mı diye kontrol ediyor.
						{
							Tekrarsiz = false; // Aynı sayı üretildiğinde o satir ve sutuna gidip tekrar sayı üretiyor.
							y = Sutun;
							x = Satir;
						}

					}
				}
			} while (!Tekrarsiz);

			Harf[i][j] = random;

		}

	}

	// sıralanmamış diziyi ekrana yazdırıyor 
	cout << "Sıralanmamış ve rastgele dizi:" << endl;
	for (int i = 1; i <= Satir; i++)
	{
		for (int j = 1; j <= Sutun; j++)
		{
			cout << Harf[i][j];
			cout << "   ";

		}
		cout << endl;
	}

	cout << "-----------------------------------------" << endl;


	// burada sıralama yapılıyor.

	for (int k = 1; k <= Satir; k++)
	{
		for (int m = 1; m <= Sutun; m++)
		{
			x = m + 1;

			for (int i = k; i <= Satir; i++)
			{
				for (int j = x; j <= Sutun; j++)
				{
					if (Harf[k][m] > Harf[i][j])

					{
						Sirala(Harf[k][m], Harf[i][j]);
					}

				}
				x = 0;
			}
		}
	}

	//sıralanmış dizi yazdırılıyor
	cout << "Sıralanmış dizi:" << endl;
	for (int i = 1; i <= Satir; i++)
	{
		for (int j = 1; j <= Sutun; j++)
		{
			cout << Harf[i][j];
			cout << "   ";

		}
		cout << endl;
	}

	return 0;
}

// Bu fonksiyon ile dizi elemanlarının adresleri kullanılarak sıralama yapılıyor adreslerini almamın sebebi fonksiyonun dizinin içindeki değişkenleri değil değerlerini alması
// eğer adres tanımlaması yapmasaydık dizinin elemanlarına etki etmezdi.
void Sirala(char &x, char &y)
{
	int temp = x;
	x = y;
	y = temp;
}
