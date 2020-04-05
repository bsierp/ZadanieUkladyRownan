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
  const Wektor Macierz::operator *(const Wektor & skl) const {
      Wektor wynik;
     for(int i=0;i<ROZMIAR;i++){
         wynik[i]=this->tab[i]*skl;
     }
      return wynik;
  }
  double Macierz::wyznacznik()const{
      Macierz wynik=*this;
     const double epsilon=0.00000001;
      double det=1;
      for(int j=0;j<ROZMIAR;j++){
          if(this->tab[j].dlugosc()<epsilon||(this->Transponuj()[j].dlugosc()<epsilon)){
            det=0;
            return det;
          }
          for(int i=(j+1);i<ROZMIAR;i++){
            wynik[i]=wynik[i]-(wynik[j]*(wynik[i][j]/wynik[j][j]));
          }
      }
      for(int i=0;i<ROZMIAR;i++){
          int j;
          j=i;
              det*=wynik[i][j];
          }
      
      return det;
  }
  const Macierz Macierz::operator + (const Macierz & skl) const {
      Macierz wynik;
      for(int i=0;i<ROZMIAR;i++){
          wynik[i]=this->tab[i]+skl[i];
      }
      return wynik;
  }
  const Macierz Macierz::operator - (const Macierz & skl) const {
      Macierz wynik;
      for(int i=0;i<ROZMIAR;i++){
          wynik[i]=this->tab[i]-skl[i];
      }
      return wynik;
  }
  const Macierz Macierz::operator * (const Macierz & skl) const{
        Macierz wynik;
       for(int i=0;i<ROZMIAR;i++){
            for(int j=0;j<ROZMIAR;j++){
                wynik[i][j]=this->tab[i]*(skl.Transponuj()[j]);
            }
        }
       return wynik;
  }
  const Macierz Macierz::operator * (double skl) const {
      Macierz wynik;
      for(int i=0;i<ROZMIAR;i++){
          wynik[i]=this->tab[i]*skl;
      }
      return wynik;
  }
  bool Macierz::operator == (const Macierz & skl) const{
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
  bool Macierz::operator != (const Macierz & skl) const{
      return !(*this==skl);
  }
  const Macierz Macierz::Transponuj() const{
      Macierz MTrans;
     for(int i=0;i<ROZMIAR;i++){
         for(int j=0;j<ROZMIAR;j++){
             MTrans[i][j]=this->tab[j][i];
         }
     }
      return MTrans;
  }
  const Macierz & Macierz::Odwroc() const {}
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
  std::istream& operator >> (std::istream &strm, Macierz &Mac){
strm>>Mac[0]>>Mac[1]>>Mac[2];
return strm;
  }
std::ostream& operator << (std::ostream &strm, const Macierz &Mac){
    strm<<Mac[0]<<endl<<Mac[1]<<endl<<Mac[2]<<endl;
}