#include <bits/stdc++.h>
using namespace std;
ifstream fin("apm.in");
ofstream fout("apm.out");

//Algoritmul lui Prim
//Compelxitate: O(m + nlogn)

const int inf = 0x3f3f3f3f;
#define NMAX 200001

struct cmp
{
  bool operator()(pair<int, int> x, pair<int, int> y)
  {
      return x.second>y.second;
  }
  //ordinea dupa cost descrescator
};

int n, m; 
int d[NMAX], r[NMAX];
int napm=0, ctotal=0; 

//d - costul minim al lui x pana la apm
//r - nodul din apm la care exista conexiune pt x

bool u[NMAX]={0};

vector<pair<int, int>> graf[NMAX], APM;
priority_queue <pair<int,int>,vector<pair<int,int>>,cmp> heap;


void read()
{
  fin>>n>>m;
  for(int i=0; i<m; i++)
  {
    int x, y, c;
    fin>>x>>y>>c;
    graf[x].push_back(make_pair(y,c));
    graf[y].push_back(make_pair(x,c));
  }
}

int main()
{
  read();

  heap.push(make_pair(1,0));
  r[1]=0;
  d[1]=0;

  for(int i=2;i<=n;i++)
    d[i]=inf;

  while(!heap.empty())
  {
    int x = heap.top().first;
    heap.pop(); //nod cu cmin din afara apm-ului
    if(u[x]==0)
    {
      APM.push_back(make_pair(x, r[x]));
      napm++;
      ctotal+=d[x];
      u[x]=1; //se marcheaza ca vizitat
      for(int i=0; i<graf[x].size(); i++)
      {
        int nod = graf[x][i].first;
        int cost = graf[x][i].second;
        d[nod]=min(d[nod], cost);
        if(d[nod]==cost)
        {
          r[nod]=x;
          heap.push(make_pair(nod,d[nod]));
        }
      }

    }
    //daca am mai vizitat, continuam
  }


  fout<<ctotal<<"\n"<<n-1<<"\n";

  for(int i=1; i<=n-1; i++)
    fout<<APM[i].first<<" "<<APM[i].second<<"\n";

  return 0;

}
