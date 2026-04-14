#include<iostream>
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
            temp->right = create("Enter the right child of: "+to_string(temp->data)+": ");
            return temp;
        }
};

int findSize(Node* root){
       if(root == NULL) {
        return 0;
       }

       return 1 + findSize(root->left) + findSize(root->right);
}
int main(){
    BinaryTree bt;
    Node* root = bt.create("Enter the root element: ");

    
    int size = findSize(root);
    cout<<"The size of the tree is: "<<size<<endl;
    return 0;
}