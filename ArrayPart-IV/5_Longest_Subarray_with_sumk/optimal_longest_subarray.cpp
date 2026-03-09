// This solution only works for positives values 
// For negative the optimal solution is better one

#include<iostream>
#include<vector>
using namespace std;

int lenOfLongest(vector<int> arr, int k){
    int first = 0;
    int second = 0;
    int sum = 0;
    int longest = 0;
    while(second<arr.size()){
        sum += arr[second];
        if(sum == k){
         int len = second - first + 1;
         longest = max(len,longest);
        }
        
        if(sum > k){
            while(sum>k){
                sum -= arr[first];
                first ++;
            }
        }
        second ++;
    }
    return longest;
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};

    int k = 3;

    cout<<"The longest subarray length with given sum k is: "<<lenOfLongest(arr,k);

    return 0;
}