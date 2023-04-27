#include <bits/stdc++.h>
using namespace std;
#define MOD 1999999973
#define ll long long

ifstream fin("lgput.in");
ofstream fout("lgput.out");

int main()
{
  ll n, p, mask=1, rez=1;
  fin>>n>>p;
  for(int i=0;i<32;i++)
  {
    if(p & mask)
    {
      rez*=n;
      rez%=MOD;
    }
    n*=n;
    n%=MOD;
    mask = mask<<1;
  }
  fout<<rez;

}
