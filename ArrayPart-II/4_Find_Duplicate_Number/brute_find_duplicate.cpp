#include<iostream>
#include<vector>
using namespace std;
int FindDuplicate(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i] == arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {3,5,2,2,1,6};
    cout<<"The duplicate number is: "<<FindDuplicate(arr);

    return 0;
}