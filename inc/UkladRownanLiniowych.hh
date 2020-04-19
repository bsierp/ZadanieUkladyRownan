#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <Macierz.hh>


class UkladRownanLiniowych {
  Macierz A;
  Wektor b;
  public:
  Wektor rozwiaz();
  UkladRownanLiniowych ();
  UkladRownanLiniowych(const Macierz & M, const Wektor & W);
  const Wektor & zwroc_wektor_wolny() const;
  void zmien_wektor_wolny(const Wektor & W);
  const Macierz & zwroc_macierz_glowna() const;
  void zmien_macierz_glowna(const Macierz & M);
  Wektor wektor_bledu() const;
};



std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);


std::ostream& operator << ( std::ostream                  &Strm, 
                            const UkladRownanLiniowych    &UklRown
                          );


#endif
