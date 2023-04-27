#include <bits/stdc++.h>
using namespace std;

ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

void euclid(int a, int b, int &d, int &x, int &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        int x0, y0;
        euclid(b, a % b, d, x0, y0);
        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int main()
{
  int T; 
  fin>>T;
  while(T--)
  {
    int a, b, c, x, y, d;
    fin>>a>>b>>c;
    euclid(a, b, d, x, y);

    if(c%d)
      fout<<0<<' '<<0<<'\n';
    else
      fout<<x*(c/d)<<' '<<y*(c/d)<<'\n';
  }
  
  return 0;
}