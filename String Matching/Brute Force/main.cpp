#include <bits/stdc++.h>
#define SMAX 100
using namespace std;

void match(char pat[], char txt[])
{
    int m = strlen(pat), n = strlen(txt);

    for(int i=0; i<=n-m; i++)
    {
      int j;
      for(j=0; j<m; j++)
        if(txt[i+j] != pat[j])
          break;

      if(j==m)
        cout<<"Potrivire gasita la pozitia "<<i<<'\n';
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
