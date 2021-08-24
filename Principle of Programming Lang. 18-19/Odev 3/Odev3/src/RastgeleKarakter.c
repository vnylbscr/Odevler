#include "RastgeleKarakter.h"


/*
@Mert Genç 09.04.2019 NO:b161210045  ©



SAU CS

mail: mert.genc1@ogr.sakarya.edu.tr

*/


RastgeleKarakter RastgeleKarakterOlustur()
{
	RastgeleKarakter this;
	this=(RastgeleKarakter)malloc(sizeof(struct RASTGELEKARAKTER));
	this->super=RandomOlustur(); //kalitim almis gibi yapiyoruz.
	this->RastgeleChar=&_RastgeleChar;
	this->RastgeleParametreliUret=&_RastgeleParametreliUret;
	this->RastgeleAraDegerParametreli=&_RastgeleAraDegerParametreli;
	this->RastgeleCumleUret=&_RastgeleCumleUret;
	this->KullaniciGirisineGoreCharUret=&_KullaniciGirisineGoreCharUret;
	this->YokEt=&_RastgeleKarakterYokEt;
	
}

char _RastgeleChar(const RastgeleKarakter this)
{
	
	this->karakter=this->super->RandomSayiUret(this->super,0,122);
	
	while(this->karakter<65 || this->karakter>122 || (this->karakter<97 && this->karakter>90 ))
	this->karakter=this->super->RandomSayiUret(this->super,0,122);
	
	return this->karakter;
	
}
//string donduren girilen sayi kadar rastgele harf ureten fonksiyon.
char* _RastgeleParametreliUret(const RastgeleKarakter this,int girilenSayi)
{
	this->dizi=(char*)malloc(sizeof(char)*girilenSayi);
	
	for(int i=0;i<girilenSayi;i++)
	{
		this->dizi[i]=this->RastgeleChar(this);
	}
	
	return this->dizi;
	
}

void _RastgeleAraDegerParametreli(const RastgeleKarakter this,int girilenSayi,char param1,char param2)
{	
	char chr=this->RastgeleChar(this);
	
	if(param1<90) // java kodunda oldugu gibi buyuk harf verilirse kucuk harfe ceviriyor.
	{
		param1=param1+32;
	}
	
	
	if(param2<90) param2=param2+32; // ayni sekilde diger parametre icinde kucuk harfe ceviriyor.
	
	if(param1>param2)
	{
		char degistir=param1;
		
		param1=param2;
		
		param2=degistir;
		
	}
	
	 int i = 0;
	 
     printf("\nVerilen %d Karakter(%c,%c): ",girilenSayi,param1,param2);
	 
     while (i < girilenSayi) 
	 {
       
		if(chr>param1 && chr<param2)
		{
			
		printf("%c",chr);
		
		chr=this->RastgeleChar(this);
		
		i++;
		
		}
		
		else chr=this->RastgeleChar(this);
			
	} 
	
} 
//rastgele cumle ureten fonksiyon.
void _RastgeleCumleUret(const RastgeleKarakter this,int kelimeSayisi)
{
	
		
	printf("Rastgele Cumle: ");
	
	for(int i=0;i<=kelimeSayisi;i++)
	{
		printf("%s",this->RastgeleParametreliUret(this,this->super->RandomSayiUret(this->super,2,8))); //kelime en az 2 en fazla 8 harf aliyor.
		printf(" ");
	
	}
	
} 
//kullanicinin girdigi degerlere gore rastgele karakter ureten fonskiyon.
char* _KullaniciGirisineGoreCharUret(const RastgeleKarakter this,char *dizi,int girilenSayi)
{
	
	int uzunluk=strlen(dizi); //dizinin eleman sayisini buluyor.
	// gonderilen dizinin icinden kac eleman istedigini parametre ile aliyor ve istenilen uzunlukta heap bellek bolgesinde bir char dizisi olusturuluyor.
	char *str=(char*)malloc(sizeof(char)*girilenSayi);
	
	
	
	for(int i=0;i<girilenSayi;i++)
	{
		int rastgele=this->super->RandomSayiUret(this->super,0,uzunluk);
		
		str[i]=dizi[rastgele];
	}
	
	return str;
	
	
	
	
}
//Rastgele karakter yoket fonksiyonu tahsis ettigimiz alanlari geri iade ediyoruz. bu fonksiyonla random sinifida yok ediliyor. 
void _RastgeleKarakterYokEt(RastgeleKarakter this)
{
	if(this==NULL) return;
	if(this->super!=NULL) this->super->YokEt(this->super);


	free(this->dizi);
	free(this);
}
