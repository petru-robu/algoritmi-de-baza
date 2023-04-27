#include <bits/stdc++.h>
using namespace std;
#define N 1001

ifstream fin("mars.in");
ofstream fout("mars.out");

int n, v[N], mars[N]={0};

void read()
{
  fin>>n;
  for(int i=1; i<=n; i++)
    fin>>v[i];

  int t;
  fin>>t;
  while(t--)
  {
    int x,y,z;
    fin>>x>>y>>z;
    mars[x] += z;
    mars[y+1] -=z;
  }
}

void sump()
{
  for(int i=1; i<=n; i++)
  {
    mars[i]+=mars[i-1];
    v[i] += mars[i];
  }
}

int main()
{
  read();
  sump();

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';
}
