#include <bits/stdc++.h>
#define SMAX 100
using namespace std;

void match(char pat[], char txt[])
{
    int m = strlen(pat), n = strlen(txt);
    int p=0, t=0, h=1;

    const int d = 256, q = INT_MAX;

    for(int i=0; i<m-1; i++)
        h = (h * d) % q;

    for(int i=0; i<m; i++)
    {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for(int i=0; i <= n - m; i++)
    {
        if(p==t)
        {
            bool mat = true;
            for(int j=0; j<m; j++)
            {
                if(txt[i+j] != pat[j])
                    {mat=false; break;}
            }

            if(mat==true)
                cout<<"Potrivire gasita la pozitia "<<i<<'\n';
            mat=false;
        }

        if(i < n-m)
        {
            t = ( d*(t - txt[i]*h) + txt[i+m] ) % q;

            if(t < 0)
                t = t+q;
        }
    }

}

int main()
{
    char s[SMAX], pat[SMAX];
    cin.getline(s, 255);
    cin.getline(pat, 255);

    match(pat, s);

    return 0;
}
