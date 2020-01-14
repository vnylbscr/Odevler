#include "Random.h"


/*
@Mert Genç 09.04.2019 NO:b161210045  ©
@Emirhan Erdoğu NO:g161210003 ©



SAU CS

mail: mert.genc1@ogr.sakarya.edu.tr
mail: emirhan.erdogu@ogr.sakarya.edu.tr

*/
 

Random RandomOlustur()
{
	
	Random this;
	this=(Random)malloc(sizeof(struct RANDOM)); //malloc ile heap bellek bolgesinde yer tahsis ediliyor.
	
	this->RandomSayiUret=&_RandomSayiUret;
	this->lfsr=0xACE1u; //struct icindeki elamanlara ilk degerler atandi.
	this->t=0;
	this->bit=0x00000;
	this->YokEt=&RandomYokEt; //fonksiyon gostericileri fonksiyonlara atandi.
	
	return this;
	
}


uint _RandomSayiUret(const Random this,uint min,uint max)//min ve max arasinda rastgele sayi ureten fonksiyon.
{
	//struct icindeki degiskenlere ilk deger atandi.
	this->min=min;
	this->max=max;
	
	//>> operatoru ile verilerin bit kalibi, belirtilen pozisyon sayisi ile saga kaydırılabilir 
	//veri saga kaydirildiginda, bastaki sifirlar sifir ile doldurulur. 
	//sag kaydirma operatoru ikili operatordur  
	//ikili, iki arguman gerektiren operator anlamina gelir
	if(this->min == this->max) return this->min;
	this->p = (int*)malloc(sizeof(int));
    this->t = this->t^(int)this->p;
    this->bit  = ((this->lfsr >> 0) ^ (this->lfsr >> 2) ^ (this->lfsr >> 3) ^ (this->lfsr >> 5) ) & 1;
    this->lfsr = ((this->bit<<15) | (this->lfsr>>1) | this->t)%this->max;
    while(this->lfsr<this->min){
		
        this->lfsr = this->lfsr + this->max - this->min;
    }
	
    return this->lfsr;
}

// heap bellek bolgesinde tahsis edilen yerler free fonksiyonu ile serbest birakiliyor.
void RandomYokEt(Random this)
{
	
	if(this==NULL) return;
	
	free(this->p);
	free(this);
	
}


