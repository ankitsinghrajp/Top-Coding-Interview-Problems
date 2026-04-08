#include<iostream>
#include<queue>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BinaryTree{
    public:
        TreeNode* create(string msg){
            int x;
            cout<<msg<<" ";
            cin>>x;

            if(x == -1) return NULL;

            TreeNode* temp = new TreeNode(x);
            temp->left = create("Enter the left child of "+to_string(temp->data)+": ");
            temp->right = create("Enter the right child of "+to_string(temp->data)+": ");
            return temp;
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

vector<vector<int>> LevelOrder(TreeNode* root){
       if(root == NULL) return {}; 
       queue<TreeNode*> q;
       q.push(root);
       vector<vector<int>> ans;

       while(!q.empty()){
           int size = q.size();
           vector<int> level;

           for(int i = 0;i<size;i++){
              TreeNode* temp = q.front();
              q.pop();

              level.push_back(temp->data);

              if(temp->left){
                q.push(temp->left);
              }

              if(temp->right){
                q.push(temp->right);
              }
           }
           ans.push_back(level);
       }

       return ans;
}

int main(){ 
      
    BinaryTree bt;
    TreeNode* root = bt.create("Enter the root node: ");

    vector<vector<int>> result = LevelOrder(root);
    printArray(result);
    return 0;
}