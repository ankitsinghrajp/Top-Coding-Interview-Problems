#include<iostream>
#include<vector>
using namespace std;
int peakElement(vector<int> &arr){
    int n = arr.size();
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1]> arr[n-2]) return n-1;

    for(int i = 1;i<arr.size()-1;i++){
        if(arr[i]>arr[i-1] && arr[i] > arr[i+1]){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,5,1};

    cout<<"The peak element is present at the index: "<<peakElement(arr);

    return 0;
}