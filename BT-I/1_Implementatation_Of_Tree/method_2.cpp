#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
      }
};

Node* BinaryTree(string msg){
    int x;
    cout<<msg;
    cin>>x;

    if(x == -1){
        return NULL;
    }
    Node * temp = new Node(x);
    
    // go to left side
    temp->left = BinaryTree("Enter the left child of " + to_string(x) + ": ");

    temp->right = BinaryTree("Enter the right child of " + to_string(x) + ": ");

    return temp;
};
int main(){
   Node* root = BinaryTree("Enter the root element: ");

   cout<<"The root node is: "<<root->data<<endl;
   cout<<"The left child of root node is: "<<root->left->data<<endl;
   cout<<"The right child of the root node is: "<<root->right->data<<endl;

    return 0;
}