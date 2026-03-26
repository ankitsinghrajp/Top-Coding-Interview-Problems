#include<iostream>
using namespace std;
class Stack{
    public:
      int st[10]; int topVar = -1; int s = 0;
      
     void push(int x){
        if(s == 10) {
            cout<<"Out of memory"<<endl;
            return;
        }
        topVar += 1;
        st[topVar] = x;
          s += 1;
     }

     int pop(){
        if(s == 0){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }

        int element = st[topVar];
        topVar -= 1;
        s -= 1;
        return element;
     }

     int top(){
        if(topVar == -1){
            cout<<"No elements in stack!"<<endl;
            return -1;
        }
        else{
            return st[topVar];
        }
     }

     int size(){
        return s;
     }
};
int main(){
    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);
    st.push(25);

    cout<<"The top element of the stack is: "<<st.top()<<endl;
    cout<<"The size of the stack is: "<<st.size()<<endl;
    
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    return 0;
}