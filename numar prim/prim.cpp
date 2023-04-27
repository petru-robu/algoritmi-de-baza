#include <bits/stdc++.h>
using namespace std;

bool prim(int n)
{
    if(n<=1)
        return 0;
    if(n == 2)
        return 1;
    if(n % 2 == 0)
        return 0;
    
    for(int p=3; p<=sqrt(n); p++)
        if(n%p == 0)
            return 0;
    return 1;
}

int main(int argc, char **argv)
{   
    if(argc <= 1)
    {
        cout<<"Introduce un numar!\n";
        return -1;
    }

    int n = stoi(argv[1]);
    
    if(prim(n))
        cout<<"Numarul "<<n<<" este prim!\n";
    else
        cout<<"Numarul "<<n<<" NU este prim!\n";   

    return 0;
}