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

    vector<int> leftViewBT(Node* root){
        queue<Node*> q;
        q.push(root);
        vector<int> ans;

        while(!q.empty()){
            int n = q.size();
            bool pushed = false;
            while(n--){
                Node* temp = q.front();
                q.pop();

              if(!pushed){
                ans.push_back(temp->data);
                pushed = true;
              }

              if(temp->left){
                q.push(temp->left);
              }
              if(temp->right){
                q.push(temp->right);
              }

            }
        }
        
        return ans;
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

   vector<int> result = bt.leftViewBT(root);

   cout<<"The left view of bt is: "<<endl;
   printArray(result);

    return 0;
}