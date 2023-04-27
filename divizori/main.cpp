#include <bits/stdc++.h>
using namespace std;

void divizori(int n)
{
  for(int d=1; d*d<=n; d++)
     if(n%d == 0)
     {
       cout<<d<<" ";
       if(d*d!=n)
        cout<<n/d<<" ";
     }
}

int main()
{
  divizori(16);
  return 0;
}
