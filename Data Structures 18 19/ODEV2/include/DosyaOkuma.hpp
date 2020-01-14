#ifndef DOSYAOKUMA_HPP
#define DOSYAOKUMA_HPP
#include "fstream"
#include "string"
//@Mert Genç
//b161210045
//18.11.2019
//1-A Veri Yapilari 2.Odev
//mert.genc1@ogr.sakarya.edu.tr
class DosyaOkuma
{
          private:
          std::string *kelimeDizisi; //kelime dizisi
          std::string dosyaAdi; //dosya Adi
          int boslukSayisi;
          public:
          DosyaOkuma(std::string);
          int kelimeSayisiniVer(); 
          std::string* stringDizisiniVer();
};


#endif