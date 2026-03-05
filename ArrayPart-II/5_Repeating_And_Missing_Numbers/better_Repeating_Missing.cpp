#include<iostream>
#include<vector>
#include<map>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> FindMissingRepeating(vector<int> arr){
     vector<int> ans;
     map<int,int> mpp;
     int repeating = -1;
     int missing = -1;

     for(int i = 0;i<arr.size();i++){
        mpp[arr[i]] += 1;
     }

     for(int i = 1;i<=arr.size();i++){
        if(mpp[i] == 2){
            repeating = i;
        }
        else if (mpp[i] == 0){
            missing = i;
        }
     }

     ans.push_back(repeating);
     ans.push_back(missing);

     return ans;
}
int main(){
     vector<int> arr = {4,2,6,3,1,1};
     cout<<"The missing and repeating number is: "<<endl;
     vector<int> ans = FindMissingRepeating(arr);
     printArray(ans);
    return 0;
}