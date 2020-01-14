#include "Kova.hpp"
#include "KovaKontrol.hpp"
#include "cstdlib"

void Kova::getrenk(int rastgelerenk)
{
     rastgelerenk = rand() % 13 + 1;
	kovaRengi = rastgelerenk;
}
int Kova::printrenk()
{
     return kovaRengi;
}
