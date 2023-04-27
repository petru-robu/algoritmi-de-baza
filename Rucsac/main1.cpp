#include <bits/stdc++.h>
#define MAXN 5010
#define MAXG 10010
using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");


int N, G;
int W[MAXN], P[MAXN];
int D[MAXN][MAXG];

int main()
{

    fin>>N>>G;
    for(int i=1; i<=N; i++)
        fin>>W[i]>>P[i];

    for(int i = 1; i <= N; i++)
        for(int cw = 0; cw <= G; cw++)
        {
            // Mai intai nu punem obiectul i.
            D[i][cw] = D[i-1][cw];

            // Daca acest lucru duce la o solutie curenta mai buna, adaugam obiectul i la o solutie anterioara.
            if(W[i] <= cw)
                D[i][cw] = max(D[i][cw], D[i - 1][cw - W[i]] + P[i]);
        }

    fout<<D[N][G];


}
