#include "Macierz.hh"


Macierz::Macierz(){
    for(int i=0;i<ROZMIAR;i++){
        for(int j=0;j<ROZMIAR;j++){
        tab[i][j]=0;
        }
    }
}
Macierz::Macierz(Wektor w1, Wektor w2, Wektor w3){
    tab[0]=w1;
    tab[1]=w2;
    tab[2]=w3;
}
  Wektor Macierz::operator *(const Wektor & skl) const {
      Wektor wynik;
     for(int i=0;i<ROZMIAR;i++){
         wynik[i]=this->tab[i]*skl;
     }
      return wynik;
  }
  double Macierz::wyznacznik()const{
      Macierz wynik=*this;
      int pom=0;//zmienna do zamiany wierszy macierzy 
      int k=0;//zmienna do sprawdzania ilosci zamian wierszy
     double epsilon=0.000000000000001;
      double det=1;
      for(int j=0;j<ROZMIAR;j++){
          if(this->tab[j].dlugosc()<epsilon||(this->Transponuj()[j].dlugosc()<epsilon)){
            det=0;
            return det;
          }
          while (abs(wynik[j][j])<epsilon)
          {
              swap(wynik[j],wynik[++pom]);
              ++k;
          }
          pom=0;
          for(int i=(j+1);i<ROZMIAR;i++){
            wynik[i]=wynik[i]-(wynik[j]*(wynik[i][j]/wynik[j][j]));
          }
      }
      for(int i=0;i<ROZMIAR;i++){
          int j;
          j=i;
              det*=wynik[i][j];
          }
      if(k%2==0)
      return det;
      else
        return -det;
      
  }
  Macierz Macierz::operator + (const Macierz & skl) const {
      Macierz wynik;
      for(int i=0;i<ROZMIAR;i++){
          wynik[i]=this->tab[i]+skl[i];
      }
      return wynik;
  }
  Macierz Macierz::operator - (const Macierz & skl) const {
      Macierz wynik;
      for(int i=0;i<ROZMIAR;i++){
          wynik[i]=this->tab[i]-skl[i];
      }
      return wynik;
  }
  Macierz Macierz::operator * (const Macierz & skl) const{
        Macierz wynik;
       for(int i=0;i<ROZMIAR;i++){
            for(int j=0;j<ROZMIAR;j++){
                wynik[i][j]=this->tab[i]*(skl.Transponuj()[j]);
            }
        }
       return wynik;
  }
  Macierz Macierz::operator * (double skl) const {
      Macierz wynik;
      for(int i=0;i<ROZMIAR;i++){
          wynik[i]=this->tab[i]*skl;
      }
      return wynik;
  }
  bool Macierz::operator == (const Macierz & skl) const{
      double epsilon=0.0000000000001;
      for(int i=0;i<ROZMIAR;i++){
      if(abs(this->tab[i]==skl[i])<epsilon)
      continue;
      else
      {
          return false;
      }
      }
      return true;
  }
  bool Macierz::operator != (const Macierz & skl) const{
      return !(*this==skl);
  }
  Macierz Macierz::Transponuj() const{
      Macierz MTrans;
     for(int i=0;i<ROZMIAR;i++){
         for(int j=0;j<ROZMIAR;j++){
             MTrans[i][j]=this->tab[j][i];
         }
     }
      return MTrans;
  }
  
  const Wektor & Macierz::operator [] (int index) const{
      if(index<0||index>ROZMIAR){
          cerr<<"Indeks macierzy poza zakresem";
          exit(1);
      }
      return tab[index];
  }
  Wektor & Macierz::operator[](int index){
       if(index<0||index>ROZMIAR){
          cerr<<"Indeks macierzy poza zakresem";
          exit(1);
      }
      return tab[index];
  }
  Macierz jednostkowa(){
      Macierz jedn;
      for(int i=0;i<ROZMIAR;++i){
          jedn[i][i]=1;
      }
      return jedn;
  }
  std::istream& operator >> (std::istream &strm, Macierz &Mac){
      for (int i=0;i<ROZMIAR;++i){
strm>>Mac[i];
      }
return strm;
  }
std::ostream& operator << (std::ostream &strm, const Macierz &Mac){
    for(int i=0;i<ROZMIAR;i++){
    strm<<Mac[i]<<endl;
    }
}