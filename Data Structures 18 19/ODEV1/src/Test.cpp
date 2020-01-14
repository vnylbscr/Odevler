#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include "KovaKontrol.hpp"
#include "Kova.hpp"
HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE); //renkler icin nesne olusturuyoruz
using namespace std;

//@author mert genç
int main()
{
     setlocale(LC_ALL,"Turkish");
     int secenek,kovaAdeti;
     cout<<"Kova adeti:";
     cin>>kovaAdeti;

     KovaKontrol *kovadizisi=new KovaKontrol(kovaAdeti);
     KovaKontrol *kovaadresdizi=new KovaKontrol(kovaAdeti);
        

     KovaKontrol *tempdizi;

     for (int i = 0; i < kovaAdeti; i++)
     {
         tempdizi[i]=kovadizisi[kovaAdeti];
     }
     

     do
     {
          cout<<"1-Toplari Yerlestir"<<endl;
          cout<<"2-Toplari Yok Et"<<endl;
          cout<<"3-Kovalari Degistir"<<endl;
          cout<<"4-Toplari Degistir"<<endl;
          cout<<"5-Kovalari Tersten Yerlestir"<<endl;
          cout<<"6-Toplari Tersten Yerlestir"<<endl;
          cout<<"7-Cikis"<<endl;
          
          cin>>secenek;
          switch (secenek)
          {
          case 1:
          int a,b;
          cout<<"Hangi kovayi:";
          cin>>a;
          cout<<"hangi kova ile:";
          cin>>b;
          kovadizisi->ToplariYerlestir1(tempdizi,topDizisi);
          break;
          case 2:

          
          default:cout<<"menu tuslarini kullaniniz.."<<endl;
               continue;
          }

          
     } while (secenek!=7);
     
     
     
    
     
          
     delete kovadizisi;
     delete topDizisi;
     delete topadresdizi;
     delete kovaadresdizi;
     cin.get();
     cin.ignore();


     return 0;

}
