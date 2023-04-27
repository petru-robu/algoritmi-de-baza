#include <bits/stdc++.h>
#define S 101
using namespace std;
ifstream fin("matrice.txt");

int a[S][S], n;
void citire(){fin>>n;
for(int i=1;i<=n;i++)
  for(int j=1;j<=n;j++) fin>>a[i][j];}

int main()
{
  citire();
  cout<<"Diangonala Principala: \n";
  for(int i=1; i<=n; i++)
    cout<<a[i][i]<<' ';
  cout<<"\n\n";

  cout<<"Diangonala Secundara: \n";
  for(int i=1; i<=n; i++)
    cout<<a[i][n-i+1]<<' ';
  cout<<"\n\n";
}
