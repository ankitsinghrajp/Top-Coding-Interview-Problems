#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int val){
        data = val;
        left = NULL;
        right = NULL;
      }
};

class BinaryTree{
    public:
    Node* create(string msg){
         int x;
         cout<<msg<<" ";
         cin>> x;
         if(x == -1) return NULL;

         Node* temp = new Node(x);
         temp->left = create("Enter the left child of "+to_string(temp->data)+": ");
         temp->right = create("Enter the right child of "+to_string(temp->data)+": ");
         return temp;
    }


    void printTree(Node* root){
        if(root == NULL){
            return;
        }

        cout<<root->data<<" ";
        printTree(root->left);
        printTree(root->right);
    }

    int sumTree(Node* root){
        if( root == NULL ){
            return 0;
        }

        return root->data + sumTree(root->left) + sumTree(root->right);
    }
};
int main(){
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node: ");
    
    bt.printTree(root);
    cout<<endl;

   cout<<"The sum of all element of the tree is: "<< bt.sumTree(root)<<endl;
    
    return 0;
}