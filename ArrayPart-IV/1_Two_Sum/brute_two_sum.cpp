#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> twoSum(vector<int> arr, int target){
    vector<int> ans;
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i] + arr[j] == target){
                 ans.push_back(i);
                 ans.push_back(j);
            }
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {2,7,11,15};
    int target = 9;

    vector<int> ans = twoSum(arr, target);
    cout<<"The indices of the elements which give target is: "<<endl;
    printArray(ans);
    return 0;
}