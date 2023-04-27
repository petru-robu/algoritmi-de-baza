#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

void SelectionSort(int v[], int n)
{
  for(int i=1; i<=n-1; i++)
    for(int j=i+1; j<=n; j++)
      if(v[i]>v[j])
        swap(v[i], v[j]);
}

int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  SelectionSort(v, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
