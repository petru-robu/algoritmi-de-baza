#include <bits/stdc++.h>
using namespace std;
ifstream fin("elmaj.in");
ifstream fin1("elmaj.in");
ofstream fout("elmaj.out");

int main()
{
    int x, nr, ap=0, n;
    fin>>n;
    for(int i=0; i<n; i++)
    {
        fin>>x;
        if(ap==0)
        {
            ap=1;
            nr=x;
        }
        else
        {
            if(x != nr)
                ap--;
            else 
                ap++;
        }
    }

    if(ap)
    {
      ap=0;
      fin1>>n;
      for(int i=0;i<n;i++)
      {
        fin1>>x;
        if(x==nr) 
            ap++;
      }
      if(ap >= (n/2+1))
      {
        fout<<nr<<' '<<ap;
        return 0;
      }
    }
    
    fout<<-1;
    return 0;
}
