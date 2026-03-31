#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void printArray(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> nextGreaterElement(vector<int> &arr){
    int N = arr.size();
    vector<int> result(N,-1);
    stack<int> st;
    for(int i = 2*N-1; i>=0;i--){
        int index = i%N;
        while(!st.empty() && st.top() <= arr[index]){
            st.pop();
        }

        if(i < N && !st.empty()){
            result[i] = st.top();
        }
        st.push(arr[index]);
    }
    return result;
}
int main(){
   vector<int> arr = {2,10,12,1,11};

   cout<<"The original array is: "<<endl;
   printArray(arr);
   vector<int> result = nextGreaterElement(arr);
   cout<<"The next greater element array is: "<<endl;
   printArray(result);
    return 0;
}