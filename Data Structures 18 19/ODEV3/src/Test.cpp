#include <iostream>
#include "BST.hpp"
using namespace std;
//Mert Genç b161210045 mert.genc1@ogr.sakarya.edu.tr
//Sinan Demir g141210075
//09.12.2019
//veri yapilari 3.odev
//1A Grubu
int main()
{
     int benimAgacSkor=0;
     int rakipAgacSkor=0;
     string benimAgacString="Benim Agac Postorder:\n";
     string rakipAgacString="Rakip Agac Postorder:\n";
     DosyaOkuma *dosyaBenim=new DosyaOkuma("benim.txt");
     DosyaOkuma *dosyaRakip=new DosyaOkuma("rakip.txt");
     Dugum *kokBenim,*kokRakip=new Dugum;

     BST *benimAgac=new BST();
     BST *rakipAgac=new BST();

     benimAgac->DizidenEkle(dosyaBenim->sayiDizisiniVer(),dosyaBenim->sayiDizisiLength());
     rakipAgac->DizidenEkle(dosyaRakip->sayiDizisiniVer(),dosyaRakip->sayiDizisiLength());

     Dugum *root=new Dugum;
     root=benimAgac->RootDondur();
     cout<<"SS:"<<benimAgac->SoySayisiBul(root);
     benimAgac->postOrderPrint();


    

     
    
     
     /*
     while (true)
     {
     cout<<benimAgacString;
     benimAgac->postOrderPrint();
     cout<<"Benim agac toplam soy sayisi:"<<benimAgac->ToplamSoySayisi();  
     cout<<"\n----------------------"<<endl;
     cout<<rakipAgacString;
     rakipAgac->postOrderPrint();
     cout<<"Rakip agac toplam soy sayisi:"<<rakipAgac->ToplamSoySayisi();
     if (benimAgac->ToplamSoySayisi() > rakipAgac->ToplamSoySayisi()) //rakip kazanma durumu
     {
          rakipAgacSkor++;
          cout<<"\n---------RAKIP KAZANDI --------------"<<endl;
          int Karsimax=benimAgac->findMax();
          rakipAgac->Ekle(Karsimax); //kazanan taraf karsi tarafin en buyuk degerini kendi agacina ekler
          benimAgac->Sil(Karsimax); //karsi taraftaki agactan silme

          kokRakip=rakipAgac->RootDondur();
          benimAgac->Ekle(kokRakip->data); 
          rakipAgac->Sil(kokRakip->data);

     }
     else if (benimAgac->ToplamSoySayisi() < rakipAgac->ToplamSoySayisi()) //benim kazanma durumu
     {
          benimAgacSkor++;
          cout<<"\n------------TEBRIKLER TURU KAZANDINIZ---------------"<<endl;
          int Karsimax=rakipAgac->findMax();
          benimAgac->Ekle(Karsimax); //kazanan taraf karsi tarafin en buyuk degerini kendi agacina ekler
          rakipAgac->Sil(Karsimax); //karsi taraftaki agactan silme

          kokBenim=benimAgac->RootDondur();
          rakipAgac->Ekle(kokBenim->data); //Karsi tarafa ekleniyor
          benimAgac->Sil(kokBenim->data); //kendinden siliniyor
           
     }
     
     else if (benimAgac->ToplamSoySayisi()==rakipAgac->ToplamSoySayisi()) //soy sayilari esit olma durumu
     {
          
          //root dondur
          kokBenim=benimAgac->RootDondur();
          kokRakip=rakipAgac->RootDondur();

          benimAgac->Ekle(kokRakip->data);
          rakipAgac->Ekle(kokBenim->data);
          // root sil
          benimAgac->Sil(kokBenim->data);
          rakipAgac->Sil(kokRakip->data);
          
          cout<<"\nDURUM BERABERE!!!! KOK DUGUMLER DEGISTIRILDI!!"<<endl;
          
          
     }
     cout<<"\nSKOR\n"<<endl;
     cout<<"Benim: "<<benimAgacSkor<<endl;
     cout<<"Rakip: "<<rakipAgacSkor<<endl;
     cout<<endl;
     
     if (rakipAgacSkor==5 || benimAgacSkor==5)
     {
          break;
     }

     cin.get();

     } //dongu sonu
     
     if (benimAgacSkor>rakipAgacSkor)
     {
          cout<<"-----------------------------------------"<<endl;
          cout<<"!!!!TEBRIKLER OYUNU KAZANDINIZ....!!!!!!!"<<endl;
     }
     else 
     {
          cout<<"----------------------------------------"<<endl;
          cout<<"UZGUNUM OYUNU KAYBETTINIZ......!!!!!!!!!"<<endl;
     }

     
   


     
     benimAgac->~BST(); //heapten tahsis edilen yerleri iade ediyoruz
     rakipAgac->~BST();
     dosyaBenim->~DosyaOkuma();
     dosyaRakip->~DosyaOkuma();
     delete kokBenim,kokRakip;
     */
     return 0;
}