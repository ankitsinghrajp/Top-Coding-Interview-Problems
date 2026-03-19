#include<iostream>
#include<vector>
using namespace std;
int searchInSortedRotatedArray(vector<int> arr, int target){
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == target){
            return i;
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