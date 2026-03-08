#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void printArray(vector<vector<int>> &arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


vector<vector<int>> threeSum(vector<int> arr){
    set<vector<int>> st;
     for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            for(int k = j+1;k<arr.size();k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> ans = {arr[i],arr[j],arr[k]};
                    sort(ans.begin(),ans.end());

                    st.insert(ans);
                }
            }
        }
     }
     vector<vector<int>> ans(st.begin(),st.end());
     return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
   
    cout<<"The pairs which sum gives 0 are: "<<endl;
    vector<vector<int>> ans = threeSum(arr);
    printArray(ans);
    return 0;
}