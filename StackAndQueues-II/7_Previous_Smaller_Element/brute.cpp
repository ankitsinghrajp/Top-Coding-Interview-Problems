#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> previousSmallerElement(vector<int> &arr){
    vector<int> result(arr.size(),-1);
    for(int i = arr.size();i>=0;i--){
        for(int j = i-1;j>=0;j--){
            if(arr[i] > arr[j]){
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}
int main(){
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    cout<<"The original array is: "<<endl;
    printArray(arr);
    cout<<"The previous smaller element array is: "<<endl;
    vector<int> result = previousSmallerElement(arr);
    printArray(result);
    return 0;
}