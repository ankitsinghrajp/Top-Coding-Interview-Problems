#include<iostream>
#include<vector>
using namespace std;

int lenOfLongest(vector<int> arr,int k){
    int len = 0;
    for(int i = 0;i<arr.size();i++){
        int sum = 0;
        int count = 0;
        for(int j = i;j<arr.size();j++){
            sum += arr[j];
            count += 1;
            if(sum == k){
              len = max(len,count);
            }
        }
    }
    return len;
}

int main(){
    vector<int> arr = {1,2,3,1,1,1,1,4,2,3};
    int k = 3;
    cout<<"The longest subarray is: "<<lenOfLongest(arr,k);

    return 0;
}