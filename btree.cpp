#include <iostream>
using namespace std;

class BTNode
{
public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int item)
    {
        data = item;
        left = right = NULL;
    }
};

void printTreeSimple(BTNode* root)
{
	if (root == NULL)
		return;

	cout << root->data << endl;

	printTreeSimple(root->left);
	printTreeSimple(root->right);

}

// 10: L20 R30
void printTree(BTNode* root)
{
	if (root == NULL)
		return;

	cout << root->data << ":";

	if (root->left != NULL)
		cout << "L" << root->left->data << " ";
	if (root->right != NULL)
		cout << "R" << root->right->data;
    cout << endl;
	printTree(root->left);
	printTree(root->right);
}



int main()
{

    BTNode* root = new BTNode(10);
    root->left = new BTNode(20);
    root->right = new BTNode(30);
    printTreeSimple(root);
    printTree(root);

}


