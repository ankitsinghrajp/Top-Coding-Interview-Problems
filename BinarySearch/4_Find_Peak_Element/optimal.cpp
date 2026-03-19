#include<iostream>
#include<vector>
using namespace std;
int peakElement(vector<int> &nums){
    int n = nums.size();
    if(n == 1) return 0;
    if(nums[0] > nums[1]) return 0;
    if(nums[n-1] > nums[n-2]) return n-1;

    int start = 1;
    int end = n-2;

    while(start <= end){
        int mid = start + (end- start)/2;
        if(nums[mid-1] <nums[mid] && nums[mid]> nums[mid+1]){
            return mid;
        }

        if(nums[mid] <nums[mid+1]){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }
    }

    return -1;
}
int main(){
    vector<int> arr = {1,2,1,4,5,6,7,8,5,1};

    cout<<"The peak element is present at the index: "<<peakElement(arr);

    return 0;
}