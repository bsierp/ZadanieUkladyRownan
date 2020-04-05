#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "Wektor.hh"
#include <iostream>
using std::cout;
class Macierz {
  Wektor tab[ROZMIAR];
  public:
  Macierz(Wektor w1, Wektor w2, Wektor w3);
  Macierz();
  const Wektor operator *(const Wektor & skl) const;
  double wyznacznik() const;
  const Macierz  operator + (const Macierz & skl) const;
  const Macierz  operator - (const Macierz & skl) const;
  const Macierz operator * (const Macierz & skl) const;
  const Macierz  operator * (double skl) const;
  bool operator == (const Macierz & skl) const;
  bool operator != (const Macierz & skl) const;
  const Macierz Transponuj() const;
  const Macierz & Odwroc() const;
  const Wektor & operator [] (int index) const;
  Wektor & operator[](int index);
};
std::istream& operator >> (std::istream &strm, Macierz &Mac);
std::ostream& operator << (std::ostream &strm, const Macierz &Mac);


#endif
