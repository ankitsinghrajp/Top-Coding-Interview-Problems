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
        temp->left = create("Enter the left child of "+to_string(x)+": ");
        temp->right = create("Enter the right child of "+to_string(x)+": ");
        return temp;
      }
};

int sizeOfTree(Node* root){
    if(root == NULL) return 0;

    return 1 + sizeOfTree(root->left) + sizeOfTree(root->right);
}
int main(){
    BinaryTree bt;
    Node* root = bt.create("Enter the root element: ");

    cout<<"The size of the tree is: "<<sizeOfTree(root)<<endl;
    return 0;
}