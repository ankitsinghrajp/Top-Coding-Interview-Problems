#include<iostream>
#include<vector>
#include<deque>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> slidingWindowMaximum(vector<int> &arr, int k){
    vector<int> result;
    deque<int> dq;
    for(int i = 0;i<arr.size();i++){
        // remove from frontside if it is outside the window
        if(!dq.empty() && arr[dq.front()] <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] <= arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k-1) result.push_back(arr[dq.front()]);
    }
    return result;
}
int main(){
   vector<int> arr = {1,3,-1,-3,5,3,7,1,6};
   int k = 3;

   cout<<"The original array is: "<<endl;
   printArray(arr);

   cout<<"The sliding window maximum is: "<<endl;
   vector<int> result = slidingWindowMaximum(arr,k);
   printArray(result);
    return 0;
}