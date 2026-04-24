#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
class Node{
    public:
     int data;
     Node* left;
     Node* right;

     Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
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
     void findLefts(Node* root, vector<int> &result){
           if(!root) return;

           if(!root->left && !root->right) return;

           result.push_back(root->data);

           if(root->left){
              findLefts(root->left,result);
           }
           else if(root->right){
            findLefts(root->right,result);
           }
     }

     void findLeaves(Node* root, vector<int> & result){
           if(!root) return;

           if(!root->left && !root->right){
              result.push_back(root->data);
           }

           findLeaves(root->left,result);
           findLeaves(root->right,result);
     }

     void findRights(Node*root, vector<int> &result){
           if(!root) return;

           if(!root->left && !root->right){
            return;
           }

           if(root->right){
              findRights(root->right,result);
           }
           else if(root->left){
            findRights(root->left,result);
           }
           result.push_back(root->data);
     }
     vector<int> boundaryTraversal(Node* root){
           vector<int> result;
           if(!root) return result;

           if(!(root->left == nullptr && root->right == nullptr)){
                result.push_back(root->data);
           }
          
           findLefts(root->left, result);
           findLeaves(root,result);
           findRights(root->right, result);

           return result;
     }

};

void printArray(vector<int> & result){
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
int main(){
    BinaryTree* bt = new BinaryTree();
    Node* root = bt->create("Enter the root node of the tree: ");

    vector<int> result = bt->boundaryTraversal(root);

    printArray(result);

    return 0;
}