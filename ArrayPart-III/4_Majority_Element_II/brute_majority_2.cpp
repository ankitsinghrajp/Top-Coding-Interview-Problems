#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> majority(vector<int> arr){
    unordered_set<int> st;
    for(int i = 0;i<arr.size();i++){
        int count = 0;
        for(int j = 0;j<arr.size();j++){
            if(arr[i] == arr[j]){
                count += 1;
            }
        }
        if(count> arr.size()/3){
            
            st.insert(arr[i]);
        }
    }
    vector<int> ans;

    for(auto it: st){
        ans.push_back(it);
    }
    return ans;
}
int main(){
    vector<int> arr = {3,2,3};
    vector<int> ans = majority(arr);
    
    cout<<"The majority Element is: ";
    printArray(ans);

    return 0;
}