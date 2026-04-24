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

     void find(Node* root, int pos, int &l, int &r){
        if(!root) return;;

        l = min(pos, l);
        r = max(pos, r);

        find(root->left, pos-1, l, r);
        find(root->right, pos+1, l, r);
     }

     vector<vector<int>> verticalOrderTraversal(Node* root){
        if(!root) return {};

        int l = 0;
        int r = 0;
        find(root, 0, l, r);

        vector<vector<pair<int,int>>> positives(r+1);
        vector<vector<pair<int,int>>> negatives(abs(l)+1);

        queue<pair<Node*, pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
           
            Node* temp = it.first;
            int col = it.second.first;
            int row = it.second.second;

            if(col >= 0){
                positives[col].push_back({row,temp->data});
            }
            else{
                int idx = abs(col);
                negatives[idx].push_back({row,temp->data});
            }
           
            
            if(temp->left){
                q.push({temp->left, {col-1,row+1}});
            }

            if(temp->right){
                q.push({temp->right, {col+1,row+1}});
            }
            
        }


        vector<vector<int>> result;

        for(int i = negatives.size()-1;i>= 0;i--){
            if(negatives[i].size()){
                auto temp = negatives[i];

                sort(temp.begin(),temp.end());
                
                vector<int> colVals;
                
                for(int j = 0;j<temp.size();j++){
                    colVals.push_back(temp[j].second);
                }
                result.push_back(colVals);
            }
        }


        for(int i = 0;i<positives.size();i++){
            if(positives[i].size()){
                auto temp = positives[i];
                sort(temp.begin(),temp.end());

                vector<int> colVals;
                for(int j = 0;j<temp.size();j++){
                    colVals.push_back(temp[j].second);
                }
                result.push_back(colVals);
            }
        }

        return result;
        
     }

    };

void printArray(vector<vector<int>> & result){
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    BinaryTree* bt = new BinaryTree();
    Node* root = bt->create("Enter the root node of the tree: ");

    vector<vector<int>> result = bt->verticalOrderTraversal(root);

    printArray(result);

    return 0;
}