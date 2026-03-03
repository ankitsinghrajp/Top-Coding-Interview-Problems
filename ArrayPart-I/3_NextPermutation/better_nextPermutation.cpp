#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){

    vector<int> arr = {3,1,2};
    cout<<"The original array is: "<<endl;
    printArray(arr);

    cout<<"The next permutation is: "<<endl;
    next_permutation(arr.begin(), arr.end());
    printArray(arr);

   return 0;
}