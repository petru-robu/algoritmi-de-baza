#include <iostream>
#include "queue.h"
using namespace std;

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.reverse();
    cout<<q;

}
