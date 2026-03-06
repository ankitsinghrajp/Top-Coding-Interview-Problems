#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int majority(vector<int> arr){
    unordered_map<int,int> mpp;
    for(int i = 0;i<arr.size();i++){
        mpp[arr[i]] += 1;
    }

    for(auto it: mpp){
        if(it.second > arr.size()/2){
            return it.first;
        }
    }
 return -1;
}
int main(){
    vector<int> arr = {2,2,1,1,1,2,2};

    cout<<"The majority element is: "<<majority(arr);
    return 0;
}