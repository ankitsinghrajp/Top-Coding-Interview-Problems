#include<iostream>
#include<vector>
#include<stack>

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
        cout<<msg<<": ";
        cin>> x;

        if(x == -1){
            return NULL;
        }

        Node* temp = new Node(x);
        temp->left = create("Enter the left child of "+to_string(temp->data));
        temp->right = create("Enter the right child of "+ to_string(temp->data));

        return temp;
    }
    
    
    void preOrder_iterative(Node* root){
        if(!root) return;
        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
            Node* temp = st.top();
            st.pop();
            cout<<temp->data<<" ";

            if(temp->right){
                st.push(temp->right);
            }

            if(temp->left){
                st.push(temp->left);
            }
        }
    }
};

int main(){
    
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node of the tree");
    
    cout<<"The preorder traversal of the tree is: "<<endl;
    bt.preOrder_iterative(root);
    
    return 0;
}