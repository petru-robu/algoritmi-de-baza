#include <bits/stdc++.h>
using namespace std;

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int cmmmc(int a, int b)
{
    return a * b / cmmdc(a,b);
}

int main()
{
    cout<<cmmdc(2, 5)<<'\n';
    return 0;
}