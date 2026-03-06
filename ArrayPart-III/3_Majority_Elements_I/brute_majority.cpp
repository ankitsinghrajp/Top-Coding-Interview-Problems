#include<iostream>
#include<vector>
using namespace std;
int majority(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        int count = 0;
        for(int j = i;j<arr.size();j++){
               if(arr[i] == arr[j]){
                count += 1;
               }
        }
        if(count > arr.size()/2){
            return arr[i];
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {2,2,1,1,1,2,2};

    cout<<"The majority element in the array is: "<<majority(arr);
    return 0;
}