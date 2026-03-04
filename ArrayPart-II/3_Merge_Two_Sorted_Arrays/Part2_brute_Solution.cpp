// If the problem is of this type  (problem statement on gfg)
// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output: a[] = [2, 2, 3, 4], b[] = [7, 10]

#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void mergeArrays(vector<int> &arr1, vector<int> &arr2){
    vector<int> ans;
    int left = 0;
    int right = 0;

    while(left < arr1.size() && right <arr2.size()){
        if(arr1[left] <= arr2[right]){
            ans.push_back(arr1[left++]);
        }
        else{
            ans.push_back(arr2[right++]);
        }
    }

    while(left < arr1.size()){
        ans.push_back(arr1[left++]);
    }

    while(right < arr2.size()){
        ans.push_back(arr2[right++]);
    }

    for(int i = 0;i<ans.size();i++){
        if(i < arr1.size()){
            arr1[i] = ans[i];
        }
        else{
            arr2[i- arr1.size()]  = ans[i];
        }

    }


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

