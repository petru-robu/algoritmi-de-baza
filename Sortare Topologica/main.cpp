#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001
#define pb push_back

ifstream fin("sortaret.in");
ofstream fout("sortaret.out");

int n, m, incidenta[MAXN]={0};
vector<int> graf[MAXN], sortaret;


void citire()
{
  fin>>n>>m;
  for(int i=1; i<=m; i++)
  {
    int x, y;
    fin>>x>>y;
    graf[x].pb(y);
    incidenta[y]++;
  }
}

void solve()
{
  queue<int> Q;
  for(int i=1; i<=n; i++)
    if(incidenta[i]==0)
      Q.push(i);

  while(!Q.empty())
  {
    int x = Q.front();
    Q.pop();

    sortaret.pb(x);

    for(auto vecin : graf[x])
    {
      incidenta[vecin]--;
      if(incidenta[vecin] == 0)
        Q.push(vecin);
    }
  }
}

void afisare()
{
  for(auto el:sortaret)
    fout<<el<<' ';
}

int main()
{
  citire();
  solve();
  afisare();
  return 0;
}
