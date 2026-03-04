#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> mergeTwoArray(vector<int> arr1, vector<int> arr2, int m, int n){
     vector<int> ans;

     int i = 0;
     int j = 0;
     while(i< m && j< n){
        if(arr1[i]<= arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
     }

     while(i<m){
        ans.push_back(arr1[i++]);
     }

     while(j<n){
        ans.push_back(arr2[j++]);
     }
     

     return ans;
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
    vector<int> mergedArray = mergeTwoArray(arr1,arr2,m,n);
    printArray(mergedArray);
    return 0;
}