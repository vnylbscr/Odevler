#include "KovaKontrol.hpp"
#include <cstdlib>

void KovaKontrol::ToplariYerlestir1(Kova topdizisi[],Kova kovadizisi[])
{

}
void KovaKontrol::ToplariDegistir4(int a,int b,Kova kovadizisi[])
{
     Kova temp;
     temp=kovadizisi[a-1];
     kovadizisi[a-1]=kovadizisi[b-1];
     kovadizisi[b-1]=temp;

}

KovaKontrol::KovaKontrol(int kovaadet)
{

     Kova *kovadizisi=new Kova[kovaadet];
     Top *topdizisi=new Top[kovaadet];

}