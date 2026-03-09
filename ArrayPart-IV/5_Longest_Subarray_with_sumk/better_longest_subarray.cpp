#include<iostream>
#include<vector>
#include<map>
using namespace std;

int lenOfLongest(vector<int> arr,int k){
    map<long long,int> preSum;
    int sum = 0;
    int longest = 0;
    for(int i = 0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k){
            longest = max(longest,i+1);
        }

        if(preSum.count(sum-k)){
            int len = i - preSum[sum-k];
            longest = max(len,longest);
        }
        
        if(!preSum.count(sum)){
            preSum[sum] = i;
        }
    }
    return longest;

}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    cout<<"The longest subarray is: "<<lenOfLongest(arr,k);

    return 0;
}