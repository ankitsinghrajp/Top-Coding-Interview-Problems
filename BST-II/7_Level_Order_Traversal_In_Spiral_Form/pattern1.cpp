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

    vector<int> levelOrderSpiralForm(Node* root){
        if(!root) return {};
        vector<int> ans;
        stack<Node*> st1;
        stack<Node*> st2;

        st1.push(root);
        while(!st1.empty() || !st2.empty()){
            if(!st1.empty()){
                while(!st1.empty()){
                    Node* temp = st1.top();
                    st1.pop();
                   
                    ans.push_back(temp->data);

                    if(temp->left) st2.push(temp->left);

                    if(temp->right) st2.push(temp->right);

                }
            }

            while(!st2.empty()){
                Node* temp = st2.top();
                st2.pop();

                ans.push_back(temp->data);

                if(temp->right) st1.push(temp->right);
                if(temp->left) st1.push(temp->left);
            }
        }
      return ans;
    }
   

   
};

void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    binaryTree bt;
    Node* root = bt.create("Enter the root Node: ");
    cout<<"Printing the tree in level order spiral form: "<<endl;
    

    vector<int> result = bt.levelOrderSpiralForm(root);
    printArray(result);
    return 0;
}