#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> fourSum(vector<int> arr, int target){
   set<vector<int>> st;
   for(int i = 0;i<arr.size();i++){
      for(int j = i+1;j<arr.size();j++){
        set<int> HashMap;
        for(int k = j+1;k<arr.size();k++){
            long long sum = arr[i] + arr[j] + arr[k];
            long long fourth = (long long) target - sum;
            if(fourth >= INT32_MIN && fourth <= INT32_MAX && HashMap.find(fourth)!= HashMap.end()){
                vector<int> result = {arr[i],arr[j],arr[k],(int)fourth};
                sort(result.begin(),result.end());
                st.insert(result);
            }
            else{
                HashMap.insert(arr[k]);
            }
        }
      }
   }
   vector<vector<int>> ans(st.begin(),st.end());
   return ans;
}
int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;
    cout<<"The elements which gives target are: "<<endl;
    
    vector<vector<int>> ans = fourSum(arr,target);
    printArray(ans);

    return 0;
}