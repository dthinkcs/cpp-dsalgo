#include <iostream>
using namespace std;

class DNode
{
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int item)
    {
        data = item;
        prev = next = NULL;
    }

};

class DLinkedList
{
    //DNode* head;
    public:
        DNode* head;
    DLinkedList()
    {
        head = NULL;
    }

    void traverse();
    void insert_head(int item);
    void insert_number(int n);


};

void DLinkedList::traverse()
{
    for (DNode* ptr = head; ptr; ptr=ptr->next)
        cout << ptr->data << "\t";
    cout << endl;
}

void DLinkedList::insert_head(int item)
{
    DNode* newptr = new DNode(item);
    newptr->next = head;
    head = newptr;
    if (newptr->next != NULL)
        newptr->next->prev = newptr;
}

void DLinkedList::insert_number(int n)
{
    for (; n != 0; n /= 10)
        insert_head(n % 10);
}

/*void DLinkedList::addition(LinkedList l2, DNode** )
{
}*/

int main(void)
{
    DLinkedList l1;
    l1.insert_number(111);
    l1.traverse();

    DLinkedList l2;
    l2.insert_number(11);
    l2.traverse();

    DLinkedList l3;
    // ADDITION OF TWO LINKED LISTS
    int a, b, c, sum;
    DNode *ptr1, *ptr2, *ptrt1, *ptrt2;
    for (ptrt1 = l1.head; ptrt1->next; ptrt1=ptrt1->next);
    for (ptrt2 = l2.head; ptrt2->next; ptrt2=ptrt2->next);

    a = b = c = 0;
    for (ptr1 = ptrt1, ptr2 = ptrt2; ptr1 || ptr2 ; )
    {
        a = ptr1 ? ptr1->data : 0;
        b = ptr2 ? ptr2->data : 0;
        sum = (a + b + c) % 10;
        l3.insert_head(sum);

        //update
        c = (a + b + c) / 10;
        if (ptr1)
            ptr1=ptr1->prev;
        if (ptr2)
            ptr2=ptr2->prev;
    }

    if (c != 0)
        l3.insert_head(c);

    l3.traverse();
}

