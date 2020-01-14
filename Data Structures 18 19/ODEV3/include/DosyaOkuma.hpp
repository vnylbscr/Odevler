#ifndef DOSYAOKUMA_HPP
#define DOSYAOKUMA_HPP
#include <string>
#include <fstream>
#include "sstream"
#include "algorithm"
//Mert Genç b161210045 mert.genc1@ogr.sakarya.edu.tr
//Sinan Demir g141210075
//09.12.2019
//veri yapilari 3.odev
//1A Grubu
using namespace std;


class DosyaOkuma
{
private:
     int boslukSayisi;
     string sayiString;
     int *sayiDizisi;
     string DosyaAdi;

public:
    int *sayiDizisiniVer();
    int sayiDizisiLength();
    DosyaOkuma(string DosyaAdi); //dosyaAdi parametre

    ~DosyaOkuma();

};





#endif