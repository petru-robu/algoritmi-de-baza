#include <bits/stdc++.h>
#define NMAX 100001
using namespace std;
ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int father[NMAX], depth[NMAX], n, m;

int findRoot(int x)
{
  while(father[x]!=x)
    x=father[x];
  return x;
}

void compress(int x, int rx)
{
  int temp =x;
  while(father[x]!=x)
  {
    x = father[x];
    father[temp]=rx;
    temp=x;
  }
}

bool query(int x, int y)
{
  int rx, ry;
  rx=findRoot(x);
  ry=findRoot(y);

  compress(x, rx);
  compress(y, ry);

  if(ry==rx)
    return 1;
  else
    return 0;
}

void reunion(int x, int y)
{
  int rx, ry;
  rx=findRoot(x);
  ry=findRoot(y);

  compress(x, rx);
  compress(y, ry);

  if(depth[rx] < depth[ry])
    father[rx] = ry;
  if(depth[rx] > depth[ry])
    father[ry] = rx;
  if(depth[rx] == depth[ry])
  {
    father[ry] = rx;
    depth[rx]++;
  }

}

int main()
{
  fin>>n>>m;
  for(int i=1; i<=n; i++)
    father[i]=i;

  for(int i=1; i<=m; i++)
  {
    int x, y, t;
    fin>>t>>x>>y;
    if(t==1)
      reunion(x, y);
    else
      query(x,y) ? fout<<"DA\n" : fout<<"NU\n";
  }
  return 0;
}
