#ifndef RASTGELE_KARAKTER_H
#define RASTGELE_KARAKTER_H
/*
@Mert Genç 09.04.2019 NO:b161210045  ©
@Emirhan Erdoğu NO:g161210003 ©

SAU CS

mail: mert.genc1@ogr.sakarya.edu.tr
mail: emirhan.erdogu@ogr.sakarya.edu.tr

*/
 
#include "Random.h"
#include "string.h"

struct RASTGELEKARAKTER
{
	Random super;
	char karakter;
	char *dizi;
	char (*RastgeleChar)(struct RASTGELEKARAKTER*);
	char* (*RastgeleParametreliUret)(struct RASTGELEKARAKTER*,int);
	void (*RastgeleAraDegerParametreli)(struct RASTGELEKARAKTER*,int,char,char);
	void (*RastgeleCumleUret)(struct RASTGELEKARAKTER*,int);
	char* (*KullaniciGirisineGoreCharUret)(struct RASTGELEKARAKTER*,char*,int);
	void (*YokEt)(struct RASTGELEKARAKTER*);
};


typedef struct RASTGELEKARAKTER* RastgeleKarakter;

RastgeleKarakter RastgeleKarakterOlustur();
char _RastgeleChar(const RastgeleKarakter);
char* _RastgeleParametreliUret(const RastgeleKarakter,int);
void _RastgeleAraDegerParametreli(const RastgeleKarakter,int,char,char);
void _RastgeleCumleUret(const RastgeleKarakter,int);
char* _KullaniciGirisineGoreCharUret(const RastgeleKarakter,char*,int);
void _RastgeleKarakterYokEt(RastgeleKarakter);




#endif