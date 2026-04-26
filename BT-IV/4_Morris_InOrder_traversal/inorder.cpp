#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int value){
        this->data = value;
        this->left = NULL;
        this->right = NULL;
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
         temp->left = create("Enter the left child of "+to_string(temp->data)+" : ");
         temp->right = create("Enter the right child of "+to_string(temp->data)+" : ");
         return temp;
       }

       vector<int> inorder_Traversal(Node* root){
            vector<int> result;
            while(root){
                // Left part does not exists
                if(!root->left){
                    result.push_back(root->data);
                    root = root->right;
                    continue;
                }

                // Left part exists
                Node* curr = root->left;
                while(curr->right && curr->right != root){
                    curr = curr->right;
                }

                // Left part not traversed
                if(curr->right == NULL){
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = NULL;
                    result.push_back(root->data);
                    root = root->right;
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
    BinaryTree* bt = new BinaryTree();
    Node* root = bt->create("Enter the root node: ");
    
    vector<int> result =  bt->inorder_Traversal(root);
    
    cout<<"The inorder traversal of the result is: "<<endl;
    printArray(result);
    return 0;
}