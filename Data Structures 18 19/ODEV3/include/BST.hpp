#ifndef BST_HPP
#define BST_HPP
#include "Dugum.hpp"
#include "DosyaOkuma.hpp"
//Mert Genç b161210045 mert.genc1@ogr.sakarya.edu.tr
//Sinan Demir g141210075
//09.12.2019
//veri yapilari 3.odev
//1A Grubu
using namespace std;

class BST
{
public:

     BST();
     ~BST();
     void Ekle(int data);
     void DizidenEkle(int * dizi,int size);
     void Sil(int);
     void postOrderPrint();
     void DeleteBST();
     int ToplamSoySayisi();
     int findMax();
     int findMin();
     Dugum* Ara(int);
     Dugum* RootDondur();
     int SoySayisiBul(Dugum *dugum);
     void RootDegistir(Dugum *);
private:
     Dugum *root; //kok dugum **
     void pEkle(int deger,Dugum *agac);
     void postOrderPrint(Dugum*);
     void pDeleteBST(Dugum *leaf);
     int ToplamSoySayisi(Dugum*);
     int toplamSoySayisi;
     int findMax(Dugum*);
     int findMin(Dugum*);
     Dugum* Sil(int,Dugum*);
     Dugum* Ara(int,Dugum*);

     

};



#endif
