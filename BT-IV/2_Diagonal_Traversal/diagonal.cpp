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

    vector<int> diagonalTraversal(Node* root){
        if(!root) return {};

        vector<int> result;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
           Node* temp = q.front();
           q.pop();

           while(temp){
             result.push_back(temp->data);

             if(temp->left){
                q.push(temp->left);
             }

             temp = temp->right;
           }
        }
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

    vector<int> result = bt->diagonalTraversal(root);

    printArray(result);

    return 0;
}