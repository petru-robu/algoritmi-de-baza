#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

typedef node stack;

stack* not_empty(stack *stack1)
{
    return stack1;
}
stack* push(stack *&stack1, int new_data)
{
    node *new_node= new node;
    if(!new_node) return NULL;
    new_node->data=new_data;
    if(!not_empty(stack1))
    {
      stack1=new_node;
      stack1->next=NULL;
    }
    else
    {
      new_node->next=stack1;
      stack1=new_node;
    }
    return stack1;
}

bool pop(stack *&stack1,int &data)
{
    if(not_empty(stack1))
    {
        data=stack1->data;
        node *t=stack1->next;
        delete stack1;
        stack1=t;
        return true;
    }
    else return false;
}

bool peek(stack *stack1, int &data)
{
    if(not_empty(stack1))
    {
        data=stack1->data;
        return true;
    }
    else return false;
}

void display(stack *stack1)
{
   while(stack1)
   {
      cout<<stack1->data<<' ';
      stack1=stack1->next;
   }
   cout<<endl;
}

void show(stack *stack1)
{
    int n,x;
    cout<<"Introduceti numarul de elemente : ";cin>>n;
    cout<<"Introduceti elementele : "<<endl;
    for(int i=0; i<n; i++)
    {
       cin>>x;
       push(stack1,x);
       display(stack1);
    }
    for(int i=0; i<n; i++)
    {
       pop(stack1,x);
       cout<<"Am extras : "<<x<<endl;
       display(stack1);
    }
}

void get_min(stack *stack1, int &min)
{
   int x;
   if(stack1)
   {
      pop(stack1, x);
      if(x<min)  min=x;
      get_min(stack1, min);
      push(stack1, x);
   }
}


void insert_in_bottom(stack *&stack1, int x)
{

    if(!not_empty(stack1))
        push(stack1,x);
    else
    {
        int y;
        pop(stack1,y);
        insert_in_bottom(stack1, x);
        push(stack1, y);
    }

}
void reverse_stack(stack *&stack1)
{
    int y;
    if(not_empty(stack1))
    {
        pop(stack1, y);
        reverse_stack(stack1);
        insert_in_bottom(stack1, y);
    }
}
void sorted_insert(stack *&stack1, int x)
{
    int y, p;
    peek(stack1, p);
    if(!not_empty(stack1)||x>p)
       push(stack1, x);
    else
    {
       pop(stack1, y);
       sorted_insert(stack1,x);
       push(stack1, y);
    }
}
void sort_stack(stack *&stack1)
{
    int y;
    if(not_empty(stack1))
    {
        pop(stack1, y);
        sort_stack(stack1);
        sorted_insert(stack1, y);
    }
}
stack* sort_stack_tmp(stack *&stack1)
{
    int y,r,p;
    stack* temp=NULL;
    while(not_empty(stack1))
    {
       pop(stack1, y);
       peek(temp,p);
       while(not_empty(temp)&&p>y)
       {
           push(stack1,p);
           pop(temp, r);
           peek(temp,p);
       }
       push(temp, y);
    }
    return temp;
}
