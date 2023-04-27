#include <bits/stdc++.h>
#define NMAX 50001
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
using namespace std;
ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

//Algoritmul Bellman-Ford
//Complexitate: O(N*M)

int N, M, pred[NMAX], d[NMAX];
vector<pair<int, int>> G[NMAX];

void read()
{
  int x, y, c;
  fin>>N>>M;
  for(int i=1; i<=M; i++)
  {
    fin>>x>>y>>c;
    G[x].pb(mp(y, c));
  }
}

bool BellmanFord(int s)
{
  bool negativeCycle=false;
  queue<int> Q;
  bitset<NMAX> inQ(false);
  int cntQ[NMAX];

  for(int i=1; i<=N; i++)
  {
    pred[i] = 0;
    d[i] = INF;
    cntQ[i]=0;
  }

  d[s] = 0; Q.push(s); inQ[s]=true;
  while(!Q.empty() && !negativeCycle)
  {
    int curr = Q.front(); Q.pop();
    inQ[curr] = false;

    for(auto &vecin:G[curr])
      if(d[curr]<INF)
        if(d[vecin.first] > d[curr] + vecin.second)
        {
          d[vecin.first] = d[curr] + vecin.second;
          pred[vecin.first] = curr;
          if(!inQ[vecin.first])
          {
            if(cntQ[vecin.first] > N)
              negativeCycle = true;
            else
            {
              Q.push(vecin.first);
              inQ[vecin.first] = true;
              cntQ[vecin.first]++;
            }
          }

        }
  }
  return !negativeCycle;
}

int main()
{
  read();
  if(!BellmanFord(1))
    fout<<"Ciclu Negativ!\n";
  else
    for(int i=2; i<=N; i++)
      fout<<d[i]<<' ';
}
