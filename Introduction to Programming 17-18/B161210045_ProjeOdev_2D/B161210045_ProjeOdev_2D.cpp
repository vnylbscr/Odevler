#include	<iostream>
#include	<Windows.h>
#include	<time.h>
#include	<cstring>

											/****************************************************************************
											**					SAKARYA ÜNİVERSİTESİ
											**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
											**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
											**				          PROGRAMLAMAYA GİRİŞİ DERSİ
											**
											**				ÖDEV NUMARASI…...:PROJE ODEVI	
											**				ÖĞRENCİ ADI...............: MERT GENÇ	
											**				ÖĞRENCİ NUMARASI.: B161210045
											**				DERS GRUBU…………: 2.ÖĞRETİM C GRUBU
											****************************************************************************/


using namespace std;

enum YON {
	YON_ASAGI = 1,
	YON_YUKARI = 2,
	YON_SAG = 3,
	YON_SOL = 4,
	YON_SBT = 5

};
struct ucakElemanlar
{
	int coordX;
	int coordY;
	YON yon;

};
struct mermiElemanlar
{
	char MermiKarakter = 254;
	int coordX;
	int coordY;
	YON yon;


};
struct dusmanElemanlar
{
	char DusmanKarakter = 245;
	int coordX;
	int coordY;
	YON yon;


};


const int genislik = 80;
const int yukseklik = 20;
const int ucakBoyutu = 5;
const int maksMermiSayisi = 400;
const int maksDusmanSayisi = 5;
char sahne[genislik][yukseklik];
int	mermiSayisi = 0;
int DusmanSayisi = 0;
ucakElemanlar ucak[ucakBoyutu];
mermiElemanlar mermi[maksMermiSayisi];
dusmanElemanlar Dusman[maksDusmanSayisi];
char tus[256];

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(consoleHandle, &info);
	info.bVisible = false;
	SetConsoleCursorInfo(consoleHandle, &info);
}  //kursoru gizleyen fonksiyon.
void klavyeOku(char tuslar[])
{
	for (int i = 0; i < 256; i++)
	{
		tuslar[i] = (char)(GetAsyncKeyState(i) >> 8);
	}
}
void sahneyiTemizle()
{
	for (int i = 0; i < yukseklik; i++)
	{
		for (int j = 0; j < genislik; j++)
		{
			sahne[j][i] = ' ';
		}

	}
}
void sinirlariOlustur()
{
	for (int x = 0; x < genislik; x++)
	{
		sahne[x][0] = 219;
		sahne[x][yukseklik - 1] = 219;
	}
	for (int i = 0; i < yukseklik; i++)
	{
		sahne[0][i] = 219;
		sahne[genislik - 1][i] = 219;
	}
}
void sahneyiCiz()
{
	for (int i = 0; i < yukseklik; i++)
	{
		for (int j = 0; j < genislik; j++)
		{
			cout << sahne[j][i];
		}
		cout << endl;
	}

}

void ucagiDoldur()
{
	for (int i = 0; i < ucakBoyutu; i++)
	{
		ucak[i].coordX = i + 1;
		ucak[i].coordY = i + 6;
		if (i == 3)
		{
			ucak[i].coordX = i - 1;
			ucak[i].coordY = i + 6;

		}
		else if (i == 4)
		{
			ucak[i].coordX = i - 3;
			ucak[i].coordY = i + 6;
		}

	}
}
void ucagiCiz()
{
	for (int i = 0; i < ucakBoyutu; i++)
	{
		int x = ucak[i].coordX;
		int y = ucak[i].coordY;
		sahne[x][y] = 179;

	}


}

void ucagiHareketEttir()
{
	klavyeOku(tus);

	for (int i = 0; i < ucakBoyutu; i++)
	{

		for (int i = 0; i < ucakBoyutu; i++)
		{

			if (tus[38] != 0) //klavyedeki yon tuslari ile ucagi hareket ettiriyor
			{
				ucak[i].yon = YON_YUKARI;

				if (ucak[0].coordY == 0 && ucak[1].coordY == 1 && ucak[2].coordY == 2 && ucak[3].coordY == 3 && ucak[4].coordY == 4) //ucagin yukardan cikip assagiya gecmesini engelliyor
				{
					ucak[i].yon = YON_SBT;
				}
				else
				{
					ucak[i].coordY--;
					ucak[i].yon = YON_SBT;
				}


			}
			if (tus[40] != 0) //down tusunu temsil ediyor.
			{
				ucak[i].yon = YON_ASAGI;

				if (ucak[0].coordY == 15 && ucak[1].coordY == 16 && ucak[2].coordY == 17 && ucak[3].coordY == 18 && ucak[4].coordY == 19)//ucagin assagidan girip yukariya gecmesini engelliyor
				{
					ucak[i].yon = YON_SBT;
				}
				else
				{
					ucak[i].coordY++;
					ucak[i].yon = YON_SBT;
				}
			}
		}
	}
}

