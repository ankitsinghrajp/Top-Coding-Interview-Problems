#include<iostream>
#include<stack>
using namespace std;
class Queue{
    public:
       stack<int> st1;
       stack<int> st2;

       void push(int x){
          st1.push(x);
       }

       void pop(){
        if(st2.empty()){

            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
             }
          if(!st2.empty()){
            st2.pop();
          }
          else{
            cout<<"Queue is empty..."<<endl;
          }
       
       }

       int top(){
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(!st2.empty()){
        return st2.top();
    }else{
        cout<<"The queue is empty!"<<endl;
        return -1;
    }
       }

       int size(){
         return st1.size() + st2.size();
       }

};
int main(){

    Queue q;
    q.push(5);
    q.push(10);
    q.push(15);
    q.push(20);

    cout<<"The size of the queue is: "<<q.size()<<endl;
    cout<<"The top element of the queue is: "<<q.top()<<endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<"The top element of the queue  is: "<<q.top()<<endl;

    return 0;
}