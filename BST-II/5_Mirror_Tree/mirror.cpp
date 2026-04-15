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

void createMirror(Node* root){
    if(root == NULL) return;
    
    Node* temp = root->right;
    root->right = root->left;
    root->left = temp;

   createMirror(root->left);
   createMirror(root->right);
}

// Helper to print inorder (to verify mirror)
void preOrder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){

    // -------- Original Tree --------
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Structure:
    //        1
    //      /   \
    //     2     3
    //    / \
    //   4   5

    cout << "PreOrder before mirror: ";
    preOrder(root);
    cout << endl;

    // Create mirror
    createMirror(root);

    cout << "PreOrder after mirror: ";
    preOrder(root);
    cout << endl;

    return 0;
}