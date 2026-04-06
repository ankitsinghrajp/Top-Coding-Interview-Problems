#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
      int val;
      Node* left;
      Node* right;

    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

Node*  BinaryTree(){
     int x;
    cout<<"Enter the root element: ";
    cin>>x;
    int first;
    int second;
    queue<Node*> q;

    Node* root = new Node(x);
    q.push(root);
    while(!q.empty()){
         Node* temp = q.front();
         q.pop();

         cout<<"Enter the left child of "<<temp->val<<": ";
         cin>>first;
         if(first != -1){
            Node* newNode = new Node(first);
            temp ->left = newNode;
            q.push(newNode);
         }

         cout<<"Enter the right child of "<<temp->val<<": ";
         cin>>second;

         if(second != -1){
            Node* newNode = new Node(second);
            temp->right = newNode;
            q.push(newNode);
         }
    }
   return root;
}
int main(){
    Node* root = BinaryTree();

    cout<<"The root Node is: "<<root->val<<endl;
    cout<<"The left child of the root is: "<<root->left->val<<endl;
    cout<<"The right child of the root is: "<<root->right->val<<endl;
    return 0;
}