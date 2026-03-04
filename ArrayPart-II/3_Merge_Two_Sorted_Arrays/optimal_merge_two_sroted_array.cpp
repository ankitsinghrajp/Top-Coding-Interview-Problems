#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void mergeTwoArray(vector<int> &arr1, vector<int> &arr2, int m, int n){
     int i = m-1;
     int j = n-1;
     int k = m+n-1;

     while(i >= 0 && j >= 0){
        if(arr1[i] <= arr2[j]){
          arr1[k--] = arr2[j--];
     }
     else{
        arr1[k--] = arr1[i--];
     }
    }

    while(j>= 0){
        arr1[k--] = arr2[j--];
    }

}
int main(){
    vector<int> arr1 = {1,2,3,0,0,0};
    int m = 3;
    vector<int> arr2 = {2,5,6};
    int n = 3;

    cout<<"The first array is: "<<endl;
    printArray(arr1);

    cout<<"The second array is: "<<endl;
    printArray(arr2);

    cout<<"The merged array is: "<<endl;
     mergeTwoArray(arr1,arr2,m,n);
    printArray(arr1);
    return 0;
}