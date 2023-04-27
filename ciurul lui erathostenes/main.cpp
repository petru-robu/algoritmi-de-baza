#include <bits/stdc++.h>
#define N 2000005
using namespace std;

ifstream fin("ciur.in");
ofstream fout("ciur.out");

int main()
{
  int n, cnt=0;
  char ciur[N];
  fin>>n;

  for(int i=2; i<=n; i++)
        ciur[i] = 1;

  for(int i=2; i<=n; i++)
    if(ciur[i]==1)
    {
      ++cnt;
      for(int j=i*2; j<=n+1; j=j+i)
        ciur[j]=0;
    }
  fout<<cnt;

  return 0;
}