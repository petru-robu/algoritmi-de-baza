#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cifmax=0, cifmin=9;
    cin>>n;

    while(n)
    {
        cifmax = max(cifmax, n%10);
        cifmin = min(cifmin, n%10);
        n/=10;
    }

    cout<<cifmax<<' '<<cifmin<<'\n';
    return 0;
}