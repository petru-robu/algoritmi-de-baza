#include <bits/stdc++.h>
#define M 2000005
using namespace std;
ifstream fin("strmatch.in");
ofstream fout("strmatch.out");

int main()
{
  char txt[M], pat[M];
  fin>>pat+1>>txt+1;
  int n =strlen(pat+1), m =strlen(txt+1), pi[M]={0};

  int potriviri[1001], nrpotriviri=0;

  int l=0;
  for(int i=2; i<=n; i++)
  {
    while(l>0 && pat[i]!=pat[l+1])
      l=pi[l];
    if(pat[i]==pat[l+1])
      l++;
    pi[i]=l;
  }

  l=0;
  for(int i=1; i<=m; i++)
  {
    while(l>0 && txt[i]!=pat[l+1])
      l=pi[l];
    if(txt[i]==pat[l+1])
      l++;
    if(l==n)
    {
      nrpotriviri++;
      if(nrpotriviri<=1000)
        potriviri[nrpotriviri] = i-n;
    }
  }

  fout<<nrpotriviri<<'\n';
  if(nrpotriviri>1000)
       nrpotriviri=1000;
   for(int i=1;i<=nrpotriviri; i++)
       fout<<potriviri[i]<<' ';


  return 0;
}
