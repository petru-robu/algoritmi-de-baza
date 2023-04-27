#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Queue
{
private:
    Node *front, *rear;

public:

    //Constructori:
    Queue()
    {
        front = rear = NULL;
    }
    //Basic operationes
    bool empty()
    {
        if(rear==NULL&&front==NULL) return true;
        else return false;
    }

    void enQueue(int x)
    {
        Node *nod = new Node;
        nod->data=x;
        nod->next=NULL;
        if(rear==NULL)
        {
            front=rear=nod;
            return;
        }

        rear->next=nod;
        rear = nod;
    }

    void deQueue()
    {
        if(this->empty())
        {
            cout<<"Nu se poate face dequeue"<<endl;
            return;
        }
        front=front->next;
        if(!front) rear=NULL;
    }

    Node* FrontNod()
    {
        if(front) return front;
        else
        {
            cout<<"Coada este vida"<<endl;
            return NULL;
        }
    }

    Node* RearNod()
    {
        if(rear) return rear;
        else
        {
            cout<<"Coada este vida"<<endl;
            return NULL;
        }
    }

    int Front()
    {
        if(rear) return front->data;
        else
        {
            cout<<"Coada este vida"<<endl;
            return -1;
        }
    }

    int Rear()
    {
        if(rear) return rear->data;
        else
        {
            cout<<"Coada este vida"<<endl;
            return -1;
        }
    }

    int size()
    {
        int l=0;
        Node* cnt=front;
        while(cnt)
        {
            l++;
            cnt=cnt->next;
        }
        return l;
    }

    friend ostream& operator<<(ostream& os, Queue q)
    {
        if(q.empty())
        {
            os<<"Coada Vida"<<endl;
            return os;
        }
        Node* cnt=q.FrontNod();
        while(cnt)
        {
            cout<<cnt->data<<' ';
            cnt=cnt->next;
        }
        os<<endl;
        return os;
    }

    void reverse()
    {
        stack<int> st;
        while (!this->empty())
        {
            st.push(front->data);
            this->deQueue();
        }
        while(!st.empty())
        {
          this->enQueue(st.top());
          st.pop();
        }
    }

};
