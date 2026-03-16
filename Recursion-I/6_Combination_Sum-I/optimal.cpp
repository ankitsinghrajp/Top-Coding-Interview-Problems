#include<iostream>
#include<vector>
using namespace std;
void subsetSums(vector<int> arr, int index, vector<vector<int>> &ans,vector<int> temp, int target){
    
}
int main(){
    vector<int> arr = {2,5,6,1};
    vector<vector<int>> ans;
    vector<int> temp;
    int target = 8;
    subsetSums(arr,0,ans,temp,target);
    cout<<"The subsets which gives sum: "<<target<<" are: "<<endl;
    printArray(ans);
    return 0;
}