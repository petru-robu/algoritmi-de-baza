#include <bits/stdc++.h>
using namespace std;

class Node{
public:
  int val;
  Node *left;
  Node *right;
  int st, dr;
  Node(int x, int a, int b)
  {
    left=right=NULL;
    val=x;st=a;dr=b;
  }
  Node(int x, int a, int b, Node* l, Node* r)
  {
    left=right=NULL;
    val=x;st=a;dr=b;
    left=l;right=r;
  }
};

Node* createNode()
{
  Node* newNode = new Node(0, 0, 0, NULL, NULL);
}


class SegTree{
private:
  Node *root;
  void destroy(Node *leaf)
  {
    if(leaf!=NULL)
    {
      destroy(leaf->left);
      destroy(leaf->right);
      delete leaf;
    }
  }
  void print(Node *leaf)
  {
    if(leaf!=NULL)
    {
      cout<<leaf->val<<"["<<leaf->st<<", "<<leaf->dr<<"];"<<"  ";
      print(leaf->left);
      print(leaf->right);
    }
  }
  Node* build(vector<int>& a, int from, int to)
  {
    if(from==to)
      return new Node(a[from], from, to);

    int m = from + (to - from) / 2;
    Node* l = build(a, from, m);
    Node* r = build(a, m+1, to);
    return new Node( l->val + r->val, from , to, l, r);
  }
  void update(int index, int value, Node* leaf)
  {
    if(leaf->st==index && leaf->dr==index)
    {
      leaf->val=value;
      return;
    }
    int m = (leaf->st + leaf->dr)/2;
    if(index <= m)
      update(index, value, leaf->left);
    else
      update(index, value, leaf->right);
    leaf->val = leaf->left->val + leaf->right->val;
  }

  int query(int a, int b, Node* leaf)
  {
    if(a<=leaf->st && leaf->dr<=b)
      return leaf->val;

    int m = (leaf->st + leaf->dr)/2, p1, p2;
    p1=p2=0;
    if(a <= m)
      p1=query(a, b, leaf->left);
    if(b > m)
      p2=query(a, b, leaf->right);

    return (p1+p2);
  }

public:
  SegTree()
  {
    root=NULL;
  }
  ~SegTree()
  {
    destroy(root);
  }
  SegTree(Node *nod)
  {
    root=nod;
  }
  void print()
  {
    //preordine
    print(root);
    cout<<'\n';
  }
  void build(int v[], int n)
  {
    vector<int> a(v, v+n+1);

    Node* arbint = build(a, 1, n);
    root=arbint;
  }
  void update(int a, int b)
  {
    update(a, b, root);
}
  int query(int a, int b)
  {
    if(a<=b)
      return query(a, b, root);
    else return -1;
  }



};
