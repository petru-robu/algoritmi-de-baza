#include <bits/stdc++.h>
using namespace std;

int sol[40], n;
bool aux[40];

bool valid(int);
void afisare(int);
void back(int);

int main()
{
  cin>>n;
  for(int i=1; i<=n; i++)
    aux[i] = false;
  back(1);
}

void afisare()
{
  for(int i=1; i<=n; i++)
    cout<<sol[i]<<' ';
  cout<<'\n';
}

bool valid(int pas)
{
  if(aux[sol[pas]] == 1)
    return false;
  else
    return true;
}

void back(int pas)
{
  if(pas==n+1)
  {
    afisare();
    return;
  }
  for(int i=n; i>=1; i--)
  {
    sol[pas] = i;
    if(valid(pas))
    {
      aux[i] = 1;
      back(pas+1);
      aux[i] = 0;
    }
  }
}
