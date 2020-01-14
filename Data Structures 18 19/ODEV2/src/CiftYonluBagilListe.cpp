#include "CiftYonluBagilListe.hpp"
#include <iostream>
using namespace std;
//@Mert Genç
//b161210045
//1-A Veri Yapilari 2.Odev
//18.11.2019
//mert.genc1@ogr.sakarya.edu.tr
BagilListe::BagilListe()
{
     uzunluk=0;     
     tail=nullptr;
     head=nullptr;
     sayac=0;

}
void BagilListe::Ekle(string deger) //basa eleman ekliyor. 
{
     Dugum *yeniDugum=new Dugum();
     int ayniDugum=0; //ayni dugumden varsa datasinda 0 yazdigindan 1 byte yer kapliyor onu cikariyoruz
     if(DegerVarMi(deger)==true) //eger listede o degerden varsa yeni dugumun datasina 0 yaziyor.
     {
           yeniDugum->next=head;
           yeniDugum->data="0";
           yeniDugum->prev=nullptr;
           head->prev=yeniDugum;
           head=yeniDugum;
           yeniDugum->DugumNo=sayac;
           sayac++;
           ayniDugum++;
           yeniDugum->kacAdimSolda=(yeniDugum->DugumNo)-DugumNoDondur(deger); //dugum sayisindan ayni olan ilk dugumu cikarirsak kac adim solda oldugunu buluruz
           KazanilanByte+=deger.size()-ayniDugum; //kazanc hesabi yapiliyor
     }
     else //listede ayni eleman yoksa elemani ekliyor
     {
          if (head==nullptr) //liste bos ise
           {
                head=yeniDugum;
                yeniDugum->prev=nullptr;
                yeniDugum->data=deger;
                yeniDugum->next=nullptr;
                tail=yeniDugum;
                yeniDugum->DugumNo=sayac;
                sayac++;
           }
           else //liste bos degil ise
           {
               yeniDugum->next=head;
               yeniDugum->data=deger;
               yeniDugum->prev=nullptr;
               head->prev=yeniDugum;
               head=yeniDugum;
               yeniDugum->DugumNo=sayac;
               sayac++;
               
           }
     }
}
void BagilListe::Yazdir() //tersten yazdiriyor cunku basa eleman eklemistik
{
     Dugum *temp=new Dugum();
     temp=tail;
     cout<<"NULL"; //basdugumun oncekisi yani null
     while (temp!=nullptr)
     {
          cout<<"< - "<<temp->data<<"  "<<temp->kacAdimSolda<<" ->";
          
          temp=temp->prev;
     }
     cout<<"NULL"; //son dugumun sonrasi null oldugundan
     cout<<endl;
     cout<<"Toplam kazanc : "<<KazanilanByte<<" byte "<<endl; //kazanc yazdiriliyor
}

void BagilListe::stringDizisiniListeyeEkle(string *array,BagilListe *liste,int size) 
{
     for (int i = 0; i <size; i++) //burada size demeden array.length() yazdim fakat hataya yol aciyor.
     {
          liste->Ekle(array[i]);
     }

}
bool BagilListe::DegerVarMi(string deger) //deger varsa true yoksa false donduren fonksiyon
{
     Dugum *gezici=new Dugum;
     gezici=head;
     while(gezici!=nullptr)
     {
          if(gezici->data==deger)
          {
               return true;
               break;
          }
          gezici=gezici->next;
     }
     
     return false;
}

int BagilListe::DugumNoDondur(string deger) //dugum no donduren fonksiyon
{
     Dugum *temp=new Dugum;
     temp=head;
     while(temp!=nullptr)
     {
          if (temp->data==deger)
          {    
               return temp->DugumNo;
               break;
          }
          temp=temp->next;
     }
     
} 
