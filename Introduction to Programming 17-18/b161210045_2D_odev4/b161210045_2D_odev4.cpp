#include <iostream>
#include <string>
#include <cstring>
using namespace std;

char *SifreliAlfabeOlustur(char *metin, char *key, char sifreliAlfabe[255]);

class Sifre
{
public: //sinif olusturuldu ve uyeler ile metodlar tanimlandi.
	Sifre(char*alfabe, char*sifre);
	Sifre();

	char *sifrele(char text[255], char  sAlfabe[255], char sifreliMesaj[255]);
	char *sifrecoz(char text[255], char sAlfabe[255], char desifreSifre[255]);
	void sifreKelimesiAta(char*);
private:
	const char *alfabe; //alfabeyi const olarak tanimlama sebebim parametresiz kurucu fonksiyonda deger atamasi yapilamamasi. yani baslangic degeri icin degerler birbiriyle uyusmuyor, aynı zamanda fazla sayida baslatici degeri aliyor.
	char* sifreKelimesi;
};

Sifre::Sifre(char * alfabe, char * sifre) //alfabe icin kurucu fonksiyon, girilen alfabeyi sinif icerisindeki alfabeye atiyor.
{
	Sifre::alfabe = alfabe;
}

Sifre::Sifre() //alfabe'ye varsayilan degeri atayan kurucu fonskiyon.
{

	Sifre::alfabe = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

char * Sifre::sifrele(char text[255], char sAlfabe[255], char sifreliMesaj[255]) //sifreleme islemi yapiliyor, parametre olarak girilen metin, sifreli alfabe ve dondurulecek deger olan sifreli mesaji aliyor.
{
	int length = strlen(alfabe);

	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] >= alfabe[0] && text[i] <= alfabe[length - 1])
		{
			sifreliMesaj[i] = (text[i] + sAlfabe[i]) % strlen(Sifre::alfabe);
			sifreliMesaj[i] += Sifre::alfabe[0] + 1;
			if (sifreliMesaj[i] > 90)
			{
				sifreliMesaj[i] = sifreliMesaj[i] - 26;
			}
			else if (sifreliMesaj[i] < 65)
			{
				sifreliMesaj[i] = sifreliMesaj[i] + 26;
			}
		}
		else
			sifreliMesaj[i] = text[i];
	}

	sifreliMesaj[strlen(text)] = '\0'; //diziyi sonlandiriyor
	return sifreliMesaj; //sifreli mesaji donduren fonksiyon.

}

char * Sifre::sifrecoz(char text[255], char sAlfabe[255], char desifreSifre[255]) //parametre olarak sifreli mesaj,sifreli alfabe ve desifre sifre alan, orijinal metini donduren sifrecoz fonksiyonu.
{
	int length = strlen(alfabe); //alfabenin uzunlugunu bir degiskene atiyorum.

	for (int i = 0; i < strlen(text); i++)
	{
		if (text[i] >= Sifre::alfabe[0] && text[i] <= Sifre::alfabe[length - 1])
		{
			desifreSifre[i] = (text[i] - sAlfabe[i] + length) % length;
			desifreSifre[i] += alfabe[0] - 1;
			if (desifreSifre[i] > 90)
			{
				desifreSifre[i] = desifreSifre[i] - 26;
			}
			else if (desifreSifre[i] < 65)
			{
				desifreSifre[i] = desifreSifre[i] + 26;
			}
		}
		else
		{
			desifreSifre[i] = text[i];
		}


	}

	desifreSifre[strlen(text)] = '\0'; //char dizisini sonlandiriyor
	return desifreSifre;
}

void Sifre::sifreKelimesiAta(char *)
{


}

int main()
{
	char duzMetin[255], key[10], sifreliMesaj[255], desifreMesaj[255], sifrelialfabe[255], alfabe[100];

	cout << "Alfabeyi giriniz (Buyuk harflerle giriniz, varsayilan alfabeyi kullanmak icin enter tusuna basiniz) : ";
	cin.getline(alfabe, 100);
	if (alfabe[0] == '\0') //kontrol yapiliyor, eğer hicbirsey girilmemisse alfabe olarak varsayilan olani kullaniyor.
	{
		cout << "GECERLI ALFABE:  " << "ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
		Sifre sifre; //parametresiz nesne olusturarak varsayılan alfabeyi kullanıyor.
		cout << "SIFRE:";  //sifre ve metin aliniyor.
		cin.getline(key, 255);
		cout << "METIN:";
		cin.getline(duzMetin, 255);

		SifreliAlfabeOlustur(duzMetin, key, sifrelialfabe);  //sifreli alfabeyi olustran fonksiyon asagida tanimlandi.
		sifre.sifrele(duzMetin, sifrelialfabe, sifreliMesaj); //sifre sinifindan sifrele metodu cagiriliyor. ve metin sifreleniyor.
		sifre.sifrecoz(sifreliMesaj, sifrelialfabe, desifreMesaj); // sifre sinifindan sifrecoz metodu cagiriliyor. ve metinin sifresi cozuluyor.
		cout << "SIFRELI ALFABE : ";
		for (int i = 0; i < strlen(duzMetin); i++)  //ekrana yazdiriliyor.
		{
			cout << sifrelialfabe[i];
		}
		cout << endl;
		cout << "SIFRELENMIS MESAJ: ";
		for (int i = 0; i < strlen(sifrelialfabe); i++)
		{
			cout << sifreliMesaj[i];
		}
		cout << endl;
		cout << "DESIFRE MESAJ:  ";
		for (int i = 0; i < strlen(sifrelialfabe); i++)
		{
			cout << desifreMesaj[i];
		}
	}
	else //kullanici alfabe girince alfabeye gore sifreleme yapiyor.
	{

		Sifre sifre(alfabe, key); //parametreli kurucu fonsksiyonu cagiriyorum ve kullanicinin girdigi alfabeyi sinifim icindeki alfabeye atiyorum.
		cout << "SIFRE: ";
		cin.getline(key, 255); 
		cout << "METIN: ";
		cin.getline(duzMetin, 255);
		SifreliAlfabeOlustur(duzMetin, key, sifrelialfabe);
		sifre.sifrele(duzMetin, sifrelialfabe, sifreliMesaj);
		sifre.sifrecoz(sifreliMesaj, sifrelialfabe, desifreMesaj);
		cout << "SIFRELI ALFABE : ";
		for (int i = 0; i < strlen(duzMetin); i++)
		{
			cout << sifrelialfabe[i];
		}
		cout << endl;
		cout << "SIFRELENMIS MESAJ: ";
		for (int i = 0; i < strlen(sifrelialfabe); i++)
		{
			cout << sifreliMesaj[i];
		}
		cout << endl;
		cout << "DESIFRE MESAJ:  ";
		for (int i = 0; i < strlen(sifrelialfabe); i++)
		{
			cout << desifreMesaj[i];
		}


	}

	cin.get();
}
char *SifreliAlfabeOlustur(char *metin, char *key, char sifreliAlfabe[255]) //girilen metinin sifre kadar tekrariyla olusan sifreli alfabeyi donduren fonksiyon.
{

	for (int i = 0, j = 0; i < strlen(metin); i++, ++j)
	{
		if (j == strlen(key))
		{
			j = 0;
		}
		sifreliAlfabe[i] = key[j];
	}
	sifreliAlfabe[strlen(metin)] = '\0';
	return sifreliAlfabe;
}