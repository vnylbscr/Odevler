#include "Kova.hpp"
#include "KovaKontrol.hpp"
#include "cstdlib"
void Top::getsembol()
{
     sembol=rand()%26+65;   
}
char Top::printsembol()
{
     return sembol;
}

