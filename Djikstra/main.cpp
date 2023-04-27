#include <bits/stdc++.h>
#define NMAX 50001
#define MMAX 250001
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

//Algoritmul lui Dijkstra
//Complexitate: O((N+M)logN)

int n, m, dist[NMAX];
vector<pair<int, int>> graf[NMAX];
const int inf = 0x3f3f3f3f;


void read()
{
  fin>>n>>m;
  for(int i=0; i<m; i++)
  {
    int x, y, c;
    fin>>x>>y>>c;
    graf[x].push_back(make_pair(y,c));
  }
}

void dijkstra()
{
  memset(dist, inf, sizeof dist);
  dist[1]=0;
  set<pair<int,int>> heap;

  heap.insert(make_pair(0, 1));
  while(!heap.empty())
  {
    int nod = heap.begin()->second;
    int d = heap.begin()->first;
    heap.erase(heap.begin());

    for(auto it = graf[nod].begin(); it!=graf[nod].end(); it++)
    {
      int to = it->first;
      int cost = it->second;
      if(dist[to] > dist[nod] + cost)
      {
        if(dist[to] != inf)
          heap.erase(heap.find(make_pair(dist[to], to)));
        dist[to] = dist[nod] + cost;
        heap.insert(make_pair(dist[to], to));
      }
    }
  }

}


int main()
{
  read();
  dijkstra();

  for(int i=2; i<=n; i++)
  {
    if(dist[i]==inf) dist[i]=0;
    fout<<dist[i]<<' ';
  }
  fout << '\n';

  fin.close();
  return 0;
}
