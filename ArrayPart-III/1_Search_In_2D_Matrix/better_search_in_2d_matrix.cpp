#include<iostream>
#include<vector>
using namespace std;
bool searchInMatrix(vector<vector<int>> arr, int target){
    for(int i = 0;i<arr.size();i++){
        if(arr[i][0] <= target && arr[i][arr[i].size()-1] >= target){
            for(int j = 0;j<arr[i].size();j++){
                if(arr[i][j] == target){
                    return true;
                }
            }

            return false;
        }
    }
    return false;
}
int main(){
    vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
    cout<<"The array is: "<<endl;
    
    int target = 10;
    bool isPresent = searchInMatrix(arr,target);

    if(isPresent){
        cout<<"The element "<<target<<" is present in the array!";
    }
    else{
        cout<<"The element "<<target<<" is not present in the array!";
    }
    return 0;
}