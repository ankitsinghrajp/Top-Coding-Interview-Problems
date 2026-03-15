#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void subsetSums(vector<int> arr,int index, int n, vector<int> &ans, int sum){
     if(index == n){
        ans.push_back(sum);
        return;
     }

    // Not taking 
      subsetSums(arr,index + 1, n, ans, sum);

      // Taking
      sum += arr[index];
      subsetSums(arr, index + 1, n , ans, sum);
}
int main(){
    vector<int> arr = {2,3};
    vector<int> ans;
    int sum = 0;
    subsetSums(arr,0,arr.size(),ans,sum);
    printArray(ans);
    return 0;
}