#ifndef CIFTYONLUBAGILLISTE_HPP
#define CIFTYONLUBAGILLISTE_HPP
#include "Dugum.hpp"
#include "DosyaOkuma.hpp"
using namespace std;
//@Mert Genç
//b161210045
//18.11.2019
//1-A Veri Yapilari 2.Odev
//mert.genc1@ogr.sakarya.edu.tr
class BagilListe
{
     private:
     Dugum *head;
     Dugum *tail;
     int uzunluk;
     int sayac=0;
     int kacAdimSolda;
     int KazanilanByte=0;
     public:
     void Ekle(string);
     int DugumNoDondur(string);
     void stringDizisiniListeyeEkle(string*,BagilListe*,int);
     void Yazdir();
     bool DegerVarMi(string);
     BagilListe();
};

#endif
