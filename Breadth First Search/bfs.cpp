#include <bits/stdc++.h>
using namespace std;

//Depth first search
//Compelxitate: 0(n+m)

vector<int> graf[100001];
queue<int> C;
bitset<100001> viz;
ifstream fin("graf.txt");

void citire()
{
    int n, m, x, y;
    fin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }
}

void BFS(int nod)
{
    cout << nod << " ";
    C.push(nod);
    viz[nod]=1;
    while(!C.empty())
    {
      nod=C.front();
      C.pop();
      for(int i=0; i<graf[nod].size(); i++)
      {
        if(!viz[graf[nod][i]])
        {
          cout << graf[nod][i] << " ";
          viz[graf[nod][i]]=1;
          C.push(graf[nod][i]);
        }
      }
    }
}

int main()
{
    citire();
    BFS(1);
}
