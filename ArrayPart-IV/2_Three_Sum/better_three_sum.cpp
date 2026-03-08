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
        set<int> HashMap;
        for(int j = i+1;j<arr.size();j++){
             int third = -(arr[i]+arr[j]);
             
             if(HashMap.find(third) != HashMap.end()){
                vector<int> temp = {arr[i],arr[j],third};
                sort(temp.begin(),temp.end());
                st.insert(temp);
             }

            HashMap.insert(arr[j]);
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