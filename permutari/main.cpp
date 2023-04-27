#include <bits/stdc++.h>
using namespace std;

int sol[100001], viz[100001], n;

void write()
{
    for(int i=1; i<=n; i++)
        cout<<sol[i]<<' ';
    cout<<'\n';
}

bool ok(int pas)
{
    return !viz[sol[pas]];
}

void back(int pas)
{
    if(pas == n+1)
    {
        write();
        return ;
    }

    for(int i=1; i<=n; i++)
    {
        sol[pas] = i;
        if(ok(pas))
        {
            viz[i] = 1;
            back(pas+1);
            viz[i] = 0;
        }      
    }        
}

int main()
{
    cin>>n;
    back(1);
    return 0;
}