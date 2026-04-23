#include<iostream>
#include<vector>
#include<queue>
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
    
    void findLeftRightMost(Node* root, int pos, int &l, int &r){
         if(!root) return;

         l = min(pos,l);
         r = max(pos,r);

         findLeftRightMost(root->left,pos-1,l,r);
         findLeftRightMost(root->right,pos+1,l,r);
    }
    vector<int> bottomViewOfBT(Node* root){
        int l = 0;
        int r = 0;

        findLeftRightMost(root, 0, l, r);

        vector<int> result(r-l+1);
        queue<Node*> q;
        queue<int> index;

        q.push(root);
        index.push(-1* l);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            int pos = index.front();
            index.pop();

            result[pos] = temp->data;
            
            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
            }

            if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
            }
        }

        return result;
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

   vector<int> result = bt.bottomViewOfBT(root);

   cout<<"The bottom view of binary Tree is: "<<endl;
   printArray(result);

    return 0;
}