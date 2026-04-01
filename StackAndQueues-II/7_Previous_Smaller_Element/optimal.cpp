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

vector<int> previousSmallerElement(vector<int> &arr){
    vector<int> result(arr.size(),-1);
    stack<int> st;
    for(int i = 0;i<arr.size();i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        
        if(!st.empty()){
            result[i] = st.top();
        }
        st.push(arr[i]);
    }
    return result;
}
int main(){
    vector<int> arr = {1, 5, 0, 3, 4, 5};

    cout<<"The original array is: "<<endl;
    printArray(arr);
    cout<<"The previous smaller element array is: "<<endl;
    vector<int> result = previousSmallerElement(arr);
    printArray(result);
    return 0;
}