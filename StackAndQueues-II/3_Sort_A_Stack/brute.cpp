#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}
void insertSorted(stack<int> &st, int element){
   if(st.empty() || st.top() <= element){
      st.push(element);
      return;
   }

   int temp = st.top();
   st.pop();
   insertSorted(st,element);
   st.push(temp);
}
void sortStack(stack<int> &st){
   if(st.empty()) return;

   int x = st.top();
   st.pop();

   sortStack(st);
   insertSorted(st,x);
}
int main(){
    stack<int> st;
    st.push(2);
    st.push(3);
    st.push(1);

    
    cout<<"The original stack is: "<<endl;
    printStack(st);
    
    cout<<"The sorted stack is: "<<endl;
    sortStack(st);
    printStack(st);

    return 0;
}