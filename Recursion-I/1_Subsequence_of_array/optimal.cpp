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

void subsequenceOfArray(vector<int> &arr,int index, int n, vector<int> &temp, vector<vector<int>> &ans){
    
    if(index == n){
        ans.push_back(temp);
        return;
    }

    // Not taking
     subsequenceOfArray(arr,index+1,n,temp,ans);
    // Taking
    temp.push_back(arr[index]);
    subsequenceOfArray(arr,index+1,n,temp,ans);
    temp.pop_back();
}
int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    int n = arr.size();
    
    subsequenceOfArray(arr,0,n,temp,ans);
    cout<<"The all possible subsequences of the given array are: "<<endl;
    printArray(ans);
    return 0;
}