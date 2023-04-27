#include <bits/stdc++.h>
#include "segtree.h"
using namespace std;
ifstream fin("data.txt");

int main()
{
  Node* root=createNode();
  SegTree aint(root);

  int n, a[101];
  fin>>n;
  for(int i=1; i<=n; i++) fin>>a[i];

  aint.build(a, n);
  aint.print();
  aint.update(3, 5);
  aint.print();
  cout<<aint.query(1, 4)<<'\n';
  cout<<aint.query(2, 4)<<'\n';
  cout<<aint.query(3, 4)<<'\n';
  cout<<aint.query(4, 4)<<'\n';
  cout<<aint.query(2, 3)<<'\n';
  cout<<aint.query(2, 5)<<'\n';
  cout<<aint.query(1, 5)<<'\n';


  return 0;
}
