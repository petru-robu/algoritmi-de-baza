#include <bits/stdc++.h>
using namespace std;
ifstream fin("vector.txt");

int a[101], v[101], n, k, pos=3;

void citire()
{
  fin>>n;
  for(int i=0;i<n;i++) fin>>a[i];
  for(int i=0;i<n;i++) v[i]=a[i];
}
void reset()
{
  for(int i=0;i<n;i++) v[i]=a[i];
}
void afisare()
{
  for(int i=0;i<n;i++) cout<<v[i]<<' ';
  cout<<'\n';
}

int main()
{
  citire();
  afisare();

  for(int j=pos-1;j<n-1;j++)
    v[j]=v[j+1];
  n--;
  afisare();
  reset();

  for(int i=0;i<n;i++)
  {
    if(v[i]%2!=0)
    {
      for(int j=i;j<n-1;j++)
        v[j]=v[j+1];
      n--;
      i--;
    }
  }
  afisare();
  reset();
}
