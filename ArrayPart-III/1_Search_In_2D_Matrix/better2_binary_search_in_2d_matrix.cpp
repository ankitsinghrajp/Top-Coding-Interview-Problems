#include<iostream>
#include<vector>
using namespace  std;

bool binarySearch(vector<int> arr, int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = (start+end)/2;
    while(start <=end){
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }

        mid = (start +end)/2;
    }
    return false;
}
bool searchInMatrix(vector<vector<int>> arr, int target){
    for(int i = 0;i<arr.size();i++){
        if(arr[i][0] <= target && arr[i][arr[i].size()-1] >= target){
           bool result  = binarySearch(arr[i], target);
           return result;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    
    int target;
    cout<<"Enter the target: ";
    cin>>target;

    bool isPresent = searchInMatrix(arr, target);
    if(isPresent){
        cout<<"The target "<<target<<" is present in the array!";
    }
    else{
        cout<<"target "<<target<<" not present!";
    }

    return 0;
}