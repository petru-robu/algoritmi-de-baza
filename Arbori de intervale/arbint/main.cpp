#include <bits/stdc++.h>
#define N 100002
#define inf INT_MIN
using namespace std;
ifstream fin("arbint.in");
ofstream fout("arbint.out");

int n, m, A[N], aint[2*N], res=-1;

void build(int nod, int st, int dr)
{
  if(st==dr)
    aint[nod]=A[st];
  else
  {
    int m = (st+dr)/2;
    build(2*nod, st, m);
    build(2*nod+1, m+1, dr);
    aint[nod]=max(aint[nod*2], aint[nod*2+1]);
  }
}

void update(int nod, int st, int dr, int pos, int val)
{
  if(st==dr)
    aint[nod]=val;
  else
  {
    int m = (st+dr)/2;
    if(pos<=m)
      update(2*nod, st, m, pos, val);
    else
      update(2*nod+1, m+1, dr, pos, val);

    aint[nod]=max(aint[nod*2], aint[nod*2+1]);
  }
}

int query(int nod, int st, int dr, int stq, int drq)
{
  if(st>=stq && drq>=dr)
  {
    return aint[nod];
  }
  int m = (st+dr)/2, p1=inf, p2=inf;
  if(stq<=m)
    p1=query(2*nod, st, m, stq, drq);
  if(drq>m)
    p2=query(2*nod+1, m+1, dr, stq, drq);

  return max(p1, p2);
}

int main()
{
  fin>>n>>m;
  for(int i=1; i<=n; i++)
    fin>>A[i];
  build(1,1,n);
  for(int i=0; i<m; i++)
  {
    int a, b, t;
    fin>>t>>a>>b;
    if(t==1)
      update(1, 1, n, a, b);
    else
      fout<<query(1, 1, n, a, b)<<'\n';

  }
  return 0;
}
