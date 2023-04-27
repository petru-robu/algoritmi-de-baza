#include <bits/stdc++.h>
using namespace std;

int sol[101], viz[101], n, p;

void write()
{
    for(int i=1; i<=p; i++)
        cout<<sol[i]<<' ';
    cout<<'\n';
}

bool ok(int pas)
{
    return (sol[pas] > sol[pas-1] && !viz[sol[pas]]);
}

void back(int pas)
{
    if(pas == p+1)
    {
        write();
        return ;
    }

    for(int i=1; i<=n; i++)
    {
        sol[pas] = i;
        if(ok(pas))
        {
            viz[i]=1;
            back(pas+1);
            viz[i]=0;
        }
    }
}

int main()
{
    cin>>n>>p;
    back(1);
    return 0;
}