void mermiyiOlustur() //2.index ucagın ortası oldugundan
{
	mermi[mermiSayisi].coordX = ucak[2].coordX;

	mermi[mermiSayisi].coordY = ucak[2].coordY;
}
void mermiDoldur() //mermiyi sahne dizisine aktaran fonksiyon.
{
	for (int i = 0; i < maksMermiSayisi; i++)
	{
		int x = mermi[i].coordX;
		int y = mermi[i].coordY;
		if (x >= genislik - 2)
		{
			x = genislik - 1;
			mermi[i].yon = YON_SBT;
			sahne[x][y] = 254;

		}
		else if (y == yukseklik)
		{
			y = yukseklik - 1;
			mermi[i].yon = YON_SBT;
			sahne[x][y] = 254;
		}
		else
		{
			sahne[x][y] = mermi[i].MermiKarakter;
		}

	}
}

void mermiyiHareketEttir() //mermi sadece saga dogru hareket edecegi icin x koordinatini artırıyor.
{
	for (int i = 0; i < maksMermiSayisi; i++)
	{
		if (mermi[mermiSayisi].yon == YON_SAG)
		{
			mermi[i].coordX++;
		}

	}
}
void mermiUret() //mermi sayisini artiyor ve mermiyi olustur fonksiyonu ile yeni bir mermi dizisi olusturuyor.
{
	mermiSayisi++;
	mermiyiOlustur();
}
void mermiKlavyeKontrol()
{
	klavyeOku(tus);

	if (tus[' '] != 0) //bosluk tusu ile mermi yolluyor.
	{
		mermiUret();
		mermi[mermiSayisi].yon = YON_SAG;
	}
}
void DusmaniOlustur() //dusman olusturuluyor dusman sayisi maksimuma esitlendiginde artirmayi durduruyor.
{

	DusmanSayisi++;
	int maksDusmanSayisi = 5;
	if (DusmanSayisi > maksDusmanSayisi)
	{
		DusmanSayisi = maksDusmanSayisi;
	}
	else
	{
		for (int i = 0; i < DusmanSayisi; i++) //dusmanin dikey ve yatay koordinatlari ataniyor. dikey koordinati rand fonksiyonu ile ataniyor.
		{
			int RandomY = rand() % 15 + 3;
			Dusman[i].coordX = genislik - 2;
			Dusman[i].coordY = RandomY;
		}
	}


}
void DusmaniSahneyeKoy() //dusmani sahne dizisine aktariyor ve ekranda kalmasi saglaniyor.
{
	for (int i = 0; i < DusmanSayisi; i++)
	{
		int x = Dusman[i].coordX;
		int y = Dusman[i].coordY;
		sahne[x][y] = Dusman[i].DusmanKarakter;
	}
}
void DusmaniHareketEttir() //dusman hareket ettiriliyor dusmanin yatay koordinati sinira ulastiginda ekrandan siliniyor.
{
	for (int i = 0; i < DusmanSayisi; i++)
	{
		if (Dusman[i].coordX == 1)
		{
			int x = Dusman[i].coordX;
			int y = Dusman[i].coordY;
			sahne[x][y] = ' ';
			DusmanSayisi--;
		}
		else
		{
			Dusman[i].coordX--;
		}
		do
		{
			DusmaniOlustur();
		} while (DusmanSayisi != maksDusmanSayisi);

	}
}
void DusmanVeMermiCarpisma() //dusman ve merminin yatay ve dikey koordinatlari birbirine esitlendiginde, ordaki dusman ve mermi karakteri siliniyor.
{
	int score = 0;
	for (int i = 0; i < mermiSayisi; i++)
	{
		for (int j = 0; j < DusmanSayisi; j++)
		{
			if (mermi[i].coordX == Dusman[j].coordX && mermi[i].coordY == Dusman[j].coordY)
			{
				mermi[j].MermiKarakter = ' ';
				Dusman[j].DusmanKarakter = ' ';
				score++;
			}

		}
	}
}

int main()
{
	HideCursor();
	ucagiDoldur();
	DusmaniOlustur();
	while (true)
	{

		sahneyiTemizle();
		sinirlariOlustur();
		klavyeOku(tus);
		mermiKlavyeKontrol();
		gotoxy(0, 0);
		DusmaniSahneyeKoy();
		DusmaniHareketEttir();
		mermiyiOlustur();
		mermiDoldur();
		mermiyiHareketEttir();
		DusmanVeMermiCarpisma();
		ucagiHareketEttir();
		ucagiCiz();
		sahneyiCiz();
		Sleep(5);

	}

	system("pause");

}


