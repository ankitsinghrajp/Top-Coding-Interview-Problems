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

void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> LevelOrder(TreeNode* root){

    if(root == NULL) return {};
    queue<TreeNode* > q;
    q.push(root);

    vector<int> ans;
    while(!q.empty()){
        TreeNode * temp = q.front();
        q.pop();
        ans.push_back(temp->data);

        // pushing the left child
        if(temp->left){
            q.push(temp->left);
        }

        // pushing the right child
        if(temp->right){
            q.push(temp->right);
        }
    }
    return ans;
}

int main(){ 
      
    BinaryTree bt;
    TreeNode* root = bt.create("Enter the root node: ");

    vector<int> result = LevelOrder(root);
    printArray(result);
    return 0;
}