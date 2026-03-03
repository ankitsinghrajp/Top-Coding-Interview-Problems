#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void nextPermutation(vector<int> &arr){
    int index = -1;
    for(int i = arr.size()-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(arr.begin(),arr.end());
        return;
    }

    for(int i = arr.size()-1;i>index;i--){
        if(arr[i]> arr[index]){
            swap(arr[i],arr[index]);
            break;
        }
    }

     reverse(arr.begin()+index+1,arr.end());
}
int main(){
    vector<int> arr = {5,4,3,2,1};
    
    cout<<"The array is: "<<endl;
    printArray(arr);

    cout<<"The next permutation of the array is: "<<endl;
    nextPermutation(arr);
    printArray(arr);

    return 0;
}