#include<iostream>
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

class Queue{
   public:
     Node* start = nullptr;
     Node* end = nullptr;
     int s = 0;

     void push(int x){
        Node* temp = new Node(x);
        if(start == nullptr && end == nullptr) {
             start = temp;
             end = temp;
        }else{
            end->next = temp;
            end = temp;
        }
       
        s += 1;
     }

     int pop(){
       Node* delNode = start;
       if(delNode == nullptr){
        cout<<"The queue is empty!"<<endl;
        return -1;
       }
       int element = delNode->val;
       start = start->next;
       delete delNode;
       if(start == nullptr) end  = nullptr;
       s -=1; 
       return element;
     }

     int top(){
        if(start == nullptr){
            cout<<"The queue is empty!"<<endl;
            return -1;
        }
        return start->val;
     }

    int size(){
        return s;
    }
     
};
int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<"The size of the queue is: "<<q.size()<<endl;
    cout<<"The topmost element of the queue is: "<<q.top()<<endl;
    q.pop();
    q.pop();
    cout<<"The topmost element of the queue is: "<<q.top()<<endl;
    return 0;
}