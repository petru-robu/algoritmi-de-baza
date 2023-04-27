#include <bits/stdc++.h>
#define S 101
using namespace std;
ifstream fin("matrice.txt");

int a[S][S], n;
void citire(){fin>>n;
//for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) fin>>a[i][j];
}
void afisare(){for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)
  cout<<a[i][j]<<' '; cout<<'\n';}}

int main()
{
  citire();
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
    {
     if (i==j || i+j==n+1) // diagonale
        a[i][j] = 1;
     if (i < j && i+j < n+1) //nord
        a[i][j] = 2;
     if (i > j && i+j > n+1) //sud
        a[i][j] = 3;
     if (i > j && i+j < n+1) //est
        a[i][j] = 4;
     if (i < j && i+j > n+1) //vest
        a[i][j] = 4;
    }
  afisare();
}
