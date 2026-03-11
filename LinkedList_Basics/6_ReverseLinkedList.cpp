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
}

Node* reverseLinkedList(Node* Head){
    Node* prev = nullptr;
    Node* curr = Head;
    Node* next = nullptr;

    while(curr!=nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
int main(){
   Node* Head = new Node();
   Head->data = 1;
   
   Node* second = new Node();
   Node* third = new Node();
   Node* fourth = new Node();
   Node* fifth = new Node();
   Node* sixth = new Node();
   Node* seventh = new Node();
   Node* eigth = new Node();
   Node* ninth = new Node();
   Node* tenth = new Node();

   second->data = 2;
   Head->next = second;
   third->data = 3;
   second->next = third;
   fourth->data = 4;
   third->next = fourth;
   fifth->data = 5;
   fourth->next = fifth;
   sixth->data = 6;
   fifth->next = sixth;
   seventh->data = 7;
   sixth->next = seventh;
   eigth->data = 8;
   seventh->next = eigth;
   ninth->data = 9;
   eigth->next = ninth;
   tenth->data = 10;
   ninth->next = tenth;
   tenth->next = nullptr;

  Node* newHead = reverseLinkedList(Head);

   printLinkedList(newHead);

    return 0;
}