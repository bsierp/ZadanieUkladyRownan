#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

using std::cerr;
using std::endl;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {
  double tab[ROZMIAR];
  public:
  Wektor(double xx, double yy, double zz);
  Wektor();
  const double & operator [](int index) const;
  double & operator [](int index);
  const Wektor  operator +(const Wektor & skl) const;
  const Wektor  operator - (const Wektor & skl) const;
  double  operator *(const Wektor & skl) const;
  const Wektor  operator *(double skl) const;
  double dlugosc() const;
  bool operator == (const Wektor & skl) const;
  bool operator != (const Wektor & skl) const;

};

std::istream & operator >> (std::istream &strm, Wektor &Wek);
std::ostream & operator << (std::ostream &strm, const Wektor &Wek);

#endif
