#ifndef KOVAKONTROL_HPP
#define KOVAKONTROL_HPP
#include "Kova.hpp"
#include "Top.hpp"

class KovaKontrol
{
private:

public:
Kova *kovatemp;
Top *toptemp;

void ToplariYerlestir1(Kova topdizisi[],Kova kovadizisi[]);
void ToplariYokEt2(Kova topdizisi[],Kova kovadizisi[]);
void KovalariDegistir3(int,int,Kova kovadizisi[]);
void ToplariDegistir4(int,int,Kova topDizisi[]);
void KovalariTerstenYerlestir5(int, Kova kovadizisi[]);
void toplariterstenyerlestir6(int, Kova topdizisi[]);
KovaKontrol(int);
};

#endif