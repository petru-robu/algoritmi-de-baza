#include <bits/stdc++.h>
using namespace std;

#define NMAX 200001
#define LOGMAX 20

ifstream fin("lca.in");
ofstream fout("lca.out");

int k, m, n;
int eul[NMAX], lev[NMAX], lg[NMAX], first[NMAX];
vector<int> x[NMAX];

int rmq[NMAX][LOGMAX];

void citire()
{
  fin>>n>>m;
  for(int i=2; i<=n; i++)
  {
    int a;
    fin>>a;
    x[a].push_back(i);
  }
}

void dfs(int nod, int l)
{
  eul[++k]=nod;
  lev[k]=l;

  first[nod]=k;

  for(auto &el : x[nod])
  {
    dfs(el, l+1);
    eul[++k]=nod;
    lev[k]=l;
  }
}

void build_rmq()
{
  for(int i=2; i<=k; i++)
    lg[i] = lg[i/2] + 1;

  for(int i=1; i<=k; i++)
    rmq[i][0] = i;

  for(int i=1; i <= lg[k]; i++)
    for(int j=1; j<= k - (1<<i); j++)
    {
      if(lev[rmq[j][i-1]] > lev[rmq[j+(1<<(i-1))][i-1]])
        rmq[j][i] = rmq[j+(1<<(i-1))][i-1];
      else
        rmq[j][i]=rmq[j][i-1];
    }
}

int lca(int x, int y)
{
  int a=first[x], b=first[y];

  if(a > b)
    swap(a,b);

  int exp = lg[b-a+1];
  int a1 = b-(1<<exp)+1;

  int sol = min(rmq[a][exp], rmq[a1][exp]);
  return eul[sol];
}

int main()
{
  citire();
  dfs(1,0);
  build_rmq();

  while(m--)
  {
    int x,y;
    fin>>x>>y;
    fout<<lca(x,y)<<'\n';
  }

}
