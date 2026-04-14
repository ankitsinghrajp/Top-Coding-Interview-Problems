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

      void countLeafNodes(Node* root, int & count){
           if(root == NULL) return;

           if(root->left == NULL && root->right == NULL) count += 1;
           countLeafNodes(root->left, count);
           countLeafNodes(root->right, count);
      }
};


int main(){
     
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node: ");

    cout<<"The pre order traversal of the tree is: "<<endl;
    bt.printTree(root);

    cout<<endl;
    int count = 0;
    bt.countLeafNodes(root,count);
    cout<<"The count of leaf Nodes is: "<<count<<endl;
    return 0;
}