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
    //void insert_tail(int);

    void insert_pos(int, int);

    void insert_sorted(int item);
    //void insert_before(int item, int item_new);
    //void insert_after(int item, int item_new);

    void delete_head();
    void delete_tail();
    void delete_specific(int item);
    void delete_pos(int pos);

};

void CLinkedList::traverse()
{
  if (head == NULL)
    cout << "Empty List" << endl;
  else
  {
    Node* ptr;
    // IN CLL's for implementation its important to check for head == NULL
    for (ptr = head; ptr->next != head; ptr=ptr->next)
      cout << ptr->data << "\t";
    cout << ptr->data << "\t";
    cout << endl;
  }
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

// tested -10 10 20 30 40 50
/*
  cll4.insert_sorted(10);
  cll4.insert_sorted(20);
  cll4.insert_sorted(50);
  cll4.insert_sorted(40);
  cll4.insert_sorted(30);
    cll4.insert_sorted(-10);
*/
void CLinkedList::insert_sorted(int item)
{
    if (head == NULL)
    {
        Node* newptr = new Node(item);
        head = newptr;
    }
    else if (item <= head->data)
    {
        insert_head(item);
    }
    else
    {
        Node* newptr = new Node(item);
        Node* ptr;
        for (ptr = head; ptr->next != head && item > ptr->next->data; ptr=ptr->next);
        // entry at tail same as entry in the middle so it has the SAME CODE
        newptr->next = ptr->next;
        ptr->next = newptr;

    }
}

// delete head tested all 3 cases [2 cases: head has 1 element; head has more than one element ]
void CLinkedList::delete_head()
{
  if (head == NULL)
  {
    cout << "Empty List! Nothing to delete" << endl;
  }
  else if (head->next == head)
  {
    delete head;
    head = NULL;
  }
  else
  { // at least 2 elements

    // find tail
    // change the tail
    Node* ptr;
    for (ptr=head; ptr->next != head; ptr=ptr->next);
    // replication
    // modification
    head = head->next;
    delete ptr->next;
    // adjustment
    ptr->next = head;
  }
}

void CLinkedList::delete_tail()
{
  if (head == NULL)
    cout << "Empty List! Nothing to delete" << endl;
  else if (head->next == head)
  {
    delete head;
    head = NULL;
  }
  else
  { // atleast 2 elements

    // find tail
    // change the tail
    Node* ptr; // ptr->next->next
    for (ptr=head; ptr->next->next != head; ptr=ptr->next);
    // replication ; of ptr->next is already in head
    // modification ; but here we can directly delete
    delete ptr->next;
    // adjustment
    ptr->next = head;

  }

}

// tested delete from beginning, middle, end
void CLinkedList::delete_specific(int item)
{
  if (head == NULL)
    cout << "Empty List! Nothing to delete" << endl;
  else if (head->data == item)
  {
      delete_head();
  }
  /*else if (head->next == head)
  {
    if (head->data == item)
    {
      delete head;
      head = NULL;
    }
    else
      cout << "Item Not Found";
  }*/
  else
  { // we have checked head already so we can check from  ptr->next (where ptr==next)
    Node* ptr;
    for (ptr = head; ptr->next != head && ptr->next->data != item; ptr=ptr->next);
    if (ptr->next == head)
      cout << "Couldnt Find Item" << endl;
    else
    {
      // delete ptr->next  ; since must not be head
      if (ptr->next->next == head)
      {
        delete ptr->next;
        ptr->next = head;
      }
      else
      {
        Node* tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
      }
    }
  }

}

void CLinkedList::delete_pos(int pos)
{
    if (pos < 1)
        cout << "Error: Invalid Position" << endl;
    else if (pos == 1)
    {
        delete_head(); // it includes case for when head == NULL
    }
    else if (head == NULL)
    {
        cout << "Error: Empty List! Cannot Delete" << endl;
    }
    else
    {
        // we know list contains atleast 1 element and pos istleast 2

        Node* ptr;
        int count = 2;
        for (ptr = head; ptr->next != head && count < pos ; count++, ptr=ptr->next);

        if (ptr->next == head) // BUG count != pos // THIS IS OK for insert BUT NOT FOR DELETE //  THIS IS false FOR 10 20 and pos = 3 count becomes 3 but we should not delete head
        {
            cout << "Error: Invalid Position (too big)" << endl;
        }
        else
        {
            //delete ptr->next;
            Node* tmp = ptr->next;
            ptr->next = tmp->next;
            delete tmp;
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

  /*
  CLinkedList cll3;
  //cll3.insert_sorted(10);
  //  cll3.insert_sorted(20);
  //cll3.insert_sorted(-10);
  //cll3.insert_sorted(50);
  //cll3.insert_sorted(40);

  cll3.insert_pos(10, 1);
  cll3.insert_pos(20, 2);

  cll3.insert_pos(30, 3);
    cll3.insert_pos(40, 3);
    cll3.insert_pos(50, 3);

  cll3.traverse();
  //cll3.insert_after(30, 40);
  cll3.insert_pos(40, 4);
  cll3.insert_pos(35, 4);
  cll3.insert_pos(-10, 1);
  cll3.insert_before(35, 32);
  cll3.insert_after(35, 37);
    cll3.insert_before(40, 38);
  // SOME PROBLEM AFTER THIS ...maybe no problem only long code for visualizer
  cll3.insert_after(40, 42);



  cll3.delete_head();cll3.traverse();
  cll3.delete_specific(20);cll3.traverse();
  cll3.delete_specific(40);cll3.traverse();
  cll3.delete_specific(30);cll3.traverse();
  cll3.delete_tail(); cll3.traverse();
  */

  CLinkedList cll4;
  cll4.insert_sorted(10);
  cll4.insert_sorted(20);
  cll4.insert_sorted(50);
  cll4.insert_sorted(40);
  cll4.insert_sorted(30);
    cll4.insert_sorted(-10);
  cll4.traverse();


  cll4.delete_specific(40); cll4.traverse();
  cll4.delete_pos(1); cll4.traverse();
  cll4.delete_pos(3); cll4.traverse();
  cll4.delete_pos(3); cll4.traverse();
  cll4.delete_pos(3); cll4.traverse();

}
