#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree
{
public:
    Node *create()
    {
        int x;
        int left;
        int right;
        cout << "Enter the root element value: ";
        cin >> x;
        queue<Node *> q;
        Node *root = new Node(x);
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << "Enter the left child of " << temp->data << ": ";
            cin >> left;

            if (left != -1)
            {
                Node *newNode = new Node(left);
                temp->left = newNode;
                q.push(temp->left);
            }

            cout << "Enter the right child of " << temp->data << ": ";
            cin >> right;

            if (right != -1)
            {
                Node *newNode = new Node(right);
                temp->right = newNode;
                q.push(temp->right);
            }
        }

        return root;
    }
};
int main()
{

    BinaryTree b1;
    Node *root = b1.create();

    if (root->left != NULL)
        cout << "The left child of root is: " << root->left->data << endl;
    else
        cout << "No left child" << endl;

    if (root->right != NULL)
        cout << "The right child of root is: " << root->right->data << endl;
    else
        cout << "No right child" << endl;

    return 0;
}