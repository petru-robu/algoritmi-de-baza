#include <bits/stdc++.h>
using namespace std;
#define NMAX 100001
ifstream fin("scmax.in");
ofstream fout("scmax.out");

int n, v[NMAX], dp[NMAX], sol[NMAX], l=0, aint[NMAX];

int main()
{

  fin>>n;
  for(int i=1;i<=n;i++) fin>>v[i], dp[i]=1;


  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<i;j++)
      if(v[j]<v[i] && dp[j]+1>dp[i])
        dp[i]=dp[j]+1;
  }

  int m=dp[1], posmax=1;
  for(int i=2;i<=n;i++)
  {
    if(m<dp[i])
    {
      m=dp[i];
      posmax=i;
    }
  }
  fout<<m<<'\n';


  sol[++l]=v[posmax];
  for(int i=posmax;i>=1;i--)
  {
    if(dp[i]==dp[posmax]-1 && v[i]<v[posmax])
    {
      sol[++l]=v[i];
      posmax=i;
    }
  }

  for(int i=l;i>=1;i--)
    fout<<sol[i]<<' ';

  return 0;
}
