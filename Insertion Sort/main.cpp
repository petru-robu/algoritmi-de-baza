#include <bits/stdc++.h>
#define S_MAX 10001
using namespace std;
ifstream fin("../vector.in");

void InsertionSort(int v[], int n)
{
  for(int i=2 ; i <= n ; i++)
  {
    int x=v[i];
    int p=i-1;
    while(p >= 0 && v[p] > x)
        v[p+1] = v[p], p --;
    v[p+1] = x;
  }
}

int main()
{
  int v[S_MAX], n;
  fin>>n;

  for(int i=1; i<=n; i++)
    fin>>v[i];

  InsertionSort(v, n);

  for(int i=1; i<=n; i++)
    cout<<v[i]<<' ';

  return 0;
}
