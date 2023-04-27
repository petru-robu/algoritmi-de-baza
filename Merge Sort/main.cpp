#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

int tmp[S_MAX];

void MergeSort(int v[], int st, int dr)
{
  if(st < dr)
  {
    int m = st+(dr-st)/2;
    MergeSort(v, st, m);
    MergeSort(v, m+1, dr);

    int i=st, j=m+1, k=0;
    while(i<=m && j<=dr)
    {
      if(v[i]<v[j])
        tmp[++k] = v[i++];
      else
        tmp[++k] = v[j++];
    }

    while(i<=m)
      tmp[++k] = v[i++];
    while(j<=dr)
      tmp[++k] = v[j++];

    for(int i=st, j=1; i<=dr; i++, j++)
      v[i] = tmp[j];
  }
  else return;

}

int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  MergeSort(v, 1, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
