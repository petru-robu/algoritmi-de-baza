#include <bits/stdc++.h>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");


int main()
{
  int t, n, a, sum;
  fin>>t;
  for(int i=1; i<=t; i++)
  {
    fin>>n;
    sum=0;
    for(int i=1; i<=n; i++)
    {
      fin>>a;
      sum=sum^a;
    }

    if(sum!=0) fout<<"DA\n";
    else fout<<"NU\n";

  }

  fout.close();fin.close();
  return 0;
}
