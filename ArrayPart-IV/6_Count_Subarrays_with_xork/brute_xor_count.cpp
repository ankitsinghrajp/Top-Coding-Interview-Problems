#include<iostream>
#include<vector>
using namespace std;
int countSubarrays(vector<int> arr, int k){
    int count = 0;
    for(int i = 0;i<arr.size();i++){
        int xOr = 0;
        for(int j = i;j<arr.size();j++){
            xOr ^= arr[j];
            if(xOr == k){
                count += 1;
            }
        }
       
    }
    return count;
}
int main(){
    vector<int> arr = {4,2,2,6,4};

    int k = 6;

    cout<<"The number of subarrays with xor k is: "<<countSubarrays(arr,k);

    return 0;
}