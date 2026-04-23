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
     void find(Node* root, int pos, int &l, int &r){
        if(!root) return;

        l = min(pos,l);
        r = max(pos,r);
        find(root->left, pos-1, l,r);
        find(root->right, pos+1, l,r);
     }
     vector<int> verticalOrderTraversal(Node* root){
           if(!root) return {};
            
           int l = 0;
           int r = 0;
           find(root,0,l,r);
        
           vector<vector<int>> negatives(abs(l)+1);
           vector<vector<int>> positives(r+1);
           queue<Node*> q;
           q.push(root);
           queue<int> index;
           index.push(0);

           while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            int pos = index.front();
            index.pop();

            if(pos >= 0){
                positives[pos].push_back(temp->data);
            }
            else{
              int index = abs(pos);
              negatives[index].push_back(temp->data);
            }

            if(temp->left){
                q.push(temp->left);
                index.push(pos-1);
            }
            
            if(temp->right){
                q.push(temp->right);
                index.push(pos+1);
            }

           }

           vector<int> result;
           for(int i = negatives.size()-1;i>=0;i--){
            for(int j = 0;j<negatives[i].size();j++){
                result.push_back(negatives[i][j]);
            }
           }

           for(int i = 0;i< positives.size();i++){
            for(int j = 0;j<positives[i].size();j++){
                result.push_back(positives[i][j]);
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

    vector<int> result = bt->verticalOrderTraversal(root);

    printArray(result);

    return 0;
}