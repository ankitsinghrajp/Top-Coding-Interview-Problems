#include<iostream>
#include<vector>
using namespace std;
int maxProfit(vector<int> arr){
    int mini = arr[0];
    int profit = 0;
    for(int i = 1;i<arr.size();i++){
        int cost = arr[i] - mini;
        profit = max(profit,cost);
        mini = min(arr[i],mini);
    }

    return profit;
}
int main(){
    vector<int> arr = {7,1,5,3,6,4};

    cout<<"The max Profit is: "<<maxProfit(arr);
    return 0;
}