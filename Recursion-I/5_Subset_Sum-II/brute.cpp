#include<iostream>
#include<vector>
#include<set>
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

void subsetSums(vector<int> arr, int index, int n, set<vector<int>> &ans, vector<int> &temp){
    if(index == n){
        ans.insert(temp);
        return;
    }

    // Not taking
    subsetSums(arr,index+1,n,ans,temp);

    // Taking
    temp.push_back(arr[index]);
    subsetSums(arr,index+1,n,ans,temp);
    temp.pop_back();
}
int main(){
    vector<int> arr = {1,2,2};
    set<vector<int>> ans;
    vector<int> temp;
    subsetSums(arr,0,arr.size(),ans,temp);

    cout<<"The subsets of the given array (with no duplicates) is: "<<endl;
    vector<vector<int>> final(ans.begin(),ans.end());
    printArray(final);
    return 0;
}