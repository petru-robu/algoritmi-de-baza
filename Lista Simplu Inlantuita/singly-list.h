#ifndef SINGLYLINKEDLIST_H_INCLUDED
#define SINGLYLINKEDLIST_H_INCLUDED

// structura nod
struct node{
    int data;
    node *next;
};
// supranume lista
typedef node LIST;


// inserare element in capat
void push(LIST *&head, int data){
    node *pn = new node;
    pn->data = data;
    pn->next = head;
    head = pn;
}

//inserare element la final
void append (LIST *&head, int data){
    node *pn = new node, *ind;
    ind=head;
    pn->data = data;
    pn->next = NULL;
    if(!head) head = pn;
        else {
                while (ind->next) ind=ind->next;
                ind->next = pn;
    }
}

//afisare lista; intoarce 1 daca a afisat elemente si 0 daca nu afiseaza nimic)
int display (LIST *head ){
    if (head){
        cout<<endl;
        while (head!=NULL) {
                cout<<head->data<<" ";
                head=head->next;
        }
        cout<<endl;
        return 1;
    }
    else return 0;
}

//stergere primul element cu valoarea key; intoarce 1 daca a sters si 0 in caz contrac
int deleteNode(LIST *&head, int key){
    node *prev=NULL, *ind=head;
    int ok=0;
    while ((ind!=NULL)&&(!ok)){
        if (ind->data == key){
            if (prev) prev->next=ind->next;
                else head = head->next;
            delete ind;
            ok = 1;
        }
        else {
                prev = ind;
                ind = ind->next;
        }
    }
    return ok;
}

// stergere litsa; intoarce NULL si modifica head pe NULL
LIST* deleteList(LIST *&head){
    node *pn;
    while (head){
            pn=head;
            head=head->next;
            delete pn;
    }
    return head;
}

// intoarce lungimea unei liste
int list_len(LIST *head){
    int l=0;
    while (head) {
        head=head->next;
        ++l;
    }
return l;
}

//schimba 2 elemente prin modificare legaturilor; intoarce 1 in caz de sucess is 0 daca una din valori nu e in lista
int swap_nodes(LIST *&head, int x, int y ){
    int OKx=0,OKy=0;
    node *px=head,*prevx=NULL,*py=head,*prevy=NULL;
    while (px&&!OKx) {
        if(px->data == x) OKx=1;
            else {
                prevx=px;
                px=px->next;
            }
    }
    while (py&&!OKy&&OKx) {
        if(py->data == y) OKy=1;
            else {
                prevy=py;
                py=py->next;
            }
    }
    if ((OKx*OKy==1)&&(x!=y)){
      if (prevx && prevy)  { // x si y nu sunt cap de lista
        node *pt;
        prevx->next=py;
        prevy->next=px;
        pt=py->next;
        py->next=px->next;
        px->next=pt;
      }
      else if(!prevx && prevy){ // x este in capul listey
         node *pt;
        prevy->next=px;
        pt=py->next;
        py->next=px->next;
        px->next=pt;
        head = py;
      }
      else if(!prevy && prevx){ // y este in capul listey
         node *pt;
        prevx->next=py;
        pt=py->next;
        py->next=px->next;
        px->next=pt;
        head = px;
      }
    }
return OKx*OKy;
}


// inserare element in lista sortata crescator
void sortedInsert(LIST *&head, node *newNode)
{
    node dummy, *current = &dummy;;
    dummy.next = head;

    while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    head = dummy.next;
}

// sortare crescator prin insertie prin schimbare de legaturi
void insertSort(LIST *&head)
{
    node* result = NULL,  *current = head, *next;     // build the answer here

    while (current != NULL)
    {
        // tricky: note the next pointer before we change it
        next = current->next;
        sortedInsert(result, current);
        current = next;
    }
    head = result;
}

int occurence_list(LIST *head, int x)
{
   int k=0;
   while(head)
   {
       if(head->data==x) k++;
       head=head->next;
   }
   return k;
}

void move_end_to_front(LIST *&head)
{
    node *seclast=NULL, *last=head;
    while (last->next)
    {
       seclast = last;
       last = last->next;
    }
    seclast->next=NULL;
    last->next=head;
    head=last;
}

void move_end(LIST *&list, node *a_nod)
{
   node *curs=list, *prev=NULL, *last=NULL;
   while(curs&&curs!=a_nod)
   {
      prev=curs;
      curs=curs->next;
   }
   if(curs)
   {
       if(prev)
       {
        last=curs;
        while(last->next) last=last->next;
        if(curs->next)
           {
                prev->next=curs->next;
                last->next=curs;
                curs->next=NULL;
           }
       }
       else
       {
         last=curs;
         while(last->next) last=last->next;
         last->next=curs;
         list=list->next;
         curs->next=NULL;

       }

   }

}

void remove_dup(LIST *start)
{
    node *ptr1, *ptr2, *dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

LIST* intersect_sorted(LIST *list1, LIST *list2)
{
    LIST *final=NULL;
    node *curs=list1;
    while(curs)
    {
        if(occurence_list(list2,curs->data)!=0) append(final,curs->data);
        curs=curs->next;
    }
    remove_dup(final);
    return final;
}

LIST* create_list_1(int a[], int n)
{
   LIST *list=NULL;
   append(list,a[0]);
   for(int i=1;i<n;i++)
   {
      if(a[i-1]==a[i]) return list;
      append(list, a[i]);

   }
}

void insert_element(LIST *list, int n)
{
    node *curs=list, *el=NULL, *t;
    el->data=n;

    while(curs)
    {
        if((curs->next)->data>n)
        {
           t=curs->next;
           curs->next=el;
           el->next=t->next;
           break;
        }
        curs=curs->next;
    }

}

LIST* concatenate(LIST *list1, LIST *list2)
{
    LIST *list=list1;
    if(list1==NULL) list=list2;
    else
    {
      while(list1->next)
        list1=list1->next;
    list1->next=list2;
    }

    return list;
}

void segregate(LIST *&list1)
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

void partition_by_key(LIST *&list1, int key)
{
    node *curs=list1, *last=list1;
    while(last->next) last=last->next;
    while(curs&&curs!=last)
        {
            if((curs->data)==key)
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
    if((last->data)==key)
        move_end(list1, last);

    curs=list1;
    last=list1;
    while(last->next) last=last->next;

    while(curs&&curs!=last)
        {
            if((curs->data)>key)
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
    if((last->data)>key)
        move_end(list1, last);
}

#endif // SINGLYLINKEDLIST_H_INCLUDED
