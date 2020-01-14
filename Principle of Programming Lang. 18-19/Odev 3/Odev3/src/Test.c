#include "RastgeleKarakter.h"
/*
@Mert Genç 09.04.2019 NO:b161210045  ©
@Emirhan Erdoğu NO:g161210003 ©


SAU CS

mail: mert.genc1@ogr.sakarya.edu.tr
mail: emirhan.erdogu@ogr.sakarya.edu.tr

*/

int main()
{
	
	// RastgeleKarakter sinifindan nesne uretiliyor(sozde).
	RastgeleKarakter rk=RastgeleKarakterOlustur();
	
	char *dizi="gyuecn";
	
	printf("Rastgele Karakter: %c\n",rk->RastgeleChar(rk));

	printf("Rastgele Karakter: %c\n",rk->RastgeleChar(rk));
	
	//girilen degere gore rastgele karakter ureten fonksiyon testi. 
	printf("Rastgele 3 Karakter: %s\n",rk->RastgeleParametreliUret(rk,3));
	
	printf("Rastgele 3 Karakter: %s\n",rk->RastgeleParametreliUret(rk,3));
	
	printf("Rastgele 5 Karakter: %s\n",rk->RastgeleParametreliUret(rk,5));

	printf("Rastgele 5 Karakter: %s\n",rk->RastgeleParametreliUret(rk,5));

	//girilen harfler arasindan rastgele karakter secen fonksiyon testi.
	rk->RastgeleAraDegerParametreli(rk,5,'a','k');
	
	rk->RastgeleAraDegerParametreli(rk,5,'a','k');
	
	printf("\n");
	// Parametre kadar rastgele kelime sayisi olan ve cumle ureten  fonksiyon testi.
	rk->RastgeleCumleUret(rk,3);
	
	printf("\n");
	
	rk->RastgeleCumleUret(rk,5);	
	
	printf("\n");
	
	//belirtilen karakterlere gore aralarindan rastgele secim yapan fonksiyon testi.
	printf("Belirtilen karakterler (%s) : %s",dizi,rk->KullaniciGirisineGoreCharUret(rk,dizi,1));
	
	printf("\n");
	
	printf("Belirtilen karakterler (%s) : %s",dizi,rk->KullaniciGirisineGoreCharUret(rk,dizi,2));
	
	printf("\n");
	
	printf("Belirtilen karakterler (%s) : %s",dizi,rk->KullaniciGirisineGoreCharUret(rk,dizi,3));
	
	printf("\n");
	
	// detayli bir test icin 100 karakter ekrana basiliyor.
	printf("Rastgele 100 Karakter: %s \t\n",rk->RastgeleParametreliUret(rk,100));

	printf("----------------------------------------------------");

	rk->YokEt(rk); //rastgelekarakter sinifi icin yikici metod(sozde) cagiriliyor.
	
	return 0;
}