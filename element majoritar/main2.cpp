#include <bits/stdc++.h>
using namespace std;

ifstream fin("elmaj.in");
ofstream fout("elmaj.out");

int v[1000000];
bool ok=1;

int el_maj(int n)
{
    int maj=v[0],dif=1;
    for(int i=1; i<n; i++)
    {
        if(v[i]!=maj)
        {
            dif--;
            if(dif==0)
            {
                maj=v[i];
                dif=1;
            }
        }
        else dif++;
    }
    if(dif==0) ok=0;
    return maj;
}

int main()
{
    int n;
    fin>>n;
    for(int i=0; i<n; i++)
        fin>>v[i];
    int maj=el_maj(n);
    if(ok==1)
    {
        int nr=0;
        for(int i=0; i<n; i++)
        {
            if(v[i]==maj)
                nr++;
        }
        fout<<maj<<' '<<nr;
        return 0;
    }
    fout<<-1;
    return 0;
}
