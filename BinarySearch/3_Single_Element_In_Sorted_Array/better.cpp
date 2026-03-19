#include<iostream>
#include<vector>
using namespace std;
int singleElement(vector<int> &arr){
   if(arr.size() == 1) return arr[0];
   
   for(int i = 0;i<arr.size()-1; i+= 2){
     if(arr[i] != arr[i+1]) return arr[i];
   }
   return arr.back();
}
int main(){
    vector<int> arr = {1,1,2,3,3,4,4,5,5,6,6};

    cout<<"The single element in the sorted array is: "<<singleElement(arr);
    return 0;
}