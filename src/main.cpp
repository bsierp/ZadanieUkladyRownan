#include <iostream>
#include "UkladRownanLiniowych.hh"
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
int main()
{
  UkladRownanLiniowych Ukl;
  std::fstream plik;
  string nazwa;
  do {
    if(!plik.good())
    cerr << "Nie udało się wczytac poprawnie pliku, lub dane w pliku sa niepoprawne. Sprobuj ponownie."<<endl;
  plik.clear();
  cin >> nazwa;
  plik.open(nazwa);
  plik >> Ukl;
  plik.close();
  }
  while(!plik.good());
  cout<<"Uklad rownan do rozwiazania"<<endl<<Ukl<<endl;
  cout<<"Rozwiazaniem rownania jest:"<<endl;
  for(int i=0;i<ROZMIAR;++i){
    cout<<"x_"<<i+1<<'='<<Ukl.rozwiaz()[i]<<endl;
  }
  cout<<"Wektor bledu:("<<Ukl.wektor_bledu()<<")"<<endl;
  cout<<"Dlugosc wektora bledu:"<<Ukl.wektor_bledu().dlugosc()<<endl;
}
