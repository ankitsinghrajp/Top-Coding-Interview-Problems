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

void subsetSums(vector<int> arr, int index, int n, vector<vector<int>> &ans, vector<int> &temp){
    ans.push_back(temp);
    for(int i = index;i<n;i++){
        if(i> index && arr[i] == arr[i-1]) continue;

        temp.push_back(arr[i]);
        subsetSums(arr,i+1,n,ans,temp);
        temp.pop_back();
    }
}
int main(){
    vector<int> arr = {1,2,2};
    vector<vector<int>> ans;
    vector<int> temp;
    subsetSums(arr,0,arr.size(),ans,temp);

    cout<<"The subsets of the given array (with no duplicates) is: "<<endl;

    printArray(ans);
    return 0;
}