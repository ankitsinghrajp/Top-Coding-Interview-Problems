#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

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
    
    
    vector<int> postOrder_Iterative(Node* root){
        vector<int> result;
        if(!root) return result;
        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        result.push_back(temp->data);
        
        if(temp->left) st.push(temp->left);

        if(temp->right){
            st.push(temp->right);
        }

    }
}
};

void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node of the tree");
    
    cout<<"The preorder traversal of the tree is: "<<endl;
    vector<int> ans = bt.postOrder_Iterative(root);
    
    reverse(ans.begin(),ans.end());
    cout<<"The post order traversal of the tree is: "<<endl;
    printArray(ans);
    return 0;
}