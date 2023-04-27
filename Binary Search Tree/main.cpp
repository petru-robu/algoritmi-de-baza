#include <bits/stdc++.h>
#include "bst.h"
using namespace std;


int main()
{
  BST arb;
  Node* temp=NULL;
  arb.insert(99);
  arb.insert(72);
  arb.insert(3);
  arb.insert(1);
  arb.insert(6);
  arb.insert(2);
  arb.insert(21);


  arb.levelOrder();
  arb.Delete(6);
  arb.levelOrder();
  arb.Delete(3);
  arb.levelOrder();
  temp = arb.search(21);
  temp = search_parent(arb.rootPtr(), temp);
  cout<<temp->data;

  return 0;
}
