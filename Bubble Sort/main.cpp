#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

void BubbleSort(int v[], int n)
{
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n-i; j++)
      if(v[j]>v[j+1])
        swap(v[j], v[j+1]);
}

int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  BubbleSort(v, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
