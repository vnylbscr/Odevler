#include "DosyaOkuma.hpp"
//Mert Genç b161210045 mert.genc1@ogr.sakarya.edu.tr
//Sinan Demir g141210075
//09.12.2019
//veri yapilari 3.odev
//1A Grubu

//dosya okuma yapici metodu parametre olarak dosya adini alir
DosyaOkuma::DosyaOkuma(string DosyaAdi)
{
            ifstream inFile;
            inFile.open(DosyaAdi); //dosya aciliyor
            stringstream strStream;
            strStream << inFile.rdbuf(); //sayilar okunuyor 
            sayiString = strStream.str(); // dosya icerigi string bir degiskene aktariliyor
            boslukSayisi=count(sayiString.begin(),sayiString.end(),' '); 
            sayiDizisi=new int[boslukSayisi+1]; //bosluk sayisinin bir fazlasi kadar sayi olacagindan 
            stringstream ssin(sayiString);
            int i=0;
            while(ssin.good() && i<boslukSayisi+1) //bosluga gore ayrildi  ve sayilar yeni bir diziye aktariiliyor
            {
                  ssin>>sayiDizisi[i];
                  ++i;
            }

            inFile.close();


}
int * DosyaOkuma::sayiDizisiniVer()
{
        return sayiDizisi;
}
int DosyaOkuma::sayiDizisiLength()
{
        return boslukSayisi+1;
}

DosyaOkuma::~DosyaOkuma()
{
        delete sayiDizisi;
}