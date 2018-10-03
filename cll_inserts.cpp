#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node* next;

  Node(int item)
  {
    data = item;
    next = this;
  }

  Node(int item, Node* add)
  {
    data = item;
    next = add;
  }
};

class CLinkedList
{
  Node* head;
  public:
    CLinkedList()
    {
      head = NULL;
    }
    void traverse();
    void insert_head(int);
    void insert_tail(int);

    void insert_pos(int, int);

    void insert_sorted(int item);
    void insert_before(int item, int item_new);
    void insert_after(int item, int item_new);


};

void CLinkedList::traverse()
{
  Node* ptr;
  for (ptr = head; ptr->next != head; ptr=ptr->next)
    cout << ptr->data << "\t";
  cout << ptr->data << "\t";
  cout << endl;
}

void CLinkedList::insert_head(int item)
{
  Node* newptr = new Node(item);

  if (head == NULL)
    head = newptr;

  else
  {
    Node* ptr;
    for (ptr = head; ptr->next != head; ptr=ptr->next);

    newptr->next = ptr->next;
    ptr->next = newptr;

    head = newptr; // ONLY DIFFERENCE
  }
}

void CLinkedList::insert_tail(int item)
{
  Node* newptr = new Node(item);

  if (head == NULL)
    head = newptr;
  else
  {
    Node* ptr;
    for (ptr = head; ptr->next != head; ptr=ptr->next);

    newptr->next = ptr->next;
    ptr->next = newptr;
  }
}


void CLinkedList::insert_pos(int item, int pos)
{
  Node* newptr = new Node(item);

  if (pos < 1)
    cout << "Invalid Position" << endl;
  else if (head == NULL && pos != 1)
    cout << "Invalid Position" << endl;
  else if (pos == 1)
    insert_head(item);
  else
  {

    int count = 2;
    Node* ptr;
    for (ptr = head; ptr->next != head && count != pos ; count++, ptr=ptr->next);
    if (pos == count) // only when both are true
    {
      // tail == ptr
      newptr->next = ptr->next;
      ptr->next = newptr;
    }
    else
    {
      cout << "Invalid Position" << endl;
    }
  }
}


void CLinkedList::insert_sorted(int item)
{
  Node* newptr = new Node(item);
  if (head == NULL)
    head = newptr;
  else if (item <= head->data)
  {
    insert_head(item);
    delete newptr;
  }
  else
  {
    Node* ptr;
    for (ptr = head; (ptr->next != head) && (item > ptr->next->data); ptr=ptr->next);
    newptr->next = ptr->next;
    ptr->next = newptr;
  }
}

void CLinkedList::insert_before(int item, int item_new)
{
  if (head == NULL)
  {
    Node* newptr = new Node(item_new);
    head = newptr;
  }
  else if (head->data == item)
    insert_head(item_new);
  else
  { // we have atleast 2 elements so ptr->next != NULL
    Node* ptr;
    for (ptr = head; ptr->next != head && ptr->next->data != item; ptr=ptr->next);
    if (ptr->next->data != item)//(ptr->next == head) // we can use this becaus of cll IN sll we should use ptr->next == NULL
      cout << "item Not Found" << endl;
    else
    {
      Node* newptr = new Node(item_new);
      newptr->next = ptr->next;
      ptr->next = newptr;
    }
  }
}

void CLinkedList::insert_after(int item, int item_new)
{
  if (head == NULL)
  {
    Node* newptr = new Node(item_new);
    head = newptr;
  }
  else
  { // we have atleast 1  element
    Node* ptr = head;
    do
    {
      if (ptr->data == item)
        break;
      ptr=ptr->next;
    }
    while (ptr != head);

    if (ptr->data != item)
      cout << "item Not Found";
    else
    {
      Node* newptr = new Node(item_new);
      newptr->next = ptr->next;
      ptr->next = newptr;
    }
  }
}

int main()
{
  /*
  CLinkedList cll1;
  cll1.insert_head(10);
  cll1.insert_head(20);
  cll1.insert_head(30);
    CLinkedList cll2;

  cll2.insert_tail(10);
  cll2.insert_tail(20);
  cll2.insert_tail(30);

  cll1.traverse();
  cll2.traverse();
  */
  CLinkedList cll3;
  //cll3.insert_sorted(10);
  //  cll3.insert_sorted(20);
  //cll3.insert_sorted(-10);
  //cll3.insert_sorted(50);
  //cll3.insert_sorted(40);

  cll3.insert_pos(10, 1);
  cll3.insert_pos(20, 2);

  cll3.insert_pos(30, 3);
  //cll3.insert_after(30, 40);

  cll3.insert_pos(40, 4);
  cll3.insert_pos(35, 4);
  cll3.insert_pos(-10, 1);
  cll3.insert_before(35, 32);
  cll3.insert_after(35, 37);
    cll3.insert_before(40, 38);
  // SOME PROBLEM AFTER THIS ...maybe no problem only long code for visualizer
  cll3.insert_after(40, 42);


  cll3.traverse();
}
