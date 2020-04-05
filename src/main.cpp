#include <iostream>
#include "UkladRownanLiniowych.hh"



using std::cout;
using std::endl;
using std::cin;

int main()
{
  Wektor w(1,2,3),ww(4,5,6),www(7,8,9);
  Macierz a(w,ww,www);
  UkladRownanLiniowych l(a,w);
  cout<<l;
  cout<<a*a;
  cout<<a.wyznacznik()<<endl;
  cout<<w.dlugosc();

  cout << endl << " Start programu " << endl << endl;
  
  cout <<endl;
}
