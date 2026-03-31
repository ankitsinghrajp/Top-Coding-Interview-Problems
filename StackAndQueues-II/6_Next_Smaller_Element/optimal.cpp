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

vector<int> nextSmallerElement(vector<int> &arr){
    vector<int> result(arr.size(),-1);
    stack<int> st;

    for(int i = arr.size()-1;i>=0;i--){
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
    vector<int> arr = {4, 8, 5, 2, 25};

    cout<<"The original array is: "<<endl;
    printArray(arr);
    cout<<"The next smaller element is: "<<endl;
    vector<int> result = nextSmallerElement(arr);
    printArray(result);
    return 0;
}