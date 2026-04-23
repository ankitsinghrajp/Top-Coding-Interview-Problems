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
    
    
    vector<int> inOrder_Iterative(Node* root){
       vector<int> result;
       if(!root) return result;

       stack<Node*> st;
       stack<bool> visited;
       st.push(root);
       visited.push(0);
       

       while(!st.empty()){
        Node* temp = st.top();
        st.pop();
         
        int visit = visited.top();
        visited.pop();

        if(visit){
            result.push_back(temp->data);
            continue;
        }

        if(temp->left){
            st.push(temp->left);
            visited.push(0);
        }

        st.push(temp);
        visited.push(1);

        if(temp->right){
            st.push(temp->right);
            visited.push(0);
        }

       }
     return result;
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
    vector<int> ans = bt.inOrder_Iterative(root);
    
    reverse(ans.begin(),ans.end());
    cout<<"The post order traversal of the tree is: "<<endl;
    printArray(ans);
    return 0;
}