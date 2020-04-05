#include "Wektor.hh"
#include <cmath>

Wektor::Wektor(){
   for(int i=0;i<ROZMIAR;i++){
       tab[i]=0;
   }
}
Wektor::Wektor(double xx, double yy, double zz){
    tab[0]=xx;
    tab[1]=yy;
    tab[2]=zz;
}
const double & Wektor::operator [](int index) const{
    if(index<0||index>ROZMIAR){
        cerr<<"Skladowa wektora pozaś zakresem"<<endl;
        exit(1);
    }
    return this->tab[index];
    }
double & Wektor::operator [](int index){
    if(index<0||index>ROZMIAR){
        cerr<<"Skladowa wektora poza zakresem"<<endl;
        exit(1);
    }
    return this->tab[index];
}
  const Wektor Wektor::operator +(const Wektor & skl) const{
      Wektor wynik;
            for(int i=0;i<ROZMIAR;i++){
                wynik[i]=this->tab[i]+skl[i];
            }
      
        return wynik;
  }
  const Wektor Wektor::operator - (const Wektor & skl) const{
     Wektor wynik;
            for(int i=0;i<ROZMIAR;i++){
                wynik[i]=this->tab[i]-skl[i];
            }
        return wynik;
  }
  double Wektor::operator *(const Wektor & skl) const{
      double wynik,czesciowa;
      for(int i=0;i<ROZMIAR;i++){
          czesciowa=this->tab[i]*skl[i];
          wynik+=czesciowa;
      }
      return wynik;
  }
  const Wektor Wektor::operator *(double skl) const{
     Wektor wynik;
            for(int i=0;i<ROZMIAR;i++){
                wynik[i]=this->tab[i]*skl;
            }
      return wynik;
  }
  double Wektor::dlugosc() const{
      double wynik,czesciowa;
   for(int i=0;i<ROZMIAR;i++){
          czesciowa=this->tab[i]*this->tab[i];
          wynik+=czesciowa;
      }
      return sqrt(wynik);
  }
  bool Wektor::operator == (const Wektor & skl) const{
      bool rowne;
      for(int i=0;i<ROZMIAR;i++){
      rowne=this->tab[i]==skl[i];
      if(rowne==1)
      continue;
      else
      {
          return false;
      }
      }
      return true;
  }
  bool Wektor::operator != (const Wektor & skl) const{
      return !(*this==skl);
  }
std::istream & operator >> (std::istream &strm, Wektor &Wek){
    for(int i=0;i<ROZMIAR;i++){
strm>>Wek[i];
    }
return strm;
}
std::ostream & operator << (std::ostream &strm, const Wektor &Wek){
for(int i=0;i<ROZMIAR;i++){
    strm<<Wek[i]<<' ';
}
}