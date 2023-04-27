#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BST
{
private:
  Node* root;

public:
  BST(){root=NULL;}
  BST(Node* n){root=n;}
  Node* rootPtr(){return root;}
  Node* search(int );
  void insert(int );
  void Delete(int );

  void inorder();
  void levelOrder();
};


//Cautare
Node* searchHelper(Node* root, int val)
{
      if(root == NULL || root->data == val)
          return root;
      if(root->data < val)
          return searchHelper(root->right,val);
      else
        return searchHelper(root->left, val);
}
Node* BST::search(int x)
{
  return searchHelper(root, x);
}


//Inserare
Node* insertHelper(Node*& root, Node* nod)
{
  if(root==NULL)
    return nod;
  if(nod->data > root->data)
    root->right = insertHelper(root->right, nod);
  else
    root->left = insertHelper(root->left, nod);

  return root;
}
void BST::insert(int x)
{
  Node* tobeInserted = new Node(x);
  root=insertHelper(root, tobeInserted);
}


//Stergere
Node* search_parent(Node* root, Node* searched)
{
  if(root == NULL || root->left == searched || root->right == searched)
      return root;
  if(root->data < searched->data)
      return search_parent(root->right, searched);
  else
    return search_parent(root->left, searched);
}
Node* succesor(Node* nod)
{
  Node* temp = nod;
  while(temp->left!=NULL)
    temp=temp->left;
  return temp;
}
void deleteHelper(Node*& root, Node* nod)
{
  Node *nod_parent = search_parent(root, nod);

  if(!nod->left || !nod->right)
  {
    Node *rep=NULL;
    if(!nod->left)
      rep = nod->right;
    else if(!nod->right)
      rep = nod->left;
    else if(!nod->right && !nod->left)
      rep =NULL;
    if(nod==nod_parent->right)
      nod_parent->right = rep;
    else nod_parent->left = rep;
    delete nod;
  }
  else
  {
    Node* suc = succesor(nod->right);
    swap(nod->data, suc->data);
    deleteHelper(root, suc);
  }
}
void BST::Delete(int key)
{
  Node* n = search(key);
  if(n!=NULL)
    deleteHelper(root, n);
}


//Afisare :
void inorderHelper(Node* root)
{
  if(root==NULL)
    return;
  inorderHelper(root->left);
  cout<<root->data<<' ';
  inorderHelper(root->right);
}
void levelOrderHelper(Node* root)
{
  if(!root) return;
  queue<Node*> Q;
  Q.push(root);
  while(!Q.empty())
  {
    Node* nod = Q.front();
    Q.pop();
    cout<<nod->data<<' ';

    if(nod->right)
      Q.push(nod->right);
    if(nod->left)
      Q.push(nod->left);
  }
}
void BST::levelOrder()
{
  levelOrderHelper(root);
  cout<<'\n';
}
void BST::inorder()
{
  inorderHelper(root);
  cout<<'\n';
}
