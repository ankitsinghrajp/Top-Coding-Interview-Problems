#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void permutations(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, vector<bool> visited){
    if(arr.size() == temp.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 0;i<arr.size();i++){
        if(visited[i] == 0){
            visited[i] = 1;
            temp.push_back(arr[i]);
            permutations(arr,ans,temp,visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(arr.size(),0);
    permutations(arr,ans,temp,visited);
    cout<<"The permutations of the given array is: "<<endl;
    printArray(ans);
    return 0;
}