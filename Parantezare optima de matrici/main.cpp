#include <bits/stdc++.h>
using namespace std;

ifstream fin("podm.in");
ofstream fout("podm.out");

#define MAXN 505
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define FOR(i, a, b)  for (int i = (a); i <= (b); ++ i)
#define INF LLONG_MAX

typedef long long ll;

ll bst[MAXN][MAXN], d[MAXN];   int n;

int main(void)
{
    fin >> n;
    FOR (i, 0, n)  fin>>d[i];

    FOR(i, 1, n)
      bst[i][i] = 0;

    FOR(i, 1, n - 1)
      bst[i][i + 1] = d[i - 1] * d[i] * d[i + 1];

    FOR(w, 2, n - 1)
      FOR(i, 1, n - w)
      {
        int j = i + w;
        bst[i][j] = INF;
        FOR(k, i, j - 1)
            bst[i][j] = Min(bst[i][j], bst[i][k] + bst[k + 1][j] + d[i - 1] * d[k] * d[j]);
      }

    fout<<bst[1][n];
    return 0;
}
