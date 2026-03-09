#include<iostream>
#include<vector>
#include<map>
using namespace std;
int countSubarrays(vector<int> arr,int k){
   map<int,int> preXor;

   int count = 0;
   int xOr = 0;
   for(int i = 0;i<arr.size();i++){
      xOr ^= arr[i];
      if(xOr == k){
        count += 1;
      }

      if(preXor.count(xOr^ k)){
        count += preXor[xOr ^k];
      }
  
        preXor[xOr] ++;
    
   }
     return count;
}
int main(){
    vector<int> arr = {4,2,2,6,4};
    int k = 6;
    
    cout<<"The count of the subarrays is: "<<countSubarrays(arr,k);

    return 0;
}