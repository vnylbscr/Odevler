#ifndef RANDOM_H
#define RANDOM_H

#include "stdio.h"
#include "stdlib.h"

/*
@Mert Genç 09.04.2019 NO:b161210045  ©
@Emirhan Erdoğu NO:g161210003 ©



SAU CS

mail: mert.genc1@ogr.sakarya.edu.tr
mail: emirhan.erdogu@ogr.sakarya.edu.tr

*/

typedef unsigned int uint; //unsigned int'i bolca kullanacagim icin yeni bir tur(kisaltma) yazdim.

struct RANDOM
{
	uint lfsr;
	uint bit;
	uint t;
	uint max;
	uint min;
	int *p;
	
	uint (*RandomSayiUret)(struct RANDOM*,uint,uint); //rastgele sayi ureten fonksiyon(gostericisi).
	
	void (*YokEt)(struct RANDOM*);
};

typedef struct RANDOM* Random; //yeni bir tur tanimliyorum.

Random RandomOlustur();
uint _RandomSayiUret(const Random,uint,uint);
void RandomYokEt(Random);


#endif
