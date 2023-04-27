#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

void CountingSort(int v[], int n)
{
  int m = v[1];
  for(int i=2; i<=n; i++)
    m = max(m, v[i]);

  int vap[m+1];

  for(int i=0; i<=m; i++)
    vap[i]=0;

  for(int i=1; i<=n; i++)
    vap[v[i]]++;

  int k=0;
  for(int i=0; i<=m; i++)
  {
    while(vap[i]!=0)
    {
      v[++k]=i;
      vap[i]--;
    }
  }

}

int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  CountingSort(v, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
