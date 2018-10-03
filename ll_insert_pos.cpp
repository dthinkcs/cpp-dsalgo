// C++ program for insertion in a single linked 
// list at a specified position 
// https://www.geeksforgeeks.org/insert-a-node-at-a-specific-position-in-a-linked-list/
/* OUTPUT
Linked list before insertion:  3 5 8 10
Position 3
Linked list after insertion of 12 at position 3:  3 5 12 8 10
Position 1
Linked list after insertion of 1 at position 1:  1 3 5 12 8 10
Position 7
Linked list after insertion of 15 at position 7:  1 3 5 12 8 10 15

*/
#include <bits/stdc++.h> 
using namespace std; 

// A linked list Node 
struct Node { 
	int data; 
	struct Node* next; 
	
	Node(){}
	
	Node(int item)
	{
	    data = item;
	    next = NULL;
	}
}; 


// Size of linked list 
int size = 0; 

// function to create and return a Node 
Node* getNode(int data) 
{ 
	// allocating space 
	Node* newNode = new Node(); 

	// inserting the required data 
	newNode->data = data; 
	newNode->next = NULL; 
	return newNode; 
} 

// function to insert a Node at required postion 
void insertPos(Node** current, int pos, int item) 
{ 
	 Node* head = *current;
	 cout << "Position " << pos << endl;
	 if (pos < 1)
	    cout << "Invalid Position " << endl;
	 else if (head == NULL && pos != 1 )
	    cout << "INVALID" << endl;
	 else if (pos == 1)
	 {
	     Node* newptr = new Node(item);
	     newptr->next = head; 
	     *current = newptr;
	 }
	 else 
	 {
	    int count = 2;
	    Node* ptr;
	    for (ptr = head; ptr && count != pos ; count++, ptr=ptr->next);
	    if (ptr == NULL)
	        cout << "Invalid Position Pos Too Big" << endl;
	    else 
	    {
	        Node * newptr = new Node(item);
	        newptr->next = ptr->next;
	        ptr->next = newptr;
	    }
	 }
} 

// This function prints contents 
// of the linked list 
void printList(struct Node* head) 
{ 
	while (head != NULL) { 
		cout << " " << head->data; 
		head = head->next; 
	} 
	cout << endl; 
} 

// Driver Code 
int main() 
{ 
	// Creating the list 3->5->8->10 
	Node* head = NULL; 
	head = getNode(3); 
	head->next = getNode(5); 
	head->next->next = getNode(8); 
	head->next->next->next = getNode(10); 

	size = 4; 

	cout << "Linked list before insertion: "; 
	printList(head); 

	int data = 12, pos = 3; 
	insertPos(&head, pos, data); 
	cout << "Linked list after insertion of 12 at position 3: "; 
	printList(head); 

	// front of the linked list 
	data = 1, pos = 1; 
	insertPos(&head, pos, data); 
	cout << "Linked list after insertion of 1 at position 1: "; 
	printList(head); 

	// insetion at end of the linked list 
	data = 15, pos = 7; 
	insertPos(&head, pos, data); 
	cout << "Linked list after insertion of 15 at position 7: "; 
	printList(head); 

	return 0; 
} 
