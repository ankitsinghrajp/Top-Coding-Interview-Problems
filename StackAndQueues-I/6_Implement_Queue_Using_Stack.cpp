#include<iostream>
#include<stack>
using namespace std;

class Queue{
    public:
    stack<int> st1;
    stack<int> st2;

    void push(int x){
        if(st1.size() == 0){
            st1.push(x);
            return;
        }
        
       while(!st1.empty()){
          st2.push(st1.top());
          st1.pop();
       }

        st1.push(x);

       while(!st2.empty()){
        st1.push(st2.top());
        st2.pop();
       }
    }

    int pop(){
        int element = st1.top();
        st1.pop();
        return element;
    }

    int top(){
        if(st1.size() != 0){
            return st1.top();
        }
        else{
            cout<<"The stack is empty!"<<endl;
            return -1;
        }
    }
   
    int size(){
        return st1.size();
    }
    
};
int main(){
    Queue q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);
    q.pop();

    cout<<"The top element of the queue is: "<<q.top()<<endl;
    cout<<"The size of the queue is: "<<q.size()<<endl;
    return 0;
}