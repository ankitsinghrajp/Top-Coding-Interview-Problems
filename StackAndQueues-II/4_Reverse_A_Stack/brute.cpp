#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void reverseStack(stack<int> &st){
    vector<int> arr;
    while(!st.empty()){
        arr.push_back(st.top());
        st.pop();
    }

    reverse(arr.begin(),arr.end());
    for(int i = 0;i<arr.size();i++){
        st.push(arr[i]);
    }
}
int main(){
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(8);
    st.push(2);

    reverseStack(st);
    return 0;
}