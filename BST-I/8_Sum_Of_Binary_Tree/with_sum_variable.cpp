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

    void sumTree(Node* root, int &sum){
        if( root == NULL ){
            return;
        }

        sum += root->data;
        sumTree(root->left, sum);
        sumTree(root->right, sum);
    }
};
int main(){
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node: ");
    
    bt.printTree(root);
    cout<<endl;
   int sum = 0;
   bt.sumTree(root,sum);

   cout<<"The sum of all element of the tree is: "<< sum<<endl;
    
    return 0;
}