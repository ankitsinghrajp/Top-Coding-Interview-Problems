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
   
    int check(Node* root, bool & valid){
         if(!root) return 0;

         int lh = check(root->left, valid);
         int rh = check(root->right, valid);

         if(abs(lh - rh) > 1) return 0;

         return 1 + max(lh,rh);
    }
    bool checkBalancedTree(Node* root){
        bool valid = 1;
        check(root,valid);
        return valid;
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