#include<iostream>
#include<queue>
using namespace std;

class Stack{

   public:
   queue<int> q;
    void push(int x){
      q.push(x);
      int s = q.size();
      for(int i=1;i<s;i++){
          q.push(q.front());
          q.pop();
      }
      
   }

   void pop(){
     q.pop();
   }

   int top(){
    return q.front();
   }
   int size(){
    return q.size();
   }
};
int main(){
    Stack st;
    st.push(5);
    st.push(10);
    st.push(15);
    st.push(20);

    cout<<"The top element is: "<<st.top()<<endl;
    st.pop();
    cout<<"The top element is: "<<st.top()<<endl;
    st.pop();
    st.pop();
    cout<<"The top element is: "<<st.top()<<endl;
    cout<<"The size of the stack is: "<<st.size()<<endl;
    return 0;
}
