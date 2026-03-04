// If the problem is of this type
// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output: a[] = [2, 2, 3, 4], b[] = [7, 10]



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void mergeArrays(vector<int> &arr1, vector<int> &arr2){
   int i = arr1.size()-1;
   int j = 0;
   while(i>= 0 && j< arr2.size()){
    if(arr1[i] > arr2[j]){
        swap(arr1[i--],arr2[j++]);
    }
    else{
        i--;
    }
   }

   sort(arr1.begin(),arr1.end());
   sort(arr2.begin(),arr2.end());
}

int main(){
    vector<int> arr1 = {2, 4, 7, 10};
    vector<int> arr2 = {2,3};

    cout<<"The first original array is: "<<endl;
    printArray(arr1);

    cout<<"The second original array is: "<<endl;
    printArray(arr2);

    cout<<"The arrays after merging is: "<<endl;
    mergeArrays(arr1,arr2);
    cout<<"arr1: "<<endl;
    printArray(arr1);

    cout<<"arr2: "<<endl;
    printArray(arr2);
    return 0;
}

