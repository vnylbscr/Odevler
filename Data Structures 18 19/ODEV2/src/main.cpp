#include <iostream>
#include "CiftYonluBagilListe.hpp"
#include "DosyaOkuma.hpp"
#include "locale.h"
#include "io.h"
#include "fcntl.h"
//18.11.2019
using namespace std;
//@Mert Genç
//b161210045
//Veri Yapilar 2.Odev
//mert.genc1@ogr.sakarya.edu.tr
int main()
{
    
 
    setlocale(LC_ALL,"Turkish");
    DosyaOkuma *dosya=new DosyaOkuma("icerik.txt"); //dosya okuma islemleri yapiliyor
    string *strArr=dosya->stringDizisiniVer(); //dosyadan okunan kelimeler tek tek bir dizi icerisine aliniyor
    BagilListe *liste=new BagilListe; // Cift yonlu bagilListe olusturuluyor.
    liste->stringDizisiniListeyeEkle(strArr,liste,dosya->kelimeSayisiniVer()); //bagilListe parametre aldigi string dizisini,listeyi ve kelimeSayisini alarak bagil Listeyi olusturuyor.
    liste->Yazdir(); //ekrana yazdirma

    delete strArr; //heap bellek bolgesinden tahsis edilen yeri geri iade ediyoruz
    delete liste;
    delete dosya;
    
    return 0;
}
