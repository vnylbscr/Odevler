#include <iostream>
#include "pch.h"
using  namespace std;

/****************************************************************************
										**					SAKARYA ÜNİVERSİTESİ
								**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
									**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
								**				          PROGRAMLAMAYA GİRİŞİ DERSİ
																	**
												**				ÖDEV NUMARASI…...: 1.ÖDEV
												**				ÖĞRENCİ ADI...............: MERT GENÇ
												**				ÖĞRENCİ NUMARASI.: B161210045
												**				DERS GRUBU…………: PROGRAMLAMAYA GİRİŞ 2.ÖĞRETİM D GRUBU
							****************************************************************************/

int main()
{
	int satir, sutun;

	for (satir = 1; satir <= 11; satir++) { /* satir sayisi 11(arada olan bosluk) olacagi icin 1 den 11'e kadar birer birer sayiyor  */
		for (sutun = 1; sutun <= 11; sutun++) { /* sütun sayisi 11(arada olan bosluk) olacagi icin 1 den 11'e kadar birer birer sayiyor */
			if (satir <= 5 && sutun <= 6 - satir || sutun >= 6 + satir) { /*ilk 2 şart satir ve sutun 5 oldugunda araya bosluk koyacagi icin */
				cout << "*";
			}
			else if (satir >= 6 && sutun <= satir - 6 || sutun >= 18 - satir) { 
				cout << "*";
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	return 0;
}

