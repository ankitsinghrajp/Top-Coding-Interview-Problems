#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    public:
        Node* create(string msg){
            int x;
            cout<<msg<<" ";
            cin>>x;

            if(x == -1) return NULL;

            Node* temp = new Node(x);
            temp->left = create("Enter the left child of "+to_string(temp->data)+": ");
            temp->right = create("Enter the right child of "+to_string(temp->data)+": ");
            return temp;
        }
};

void InOrder(Node * root){
    if(root == NULL) return;

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
int main(){
    
    BinaryTree bt;
    Node* root = bt.create("Enter the root node: ");

    cout<<"The Inorder traversal of the tree is: "<<endl;
    InOrder(root);
    return 0;
}