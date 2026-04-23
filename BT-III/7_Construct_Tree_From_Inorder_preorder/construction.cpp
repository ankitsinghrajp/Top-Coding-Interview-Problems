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
       this->left = nullptr;
       this->right = nullptr;
     }
};

class BinaryTree{
    public:
      int find(vector<int> &inorder, int target, int & start, int & end){
        for(int i = start;i<=end;i++){
            if(inorder[i] == target){
                return i;
            }
        }
        return -1;
      }

      Node* Tree(vector<int> & inorder, vector<int> & preorder, int inStart, int inEnd, int index){
         
        if(inStart > inEnd) return nullptr;

        Node* root = new Node(preorder[index]);

        int pos = find(inorder,preorder[index], inStart, inEnd);

        root->left = Tree(inorder,preorder,inStart,pos-1,index+1);
        root->right = Tree(inorder, preorder,pos+1,inEnd,index+(pos-inStart) + 1);
        return root;
      }
};

int main(){
    vector<int> inorder = {4,2,8,5,9,1,6,3,7,10};
    vector<int> preorder = {1,2,4,5,8,9,3,6,7,10};
     
     BinaryTree* bt;
     Node* root = bt->Tree(inorder, preorder, 0,inorder.size()-1,0);
     
    return 0;
}