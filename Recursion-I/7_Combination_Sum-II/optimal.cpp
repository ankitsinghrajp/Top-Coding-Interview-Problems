#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(vector<vector<int>> arr){
   for(int i = 0;i<arr.size();i++){
    for(int j = 0;j<arr[i].size();j++){
        cout<<arr[i][j]<<" ";
    }
    cout<<endl;
   }
}

void findCombinations(vector<int> arr,int index, int target, vector<vector<int>> &ans, vector<int> &temp){
    if(target == 0){
        ans.push_back(temp);
        return;
    }

   for(int i = index;i<arr.size();i++){

    if(i> index && arr[i] == arr[i-1]) continue;
    
    if(arr[i] > target) break;

    temp.push_back(arr[i]);
    findCombinations(arr,i+1,target - arr[i],ans, temp);
    temp.pop_back();
   }
}
int main(){
     vector<int> arr = {10,1,2,7,6,1,5};
     int target = 8;

     sort(arr.begin(),arr.end());
     vector<vector<int>> ans;
     vector<int> temp;

     findCombinations(arr,0,target,ans,temp);

     cout<<"The combinations by skipping duplicates are: "<<endl;
     printArray(ans);

    return 0;
}