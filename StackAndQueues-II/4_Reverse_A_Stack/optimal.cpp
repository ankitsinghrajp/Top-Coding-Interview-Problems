#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void insertAtBottom(stack<int> &st, int element){
    if(st.empty()) {
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();
    insertAtBottom(st,element);
    st.push(temp);
}
void reverseStack(stack<int> &st){
    if(st.empty()) return;

    int x = st.top();
    st.pop();

    reverseStack(st);
    insertAtBottom(st,x);
}
int main(){
    stack<int> st;
    st.push(3);
    st.push(4);
    st.push(1);
    st.push(8);
    st.push(2);

    
    cout<<"The original stack is: "<<endl;
    printStack(st);
    cout<<"The reversed stack is: "<<endl;
    reverseStack(st);
    printStack(st);
    return 0;
}