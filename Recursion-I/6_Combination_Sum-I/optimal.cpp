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
void findCombination(vector<int> arr, int index, vector<vector<int>> &ans,vector<int> &temp, int target){
     if(index == arr.size()){
        if(target == 0){
            ans.push_back(temp);
        }
        return;
     }

     if(arr[index] <= target){
        temp.push_back(arr[index]);
        findCombination(arr,index,ans,temp,target-arr[index]);
        temp.pop_back();
     
    }
    findCombination(arr,index+1,ans,temp,target);
}

int main(){
    vector<int> arr = {2,5,6,1};
    vector<vector<int>> ans;
    vector<int> temp;
    int target = 8;
    findCombination(arr,0,ans,temp,target);
    cout<<"The subsets which gives sum "<<target<<" are: "<<endl;
    printArray(ans);
    return 0;
}