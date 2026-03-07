#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> twoSum(vector<int> &arr,int target){
    vector<int> ans;
    unordered_map<int,int> mpp;

    for(int i = 0;i<arr.size();i++){
        int prefix = target - arr[i];
        if(mpp.find(prefix)!= mpp.end()){
            ans.push_back(mpp[prefix]);
            ans.push_back(i);
            break;
        }
        else{
            mpp[arr[i]] = i;
        }
    }
   return ans;
}
int main(){
    vector<int> arr = {2,6,5,8,11};
    
    int target = 14;
    cout<<"The target is given by this indices elements: "<<endl;
    vector<int> ans = twoSum(arr,target);
    printArray(ans);

    return 0;
}