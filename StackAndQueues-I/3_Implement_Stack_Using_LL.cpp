#include<iostream>
#include<vector>
using namespace std;
class Node{
   public: 
     int val;
     Node* next;
    
    Node(int x){
       val = x;
       next = nullptr;
    }
};
class Stack{
    public:
      Node* topPtr = nullptr; 
      int s = 0;

      void push(int x){
         Node * temp = new Node(x);
         temp->next = topPtr;
         topPtr = temp;
         s += 1;
      }
      int pop(){
        if(topPtr == nullptr){
            cout<<"The stack is empty"<<endl;
            return -1;
        }
        Node* delNode = topPtr;
        topPtr = topPtr->next;
        int element = delNode->val;
        delete delNode;
        s -= 1;
        return element;
      }

      int top(){
        if(topPtr == nullptr){
            cout<<"The stack is empty"<<endl;
            return -1;
        }
        return topPtr->val;
      }
    
      int size(){
        return s;
      }
};
int main(){
    Stack st;
    st.push(2);
    st.push(4);
    st.push(6);
    st.push(8);
    st.push(10);
    st.push(12);
    st.push(14);

    cout<<"The size of the stack is: "<<st.size()<<endl;
    cout<<"The top element of the stack is: "<<st.top()<<endl;

    st.pop();
    cout<<"The top element of the stack is: "<<st.top()<<endl;
    cout<<"The top element of the stack is: "<<st.pop()<<endl;

    return 0;
}