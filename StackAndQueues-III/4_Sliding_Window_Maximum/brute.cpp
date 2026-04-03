#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> slidingWindowMaximum(vector<int> &arr, int k){
    if(k> arr.size() || k<= 0) return {};
    vector<int> result;
   for(int i = 0;i<arr.size()-k+1;i++){
    int maxi = arr[i];
    for(int j = i;j<i+k;j++){
        maxi = max(maxi, arr[j]);
    }
    result.push_back(maxi);
   }
   return result;
}
int main(){
   vector<int> arr = {1,3,-1,-3,5,3,7,1,6};
   int k = 3;

   cout<<"The original array is: "<<endl;
   printArray(arr);

   cout<<"The sliding window maximum is: "<<endl;
   vector<int> result = slidingWindowMaximum(arr,k);
   printArray(result);
    return 0;
}