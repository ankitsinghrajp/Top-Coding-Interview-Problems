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

vector<int> twoSum(vector<int> nums,int target){
    vector<int> ans;
    vector<pair<int,int>> arr;
    for(int i = 0; i<nums.size();i++){
        arr.push_back({nums[i],i});
    }

    sort(arr.begin(),arr.end());

    int start = 0;
    int end = arr.size()-1;
    while(start< end){
        if(arr[start].first + arr[end].first == target){
            ans.push_back(arr[start].second);
            ans.push_back(arr[end].second);
            return ans;
        }
        else if(arr[start].first + arr[end].first < target){
            start ++;
        }
        else{
            end --;
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