#include <bits/stdc++.h>
using namespace std;

int sol[101], n;

void write(int pas)
{
    for(int i=1; i<=pas; i++)
        cout<<sol[i]<<' ';
    cout<<'\n';
}

bool ok(int pas)
{
    if(pas == 1)
        return 1;
    else
        return sol[pas]>sol[pas-1];
}

void back(int pas)
{
    for(int i=1; i<=n; i++)
    {   
        sol[pas] = i;
        if(ok(pas))
        {
            write(pas);
            back(pas+1);
        }
    }
}



int main()
{
    cin>>n;
    back(1);
}