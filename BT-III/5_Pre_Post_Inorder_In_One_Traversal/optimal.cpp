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
    
    void findPrePostInorder(Node* root, vector<int> &preOrder, vector<int> & postOrder, vector<int> & inOrder){
          if(root == NULL) return;

           stack<pair<Node*,int>> st;

           st.push({root,1});


           while(!st.empty()){
               auto it = st.top();
               st.pop();

               if(it.second == 1){
                   preOrder.push_back(it.first->data);
                   it.second ++;
                   st.push(it);
                   if(it.first->left){
                      st.push({it.first->left,1});
                   }
               }
               else if(it.second == 2){
                inOrder.push_back(it.first->data);
                it.second ++;
                st.push(it);
                if(it.first->right){
                    st.push({it.first->right,1});
                }
               }
               else{
                  postOrder.push_back(it.first->data);
               }
           }
    }  
};

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    
    BinaryTree bt;
    Node* root = bt.create("Enter the root Node of the tree");
    

    vector<int> PreOrder;
    vector<int> PostOrder;
    vector<int> InOrder;

    bt.findPrePostInorder(root, PreOrder, PostOrder, InOrder);
    cout<<"The preOrder Traversal of the tree is: "<<endl;
    printArray(PreOrder);

    cout<<"The inorder Traversal of the tree is: "<<endl;
    printArray(InOrder);
    
    cout<<"The postOrder Traversal of the tree is: "<<endl;
    printArray(PostOrder);

    return 0;
}