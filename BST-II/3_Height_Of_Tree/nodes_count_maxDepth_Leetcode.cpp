#include<iostream>
#include<vector>
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
           temp->left = create("Enter the left child of: "+to_string(temp->data)+": ");
           temp->right = create("Enter the right child of "+to_string(temp->data)+": ");

           return temp;
      }

      void printTree(Node* root){
         if(root == NULL) return;

         cout<<root->data<<" ";
         printTree(root->left);
         printTree(root->right);
      }

      int maxDepth(Node* root){
        if(root == NULL) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
      }
};


int main(){
     
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node: ");

    cout<<"The pre order traversal of the tree is: "<<endl;
    bt.printTree(root);

    cout<<endl;

    cout<<"The max Depth of the tree is: "<<bt.maxDepth(root)<<endl;
    return 0;
}