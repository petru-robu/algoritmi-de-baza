#include <bits/stdc++.h>
#define M 5000
using namespace std;
ifstream fin("lazy.in");
ofstream fout("lazy.out");

int A[M], aint[2*M], n, q;
int lazy[2*M]={0};

void build(int nod, int st, int dr)
{
  if(st==dr)
    aint[nod]=A[st];
  else
  {
    int m = (st+dr)/2;
    build(2*nod, st, m);
    build(2*nod+1, m+1, dr);
    aint[nod]=aint[2*nod]+aint[2*nod+1];
  }
}

void lazyUpdate(int nod, int st, int dr, int a, int b, int val)
{
  if(lazy[nod] != 0)
    {
      aint[nod] += (dr - st + 1) * lazy[nod];
      if(st!=dr)
      {
        lazy[nod*2] += lazy[nod];
        lazy[nod*2+1] += lazy[nod];
      }
      lazy[nod]=0;
    }

  if(st > dr || st > b || dr < a)
    return;

  if(st>=a && b>=dr)
  {
    aint[nod] += (dr-st+1) * val;
    if(st!=dr)
    {
      lazy[nod*2] += val;
      lazy[nod*2+1] += val;
    }
    return;
  }

  int m = (st+dr)/2;
  lazyUpdate(2*nod, st, m, a, b, val);
  lazyUpdate(2*nod+1, m+1, dr, a, b, val);
  aint[nod] = aint[nod*2] + aint[nod*2+1];
}

int lazyQuery(int nod, int st, int dr, int a, int b)
{
  if(lazy[nod]!=0)
  {
    aint[nod] += (dr-st+1)*lazy[nod];
    if(st!=dr)
    {
      lazy[nod*2] += lazy[nod];
      lazy[nod*2+1] += lazy[nod];
    }
    lazy[nod]=0;
  }

  if(st>=a && b>=dr)
    return aint[nod];
  int m = (st+dr)/2, p1, p2;
  p1=p2=0;
  if(a<=m)
    p1=lazyQuery(2*nod, st, m, a, b);
  if(b>m)
    p2=lazyQuery(2*nod+1, m+1, dr, a, b);

  return (p1+p2);
}

int main()
{
  fin>>n;
  for(int i=1; i<=n; i++)
    fin>>A[i];

  build(1, 1, n);
  fin>>q;
  for(int i=0; i<q; i++)
  {
    int t, a, b, c;
    fin>>t;
    if(!t)
    {
      fin>>a>>b;
      fout<<lazyQuery(1, 1, n, a, b)<<'\n';
    }
    else
    {
      fin>>a>>b>>c;
      lazyUpdate(1, 1, n, a, b, c);
    }
  }

  fin.close();fout.close();
  return 0;
}
