#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int first = low;
    int second = mid+ 1;
    while(first <= mid && second <= high){
        if(arr[first] <= arr[second]){
            temp.push_back(arr[first++]);
        }
        else{
            temp.push_back(arr[second++]);
        }
    }

    while(first <= mid){
        temp.push_back(arr[first++]);
    }

    while(second <= high){
        temp.push_back(arr[second++]);
    }

    for(int i = low;i<= high;i++){
        arr[i] = temp[i-low];
    }
}

int countPairs(vector<int> &arr,int low, int mid, int high){
    int count = 0;
    int right = mid +1;
    for(int i = low;i<= mid;i++){
        while(right <= high && arr[i] > 2LL * arr[right]){
            right++;
        }
        count += (right - (mid+1));
    }
    return count;
}

int mergeSort(vector<int> &arr,int low, int high){
    int count = 0;
   if(low >= high) return 0;

   int mid = (low + high)/2;
   count += mergeSort(arr,low,mid);
   count += mergeSort(arr,mid+1,high);
   count += countPairs(arr,low,mid,high);
   merge(arr,low,mid,high);
   return count;
}

int main(){
    vector<int> arr = {40,25,19,12,9,6,2};
   
    int pairs = mergeSort(arr,0,arr.size()-1);
    
    cout<<"The pairs are: "<<pairs<<endl;

    return 0;
}