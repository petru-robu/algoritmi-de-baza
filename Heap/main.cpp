a#include <bits/stdc++.h>
#define S 1001
using namespace std;
ifstream fin("heap.in");

int left_son(int nod)
{
    return 2*nod;
}
int right_son(int nod)
{
    return 2*nod+1;
}
int father(int nod)
{
    return nod/2;
}

int max(int H[], int n)
{
  if(n==0)
    return -1;
  else
    return H[1];
}

void sift(int H[], int n, int nod)
{
    int son = 1;
    while(son)
    {
        son=0;
        if(left_son(nod)<=n)
        {
            son=left_son(nod);
            if(right_son(nod)<=n && H[left_son(nod)]<H[right_son(nod)])
                son=right_son(nod);
        }

        if(H[nod] >= H[son])
            son=0;
        if(son)
        {
          swap(H[nod], H[son]);
          nod = son;
        }
    }
}
void percolate(int H[], int n, int nod)
{
    int key = H[nod];
    while(nod>1 && key>H[father(nod)])
    {
        H[nod] = H[father(nod)];
        nod = father(nod);
    }
    H[nod] = key;
}
void heapify(int H[], int n)
{
    for(int i=n/2; i>=1; i--)
      sift(H, n, i);
}
void insert(int H[], int &n, int x)
{
  n++;
  H[n]=x;
  percolate(H, n, n);
}
void remove(int H[], int &n, int nod)
{
  if(n==0)
    return;
  H[nod]=H[n];
  n--;
  if(nod>1 && H[nod]>H[father(nod)])
    percolate(H, n, nod);
  else
    sift(H, n, nod);
}
void heapsort(int H[], int n)
{
  heapify(H, n);
  for(int i=n; i>=2; i--)
  {
    swap(H[1], H[i]);
    sift(H, i-1, 1);
  }
}

int main()
{
  int m, A[S];
  fin>>m;
  for(int i=1; i<=m; i++)
      fin>>A[i];

  heapsort(A, m);
  for(int i=1; i<=m; i++)
      cout<<A[i]<<' ';

  return 0;
}
