// most optimal solution binary search on whole matrix;
#include<iostream>
#include<vector> 
using namespace std;
bool findInMatrix(vector<vector<int>> arr, int target){
    int n = arr.size();
    int m = arr[0].size();
    int start = 0;
    int end = n*m - 1;

    while(start <= end){
        int mid = (start + end)/2;
        
        int row = mid/m;
        int col = mid%m;

        if(arr[row][col] == target){
            return true;
        }
        else if(arr[row][col] < target){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    
    int target;
    cout<<"Enter the target which you want to search: ";
    cin>>target;

    bool isPresent = findInMatrix(arr,target);

    if(isPresent){
        cout<<"The element "<<target<<" is present in the array!"<<endl;
    }
    else{
        cout<<"The element "<<target<<" is not present!"<<endl;
    }
    return 0;
}