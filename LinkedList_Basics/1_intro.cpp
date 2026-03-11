#include<iostream>
using namespace std;
class Node{
   public: 
      int data;
      Node* next;
};
int main(){

    // Simple way

    // Node n1;
    // n1.data = 10000;
    // n1.next = NULL;
    // Node n2;
    // n2.data = 20000;

    // cout<<"The data is: "<<n1.data<<endl;
    // cout<<"The next pointer is: "<<n1.next;

    // Dynamic Way
    Node* Head;
    Head = new Node();
    Head->data = 345;
    Head->next = nullptr;

    cout<<"The Head data is: "<<Head->data<<endl;
    cout<<"The Head next is: "<<Head->next<<endl;

    return 0;
}