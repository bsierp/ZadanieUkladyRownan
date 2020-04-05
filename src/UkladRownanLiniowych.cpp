#include "UkladRownanLiniowych.hh"


const Wektor & UkladRownanLiniowych::rozwiaz(){}
  UkladRownanLiniowych::UkladRownanLiniowych (){}
  UkladRownanLiniowych::UkladRownanLiniowych(const Macierz & M, const Wektor & W){
      A=M;
      b=W;
  }
  const Wektor & UkladRownanLiniowych::zwroc_wektor_wolny() const{
      return this->b;
  }
  void UkladRownanLiniowych::zmien_wektor_wolny(const Wektor & W){
      this->b=W;
  }
   const Macierz &UkladRownanLiniowych::zwroc_macierz_glowna() const{
       return this->A;
   }
void UkladRownanLiniowych::zmien_macierz_glowna(const Macierz & M){
      this->A=M;
  }
  std::istream& operator >> (std::istream &strm, UkladRownanLiniowych &UklRown){
      return strm;
  }


std::ostream& operator << ( std::ostream &strm, const UkladRownanLiniowych &UklRown){
    for(int i=0;i<ROZMIAR;i++){
        if(i!=ROZMIAR/2)
    strm<<'|'<<UklRown.zwroc_macierz_glowna()[i]<<"||x_"<<i+1<<"| |"<<UklRown.zwroc_wektor_wolny()[i]<<'|'<<endl;
    if(i==ROZMIAR/2)
    strm<<'|'<<UklRown.zwroc_macierz_glowna()[i]<<"||x_"<<i+1<<"|=|"<<UklRown.zwroc_wektor_wolny()[i]<<'|'<<endl;
    }
}
