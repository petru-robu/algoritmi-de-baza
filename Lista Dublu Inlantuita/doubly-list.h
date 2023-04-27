#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <cstring>
using namespace std;



//STRUCT
struct node
{
    int data;
    node *prev;
    node *next;
};
typedef node list;
//1.PUSH
void push(list *&list1, int a)
{
   node *new_node = new node;
   new_node->data = a;
   new_node->next = list1;
   new_node->prev = NULL;
   if(list1) list1->prev = new_node;
   list1=new_node;
}
//2.APPEND
void append(list *&list1, int a)
{
   node *new_node = new node;
   node *last=list1;
   new_node->data = a;
   new_node->next = NULL;
   if(list1==NULL)
   {
      new_node->prev = NULL;
      list1 = new_node;
   }
   else
   {

      while(last&&last->next) last=last->next;
      last->next=new_node;
      new_node->prev=last;
   }
}
//3.READ
void read_list(list *&list1)
{
    int n,a;
    cout<<"Introduceti numarul de elemente : "; cin>>n;
    cout<<endl<<"Introduceti elementele : "<<endl;
    for(int i=0; i<n; i++)
    {
       cin>>a;
       append(list1,a);
    }
    cout<<endl;
}
//4.DISPLAY
void display(list *list1)
{
    while(list1)
    {
      cout<<list1->data<<" ";
      list1=list1->next;
    }
    cout<<endl;
}
//5.DISPLAY_REV
void display_rev(list *list1)
{
    node *curs=list1;
    while(curs&&curs->next) curs=curs->next;
    while(curs)
    {
        cout<<curs->data<<" ";
        curs=curs->prev;
    }
    cout<<endl;
}
//6.SEARCH BY KEY
node* search_key(list *list1, int key)
{
    node *curs=list1;
    while(curs)
    {
        if(curs->data==key) return curs;
        curs=curs->next;
    }
    return NULL;
}
//7.LENGHT
int lenght(list *list1)
{
    int k=0;
    while(list1)
    {
        k++;
        list1=list1->next;
    }
    return k;
}
//8.INSERT_IN_SORTED
void insert_in_sorted(list *&list1, node *new_node)
{
     node *curs;
     if(list1==NULL)
         list1=new_node;
     else if((list1->data) >= (new_node->data))
          {
              new_node->next=list1;
              (new_node->next)->prev=new_node;
              list1=new_node;
          }
          else
          {
              curs=list1;
              while(curs->next&&(curs->next)->data < new_node->data) curs=curs->next;
              new_node->next=curs->next;
              if(curs->next) new_node->next->prev=new_node;
              curs->next=new_node;
              new_node->prev=curs;

          }
}
//9.SORT
void sort_list(list *&list1)
{
     list *sorted=NULL, *curs=list1;node *temp=NULL;
     while(curs!=NULL)
    {
        temp=curs->next;
        curs->prev=curs->next=NULL;
        insert_in_sorted(sorted, curs);
        curs=temp;
    }

    list1=sorted;

}
//10.DELETE NODE
void delete_node(list *&list1, node *nod_de_sters)
{
    if(list1==nod_de_sters)
        list1=nod_de_sters->next;
    if(nod_de_sters->next)
        nod_de_sters->next->prev=nod_de_sters->prev;
    if(nod_de_sters->prev)
        nod_de_sters->prev->next=nod_de_sters->next;
    delete nod_de_sters;
}
//11.DELETE NODE AT POSITION
void delete_node_at_position(list *&list1, int n)
{
    node *curs=list1;
    for(int i=1;curs&&i<n;i++) curs=curs->next;
    if(curs==NULL) cout<<"Nu exista pos in lista"<<endl;
    else delete_node(list1, curs);
}
//12.DELETE LIST BY POSITION
void delete_list_by_position(list *&list1)
{
    for(int i=1; i<=lenght(list1);i++) delete_node_at_position(list1, i);
}
//13.DELETE LIST
int delete_list(list *&list1)
{
    node *curs=list1, *temp=NULL;
    while(curs)
    {
        temp=curs->next;
        delete_node(list1,curs);
        curs=temp;
    }
    return 1;
}
//14.DELETE DUPLICATES OF A KEY
void delete_duplicates_of_key(list *&list1, int key)
{
  node *curs = list1;
  while(curs&&curs->data!=key) curs=curs->next;
  if(curs->next)
  {
      curs=curs->next;
      while(curs)
         {
            if(curs->data==key) delete_node(list1,curs);
            curs=curs->next;
         }
  }
}
//15.DELETE DUPLICATES (AND SORT)
void delete_duplicates(list *&list1)
{
   sort_list(list1);
   node *curs = list1;
   while(curs->next)
   {
      if((curs->data)==((curs->next)->data)) delete_node(list1,curs->next);
      else curs=curs->next;
   }
}
//16.INSERT BEFORE KEY
void insert_before_key(list *&list1, int key, int n)
{
   node *curs=list1;

    if(list1->data==key)
         push(list1, n);
    else
    {
        node *new_node= new node;
        new_node->data=n;new_node->prev=NULL;new_node->next=NULL;
        while(curs&&curs->next->data!=key) curs=curs->next;
        node *temp=curs->next;
        temp->prev=new_node;
        curs->next=new_node;
        new_node->prev=curs;
        new_node->next=temp;
    }
}
//17.INSERT AFTER KEY
void insert_after_key(list *&list1, int key, int n)
{
    node *curs=list1->next;
    while(curs&&curs->prev->data!=key) curs=curs->next;
    if(curs==NULL)
        append(list1, n);
    else
    {
        node *new_node= new node;
        new_node->data=n;new_node->prev=NULL;new_node->next=NULL;
        node *temp=curs->prev;
        temp->next=new_node;
        curs->prev=new_node;
        new_node->next=curs;
        new_node->prev=temp;
    }

}
//18.CONCATENATE
void concatenate(list *list1,list *list2)
{
    node *curs=list1;
    while(curs->next) curs=curs->next;
    curs->next=list2;
    list2->prev=curs;
}
//19.MOVE NODE IN THE FRONT BY POSITION
void move_front(list *&list1, int pos)
{
    if(pos!=1)
    {
        node *curs=list1;
        for(int i=1; i<pos; i++)
            curs=curs->next;
        push(list1, curs->data);
        delete_node(list1, curs);
    }
}
//19.MOVE NODE IN THE BACK BY POSITION
void move_back(list *&list1, int pos)
{
    if(pos!=lenght(list1))
    {
        node *curs=list1;
        for(int i=1; i<pos; i++)
            curs=curs->next;
        append(list1, curs->data);
        delete_node(list1, curs);
    }
}
//20.MOVE NODE IN THE BACK BY NODE
void move_end(list *&list, node *a_nod)
{
   node *curs=list, *last=NULL;
   while(curs&&curs!=a_nod)
      curs=curs->next;
   if(curs)
   {
       if(curs->prev)
       {
        last=curs;
        while(last->next) last=last->next;
        if(curs->next)
           {
                curs->prev->next=curs->next;
                curs->next->prev=curs->prev;
                last->next=curs;
                curs->prev=last;
                curs->next=NULL;
           }
       }
       else
       {
         last=curs;
         while(last->next) last=last->next;
         last->next=curs;
         curs->prev=last;
         if(list->next) list=list->next;
         list->prev=NULL;
         curs->next=NULL;

       }

   }

}
//21.SEGREGATE
void segregate_by_links(list *&list1)
{
    node *curs=list1, *last=list1;
    while(last->next) last=last->next;
    while(curs!=NULL&&curs!=last)
    {
       if((curs->data)%2==1)
       {
          node *t=curs->next;
          move_end(list1, curs);
          curs=t;
       }
       else
       {
         curs=curs->next;
       }
    }
    if((last->data)%2==1)
          move_end(list1, last);

}
//21.SEGREGATE
void segregate_by_delete(list *&list1)
{
    node *curs=list1, *last=list1;
    while(last->next) last=last->next;
    while(curs!=NULL&&curs!=last)
    {
       if((curs->data)%2==1)
       {
          node *t=curs->next;
          append(list1, curs->data);
          delete_node(list1, curs);
          curs=t;
       }
       else
       {
         curs=curs->next;
       }
    }
    if((last->data)%2==1)
    {
        append(list1, last->data);
        delete_node(list1, last);
    }

}
//23.REVERSE
void reverse_list(list *&list1)
{
    node *temp = NULL;
    node *curs = list1;

    while (curs)
    {
        temp = curs->prev;
        curs->prev = curs->next;
        curs->next = temp;
        curs=curs->prev;
    }

    if(temp != NULL )
        list1 = temp->prev;


}
//24.PARTITION
//CHAR DUBLY LINKEE LIST
struct char_node
{
    char data;
    char_node *next;
    char_node *prev;
};
typedef char_node char_list;
//25.CHAR PUSH
void char_push(char_list *&list1, char new_data)
{
    char_node *new_node = new char_node;
    new_node->data  = new_data;
    new_node->next = list1;
    new_node->prev = NULL;
    if (list1!=NULL)
      list1->prev=new_node;
    list1=new_node;
}
//26.CHAR PALINDROME
int char_palindorme(char_list *list1)
{
    int ok=1;
    char_node *stanga=NULL, *dreapta=NULL;
    stanga=dreapta=list1;
    while(dreapta->next) dreapta=dreapta->next;
    while(stanga&&dreapta&&stanga!=dreapta&&ok!=0)
    {
        if(stanga->data!=dreapta->data) ok=0;
        stanga=stanga->next;
        dreapta=dreapta->next;
    }
    return ok;
}
//27.HUGE INT READ
list* huge_int_in_list(char s[])
{
    list *list1=NULL;
    int i=0;
    while(s[i]!='\0')
    {
        append(list1, int(s[i]-'0'));
        i++;
    }
    return list1;
}
//28.HUGE_INT_ADD
list* huge_int_add(char a[], char b[])
{
   list *list1=NULL,*list2=NULL;
   list1 = huge_int_in_list(a);
   list2 = huge_int_in_list(b);

   if(lenght(list1)>lenght(list2))
   {
      node *curs=list1;
      while(curs&&list2)
        {
            curs->data=curs->data+list2->data;
            list2=list2->next;
            curs=curs->next;
        }
        return list1;
   }
   else
   {
      node *curs=list2;
      while(curs&&list1)
        {
            curs->data=curs->data+list1->data;
            list1=list1->next;
            curs=curs->next;
        }
        return list2;
   }

}
//XOR LINKED LIST
struct xor_node
{
    int data;
    xor_node *npx;
};
typedef xor_node xor_list;
//27.XOR OPERATTION
xor_node* XOR (xor_node *a, xor_node *b)
{
    return reinterpret_cast<xor_node *>(reinterpret_cast<uintptr_t>(a) ^reinterpret_cast<uintptr_t>(b));
}
//28.XOR PUSH
void xor_push(xor_list *&list1, int data)
{
    xor_node *new_node = new xor_node;
    new_node->data=data;
    new_node->npx=XOR(list1, NULL); //ac lucru : new_node->npx = list1;
    if(list1)
        list1->npx=XOR(new_node, list1->npx);
    list1=new_node;
}
//29.XOR DISPLAY
void xor_display(xor_list *list1)
{
    xor_node *curs = list1, *prev=NULL, *next;
    while(curs)
    {
        cout<<curs->data<<" ";
        next=XOR(prev,curs->npx);
        prev=curs;
        curs=next;
    }
}

#endif
