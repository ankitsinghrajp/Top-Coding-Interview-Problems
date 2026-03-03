#include<iostream>
#include<vector>
using namespace std;
int maxSum(vector<int> arr){
    int maxi = INT32_MIN;
    int sum = 0;
    for(int i = 0;i<arr.size();i++){
        if(sum < 0){
            sum = 0;
        }

        sum += arr[i];
        maxi = max(sum,maxi);
    }
    return maxi;
}
int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};

    cout<<"The max sum of this array is: "<<maxSum(arr);

    return 0;
}