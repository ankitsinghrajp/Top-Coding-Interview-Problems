#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
vector<int> maxSubarray(vector<int> arr){
    vector<int> resultant;
    int maxi = INT32_MIN;
    int sum = 0;
    int start = 0;
    int ansStart = -1;
    int ansEnd = -1;
    for(int i = 0;i<arr.size();i++){
        if(sum == 0){
          start = i;
        }

        sum += arr[i];
        if(maxi<sum){
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if(sum < 0){
            sum = 0;
        }
    }

    for(int i = ansStart; i <= ansEnd; i++){
        resultant.push_back(arr[i]);
    }

    return resultant;
}
int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"The longest subarray is: "<<endl;
    vector<int> result = maxSubarray(arr);

    cout<<"The subarray is: "<<endl;
    printArray(result);
    return 0;
}