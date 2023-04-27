#include <bits/stdc++.h>
using namespace std;

ifstream fin("inversmodular.in");
ofstream fout("inversmodular.out");

void euclid(int a, int b, int &d, int &x, int &y)
{
    if(!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        int x0, y0;
        euclid(b, a % b, d, x0, y0);
        x = y0;
        y = x0 - (a / b) * y0;
    }
}

int main()
{
  int A, N, d, x, y;
  fin>>A>>N;
  euclid(A, N, d, x, y);
  cout<<d;
  if(x<=0)
    x = N + x%N;

  fout<<x;

  return 0;
}
