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

vector<int> majority(vector<int> arr){
    vector<int> ans;
    unordered_map<int,int> mpp;
    for(int i = 0;i<arr.size();i++){
        mpp[arr[i]] += 1;
    }

    for(auto it: mpp){
        if(it.second > arr.size()/3){
            ans.push_back(it.first);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {2,3,3};
    vector<int> ans = majority(arr);

    cout<<"The majority elements are: ";
    printArray(ans);

    return 0;
}