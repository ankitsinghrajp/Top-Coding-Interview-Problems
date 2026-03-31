#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> nextGreaterElement(vector<int> &arr){
    int N = arr.size();
   vector<int> result(N, -1);
   for(int i = 0;i< N;i++){
    for(int j = i+1;j< i + N; j++){
        int index = j % N;

        if(arr[index]> arr[i]){
            result[i] = arr[index];
            break;
        }
    }
   }
   return result;
}
int main(){
    vector<int> arr = {2,10,12,1,11};

    cout<<"The original array is: "<<endl;
    printArray(arr);

    cout<<"The next greater element array is: "<<endl;
    vector<int> nge = nextGreaterElement(arr);
    printArray(nge);
    return 0;
}