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

      bool parent(Node* root, int x, int y){

         if(!root) return 0;

         if(root->left && root->right){
            if(
                (root->left->data == x && root->right->data == y)
                ||
                (root->left->data == y && root->right->data == x)
            )
            {
                return 1;
            }
         }

         return parent(root->left, x, y) || parent(root->right, x, y);
      }

      bool nodeCousins(Node* root, int x, int y){
           queue<Node*> q;
           int l1 = -1;
           int l2 = -1;
           int level = 0;

           q.push(root);
           
           while(!q.empty()){
               int n = q.size();

               while(n--){
                Node* temp = q.front();
                q.pop();

                if(temp->data == x){
                    l1 == level;
                }
                
                if(temp->data == y){
                    l2 == level;
                }

                if(temp->left){
                    q.push(temp->left);
                }

                if(temp->right){
                    q.push(temp->right);
                }
               }
               level += 1;

               if(l1 != l2){
                return 0;
               }

               if(l1 != -1){
                break;
               }
           }  
           return !parent(root,x,y); 
      }
   
};

void printArray(vector<vector<int>> &arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[i].size();j++){
          cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    binaryTree bt;
    Node* root = bt.create("Enter the root Node: ");
    

    bool result = bt.nodeCousins(root,4,6);
    if(result){
        cout<<"YES! the two nodes are cousin nodes!"<<endl;
    }
    else{
        cout<<"NO!  the two nodes are not cousins!"<<endl;
    }
    return 0;
}