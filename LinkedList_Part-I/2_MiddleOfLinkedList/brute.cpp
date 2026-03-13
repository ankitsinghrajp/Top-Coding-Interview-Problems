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

Node* MiddleOfLinkedList(Node* Head){

    Node* temp = Head;
    int count = 0;
    while(temp!=nullptr){
        count ++;
        temp = temp->next;
    }

    int middleNode = (count/2) + 1;
    
    temp = Head;
    while(middleNode != 1){
       temp = temp->next;
       middleNode--;
    }

    return temp;
}

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

   Node* middleNode = MiddleOfLinkedList(Head);

   cout<<"The middle of the linked list is: "<<endl;
   printLinkedList(middleNode);

    return 0;
}