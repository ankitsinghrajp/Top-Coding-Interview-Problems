#include<iostream>
#include<vector>
using namespace std;
int countInversion(vector<int> arr){
   int count = 0;
   for(int i = 0;i<arr.size();i++){
    for(int j = i+1;j<arr.size();j++){
        if(arr[i]>arr[j]){
            count +=1;
        }
    }
   }

   return count;
}
int main(){
    vector<int> arr = {5,3,2,4,1};
    
    cout<<"The count of the inversion of array is: "<<countInversion(arr);
    return 0;
}