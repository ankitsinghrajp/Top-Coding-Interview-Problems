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
    vector<int> result(arr.size(),-1);
    for(int i = 0;i<arr.size();i++){
       bool nge = false;

       int index = i+1;
       while(index != arr.size()){
          if(arr[i] <arr[index]){
              nge = true;
              result[i] = arr[index];
              break;
          }
          index ++;
       }
       
       if(nge) continue;

       index = 0;
       while(index != i){
        if(arr[index] > arr[i]){
            result[i] = arr[index];
            break;
        }
        index ++;
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