#include<iostream>
#include<vector>
using namespace std;
int searchInSortedRotatedArray(vector<int> arr, int target){
    int start = 0;
    int end = arr.size()-1;

    while(start <= end){
        int mid = start + (end-start)/2;

        if(arr[mid] == target) return mid;
        
        // First half is sorted
        if(arr[start] <= arr[mid]){
           if(arr[start] <= target && arr[mid] >= target){
               end = mid - 1;
           }
           else{
            start = mid + 1;
           }
        }
        // The second half is sorted
        else{
          if(arr[mid] < target && target <= arr[end]){
            start = mid + 1;
          }
          else{
            end = mid - 1;
          }
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {3,4,5,6,7,1,2,3};
    int target = 1;

    int result = searchInSortedRotatedArray(arr,target);
    if(result != -1){
        cout<<"The element is present at index: "<<result<<endl;
    }
    else{
        cout<<"The element is not present in the array!"<<endl;
    }
    return 0;
}