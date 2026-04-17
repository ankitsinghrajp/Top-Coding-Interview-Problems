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

class binaryTree{
    public:
      Node* create(string msg){
           int x;
           cout<<msg<<" ";
           cin>>x;

           if(x == -1) return NULL;

           Node* temp = new  Node(x);
           
           temp->left = create("Enter the the left child of "+to_string(temp->data)+": ");
           temp->right = create("Enter the right child of "+to_string(temp->data)+": ");
           return temp;
      }

    void preOrderTraversal(Node* root){
        if(!root) return;

        cout<<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

    int height(Node* root){
        if(!root) return -1;

        return 1 + max(height(root->left), height(root->right));
    }
    bool checkBalancedTree(Node* root){
       if(!root) return true;

       int lh = height(root->left);
       int rh = height(root->right);
       
       if(abs(lh-rh) > 1) return false;

       return checkBalancedTree(root->left) && checkBalancedTree(root->right);
    }
};

int main(){
    binaryTree bt;
    Node* root = bt.create("Enter the root Node: ");
   cout<<"The tree is: "<<endl;
   bt.preOrderTraversal(root);

   if(bt.checkBalancedTree(root)){
      cout<<"The tree is balanced subtree!"<<endl;
      cout<<"Congratulations!"<<endl;
   }
   else{
    cout<<"The tree is not subtree!"<<endl;
    cout<<"Keep moving!"<<endl;
   }

    return 0;
}