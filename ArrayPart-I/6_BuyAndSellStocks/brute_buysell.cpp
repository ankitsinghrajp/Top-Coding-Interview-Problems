#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> arr){
    int maxProfit = 0;
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            int profit = arr[j] - arr[i];
            maxProfit = max(profit,maxProfit);
        }
    }

    return maxProfit;
}
int main(){
    vector<int> arr = {7,1,5,3,6,4};
    cout<<"The max profit is: "<<maxProfit(arr);
    return 0;
}