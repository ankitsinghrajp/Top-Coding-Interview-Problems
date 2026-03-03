#include<iostream>
#include<vector>
using namespace std;
int maxSum(vector<int> arr){
    int maxi = INT32_MIN;
    for(int i = 0;i<arr.size();i++){
        int sum = 0;
        for(int j = i;j<arr.size();j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}
int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"The maximum sum of the array is: "<<maxSum(arr);
    return 0;
}