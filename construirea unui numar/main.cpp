#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv)
{
    if(argc <= 1)
    {
        cout<<"Introduce un numar!\n";
        return -1;
    }
    
    int n = stoi(argv[1]);
    int p=1, res=0;

    while(n)
    {
        res += (n % 10)*p;
        p *= 10;
        n/=10;
    }

    cout<<res<<'\n';
    return 0;
}