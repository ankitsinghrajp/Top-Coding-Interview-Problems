#include<iostream>
#include<vector>
using namespace std;

int reversePair(vector<int> arr){
     int count = 0;
    for(int i = 0;i<arr.size();i++){
         for(int j = i+1;j<arr.size();j++){
            if(arr[i]> 2LL *arr[j]){
                count += 1;
            }
         }
    }
    return count;
}
int main(){
    vector<int> arr = {1,3,2,3,1};

    cout<<"The reverse pairs is: "<<reversePair(arr);
    return 0;
}