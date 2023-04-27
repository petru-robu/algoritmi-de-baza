#include <bits/stdc++.h>
using namespace std;
ifstream fin("rmq.in");
ofstream fout("rmq.out");

int LOG[100001], n, m, x, y;
vector<int> rmq[100002];

void compute_log()
{
  LOG[1]=0;
  for(int i=2; i<=n; i++)
      LOG[i] = LOG[i/2] + 1;
}

void build_rmq()
{
  for(int p=1; p<=LOG[n]; p++)
    for(int i=1; i <= n - (1<<p) + 1; i++)
    {
      rmq[i][p]=min(rmq[i][p-1], rmq[i+(1<<(p-1))][p-1]);
    }
}

int main()
{
  fin>>n>>m;
  compute_log();
  for(int i=1;i<=n;i++)
    {
      rmq[i].resize(LOG[n]+1);
      fin>>rmq[i][0];
    }
  build_rmq();

  for(int i=0; i<m; i++)
  {
    fin>>x>>y;
    int exp=LOG[y-x+1];
    int x1 = y-(1<<exp)+1;
    fout<< min(rmq[x][exp], rmq[x1][exp]) <<'\n';
  }

  return 0;
}
