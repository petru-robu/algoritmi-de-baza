#include <bits/stdc++.h>
using namespace std;

void factprimi(int x)
{
    int d=2, p=0;
    while(x > 1)
    {
        p = 0;
        while(x % d == 0)
        {
            p++;
            x/=d;
        }

        if(p != 0)
            cout<<d<<'^'<<p<<' ';
        
        d++;
        
        if(d*d>x && x>1)
            d = x;
    }
}

int main()
{
    factprimi(1260);
}