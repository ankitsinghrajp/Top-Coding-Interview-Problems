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
    int find(vector<int> &arr, int target, int start, int end){
        for(int i = 0;i<arr.size();i++){
            if(arr[i] == target) return i;
        }
        return -1;
    }
    
    Node* Tree(vector<int> &inorder, vector<int> & postorder, int inStart, int inEnd, int index){
         if(inStart > inEnd) return NULL;

         Node* temp = new Node(postorder[index]);

         int pos = find(inorder,postorder[index], inStart,inEnd);

         temp->left = Tree(inorder, postorder, inStart, pos-1, index - (inEnd - pos) -1);
         temp->right = Tree(inorder, postorder, pos+1, inEnd, index-1);
         return temp;


    }
};
int main(){

    vector<int> inorder = {4,2,6,5,7,1,10,8,9,3};
    vector<int> postorder = {4,6,7,5,2,10,9,8,3,1};

    
    BinaryTree* bt = new BinaryTree();
    Node* root = bt->Tree(inorder,postorder, 0,inorder.size()-1,postorder.size()-1);

    cout<<"The root node of the tree is: "<<root->data<<endl;
    cout<<"The left node of the root is: "<<root->left->data<<endl;
    cout<<"The right node of the root is: "<<root->right->data<<endl;


    return 0;
}