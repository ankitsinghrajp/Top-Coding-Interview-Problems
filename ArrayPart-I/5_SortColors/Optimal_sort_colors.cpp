// Dutch National Flag Algorithm
#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void sortColors(vector<int> &arr){
    int low = 0;
    int mid = 0;
    int high = arr.size()-1;

    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high --;
        }
    }
}
int main(){
    vector<int> arr = {0,1,2,0,1,2,1,2,0,0,0,1};
    
    cout<<"The original colors are: "<<endl;
    printArray(arr);
    
    cout<<"The sorted colors are: "<<endl;
    sortColors(arr);
    printArray(arr);
    return 0;
}