#include "UkladRownanLiniowych.hh"


Wektor UkladRownanLiniowych::rozwiaz(){
    Wektor wynik;
    Macierz trans=this->A.Transponuj();
    double epsilon=0.00000000001;
    if(abs(this->A.wyznacznik())<epsilon){
    cerr<<"Uklad nie jest ukladem cramera"<<endl;
    exit(1);
    }
    for(int i=0;i<ROZMIAR;++i){
       trans[i]=this->b;
       wynik[i]=trans.wyznacznik()/this->A.wyznacznik();
       trans[i]=this->A.Transponuj()[i];
    }
    return wynik;
}
  UkladRownanLiniowych::UkladRownanLiniowych (){
      Macierz M;
      Wektor W;
      A=M;
      b=W;
  }
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
      Macierz Mpom;
      Wektor Wpom;
      strm >> Mpom >> Wpom;
        UklRown.zmien_macierz_glowna(Mpom.Transponuj());
        UklRown.zmien_wektor_wolny(Wpom);    
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
Wektor UkladRownanLiniowych::wektor_bledu() const{
    UkladRownanLiniowych wynik=*this;
    Wektor rozwiazania=wynik.rozwiaz();
    Wektor bledu;
    bledu=this->A*rozwiazania-this->b;
    return bledu;
}