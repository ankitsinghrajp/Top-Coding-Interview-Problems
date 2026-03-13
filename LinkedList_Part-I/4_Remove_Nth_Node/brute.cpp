#include<iostream>
using namespace std;
class Node{
    public:
       int data;
       Node* next;
};

void printLinkedList(Node* Head){
    Node* temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<endl;
};



int main(){
   Node* Head = new Node();
   Head->data = 1;
   
   Node* second = new Node();
   Node* third = new Node();
   Node* fourth = new Node();
   Node* fifth = new Node();
   
   second->data = 2;
   Head->next = second;
   
   third->data = 3;
   second->next = third;

   fourth->data = 4;
   third->next = fourth;

   fifth->data = 5;
   fourth->next = fifth;
   fifth->next = nullptr;

   printLinkedList(Head);

    return 0;
}