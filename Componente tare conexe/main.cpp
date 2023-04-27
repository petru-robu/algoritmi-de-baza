#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005

ifstream fin("ctc.in");
ofstream fout("ctc.out");

int N, M, index=0;
vector<int> G[MAXN], idx, lowlink, in_stack, componenta;
vector< vector<int> > Componente;
stack<int> S;

void read()
{
  fin>>N>>M;
  for(int i=1; i<=M; i++)
  {
    int x, y; fin>>x>>y;
    G[x-1].push_back(y-1);
  }
  fin.close();
}

void print()
{
  fout<<Componente.size()<< '\n';
  for(int i=0; i < Componente.size(); i++)
  {
    for(int j=0; j< Componente[i].size(); j++)
      fout<<Componente[i][j] + 1 <<' ';
    fout<<'\n';
  }
  fout.close();
}

void tarjan(int x)
{
  idx[x] = lowlink[x] = index;
  index++;
  S.push(x);
  in_stack[x] = 1;

  for(auto& vecin: G[x])
  {
    if(idx[vecin] == -1)
    {
      tarjan(vecin);
      lowlink[x] = min(lowlink[x], lowlink[vecin]);
    }
    else
      if(in_stack[vecin])
        lowlink[x] = min(lowlink[x], lowlink[vecin]);
  }

  if(idx[x] == lowlink[x])
  {
    componenta.clear();
    int node;
    do
    {
      node = S.top();
      S.pop();
      in_stack[node] = 0;
      componenta.push_back(node);
    } while(node != x);

    Componente.push_back(componenta);
  }
}

int main()
{
  read();

  idx.resize(N); idx.assign(N, -1);
  lowlink.resize(N);
  in_stack.resize(N); in_stack.assign(N, -1);

  for(int i=0; i<N; i++)
    if(idx[i] == -1)
      tarjan(i);

  print();
  return 0;
}
