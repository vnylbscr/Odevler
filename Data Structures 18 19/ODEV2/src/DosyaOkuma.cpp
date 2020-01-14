#include "DosyaOkuma.hpp"
#include <fstream>
#include "sstream"
#include <string>
#include "algorithm"
#include <iostream>
using namespace std;
//@Mert Genç
//b161210045
//1-A Veri Yapilari 2.Odev
//18.11.2019
//mert.genc1@ogr.sakarya.edu.tr
DosyaOkuma::DosyaOkuma(string dosyaAdi)
{
  ifstream inFile;
  inFile.open(dosyaAdi); //dosya aciliyor
  stringstream strStream;
  strStream << inFile.rdbuf(); //dosya okunuyor
  string strarr = strStream.str(); //str fonksiyonu dosyanin tum icerigini tutuyor once txt'nin tum icerigi strarr degiskenine aktariliyor, alttaki satirda bosluga gore parcalaniyor.
  boslukSayisi=count(strarr.begin(),strarr.end(),' '); //bosluk sayisina gore kelime olacagindan
  kelimeDizisi=new string[boslukSayisi+1]; //bosluk sayisinin bir fazlasi kadar kelime olacagindan 
  stringstream ssin(strarr);
  int i=0;
  while(ssin.good() && i<boslukSayisi+1) //kelime kelime ayriliyor ve yeni bir diziye aktariiliyor
  {
        ssin>>kelimeDizisi[i];
        ++i;
  }
	  inFile.close(); //dosya kapatiliyor
}
string* DosyaOkuma::stringDizisiniVer()
{
     return kelimeDizisi;
}
int DosyaOkuma::kelimeSayisiniVer() //kelime sayisini donduren fonksiyon
{
    return boslukSayisi+1;
}
