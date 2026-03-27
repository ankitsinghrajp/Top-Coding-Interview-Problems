#include<iostream>
#include<vector>
using namespace std;

class Queue{
   public:
     const int s = 10; 
     int arr[10]; 
     int currSize = 0;
     int start = -1; 
     int end = -1;

    void push(int x){
        if(currSize == 10){
            cout<<"Queue out of memory!"<<endl;
            return;
        }
        if(currSize == 0){
            start = (start+1)%s;
        }

        end = (end+1)%s;
        arr[end] = x;
        currSize += 1;
    }

    int pop(){
        if(currSize == 0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }

         int element = arr[start];

        if(currSize == -1){
            start = -1;
            end = -1;
        }
        else{
            start = (start + 1)%s;
        }
        
        currSize -= 1;
        return element;
    }

    int top(){
        if(currSize == 0){
            cout<<"Queue is empty!"<<endl;
            return -1;
        }
        return arr[start];
    }

    int size(){
        return currSize;
    }
    

};
int main(){
    Queue q;

    q.push(5);
    q.push(10);
    q.push(15);
    q.push(15);
    q.push(20);
    q.push(34); //
    q.push(7);
    q.push(56);
    q.push(12);
    q.push(5);

   cout<<"The size of the queue is: "<<q.size()<<endl;
   cout<<"The top element of the queue is: "<<q.top()<<endl;
   q.pop();
   q.push(45);
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   q.pop();
   q.pop();

   cout<<"The top element of the queue is: "<<q.top()<<endl;
   cout<<"The size of the queue is: "<<q.size()<<endl;
    return 0;
}