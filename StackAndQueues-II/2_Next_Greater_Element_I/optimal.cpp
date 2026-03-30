#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> nextGreaterElements(vector<int> &arr){
    stack<int> st;
    vector<int> result(arr.size(),-1);
    for(int i = arr.size()-1;i>= 0; i--){
       
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if(!st.empty()) result[i] = st.top();

        st.push(arr[i]);
    }
    
    return result;
}
int main(){
    vector<int> arr = {4,12,5,3,1,2,5,3,1,2,4,6};

    cout<<"The original array is: "<<endl;
    printArray(arr);
    cout<<"The next greater elements array is: "<<endl;
    vector<int> nge = nextGreaterElements(arr);
    printArray(nge);
    return 0;
}