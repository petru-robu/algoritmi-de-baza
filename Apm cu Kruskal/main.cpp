#include <bits/stdc++.h>
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

//Algoritmul lui Kruskal
//Compelxitate: O(mlogn)

const int maxn = 400100;

int GR[maxn], X[maxn], Y[maxn],C[maxn];
int n, m, ANS, IND[maxn];
vector<int> VANS;

int father(int i)
{
    if (GR[i] == i) return i;
    GR[i] = father(GR[i]);
    return GR[i];
}

void reunion(int i,int j)
{
    GR[father(i)] = father(j);
}

bool cmp(int i,int j)
{
    return(C[i] < C[j]);
}

int main()
{
    fin>>n>>m;
    for(int i = 1; i <= m; i++)
    {
        fin>>X[i]>>Y[i]>>C[i];
        IND[i] = i;
    }

    for(int i = 1; i <= n; i++)
      GR[i] = i;

    sort(IND+1, IND+m+1, cmp);

    for(int i=1; i<=m; i++)
    {
        if (father(X[IND[i]]) != father(Y[IND[i]])) //in componente separate
        {
            ANS += C[IND[i]];
            reunion(X[IND[i]],Y[IND[i]]);
            VANS.push_back(IND[i]);
        }
    }

    fout<<ANS<<'\n'<<n-1<<'\n';
    for(int i=0; i<n-1; i++)
      fout<<X[VANS[i]]<<' '<<Y[VANS[i]]<<'\n';


    return 0;
}
