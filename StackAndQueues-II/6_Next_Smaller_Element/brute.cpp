#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> nextSmallerElement(vector<int> &arr){
    vector<int> result(arr.size(),-1);
    for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            if(arr[i] > arr[j]){
                result[i] = arr[j];
                break;
            }
        }
    }
    return result;
}
int main(){
    vector<int> arr = {4, 8, 5, 2, 25};

    cout<<"The original array is: "<<endl;
    printArray(arr);
    cout<<"The next smaller element is: "<<endl;
    vector<int> result = nextSmallerElement(arr);
    printArray(result);
    return 0;
}