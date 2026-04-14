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

      int countLeafNodes(Node* root){
          if(root == NULL){
            return 0;
          }

          if(root->left == NULL && root->right == NULL){
            return 1;
          }
    
          return countLeafNodes(root->left) + countLeafNodes(root->right); 
      }
};


int main(){
     
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node: ");

    cout<<"The pre order traversal of the tree is: "<<endl;
    bt.printTree(root);

    cout<<endl;

    cout<<"The count of leaf Nodes is: "<<bt.countLeafNodes(root)<<endl;
    return 0;
}