#include<iostream>
using namespace std;

class Node{
    public:
       int data;
       Node* next;
};

void printLinkedList(Node* Head){
    Node* temp = new Node();
    temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}
int main(){
    Node* Head;
    Head = new Node();
    
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();
    Node* fifth = new Node();

    Head->data = 20;
    Head->next = second;
    second->data = 10;
    second->next = third;
    third->data = 15;
    third->next = fourth;
    fourth-> data = 25;
    fourth->next = fifth;
    fifth->data = 50;
    fifth->next = nullptr;



    // Insert element at start of the linked list

    // Node* temp = new Node();
    // temp->data = 5;
    // temp->next = Head;
    // Head = temp;





    // Insert element at the middle of the linked list

    // Lets insert 19 between 15 and 25

    // Node* temp = Head;
    // while(temp!= nullptr){
    //     if(temp->data == 15){
    //         break;
    //     }

    //     temp = temp->next;
    // }

    // Node * newNode = new Node();
    //         newNode -> data = 19;
    //         newNode->next = temp->next;
    //         temp->next = newNode;

    




    // Insert element at the end of the linked list

    Node* temp = Head;
    while(temp->next !=nullptr){
        temp = temp->next;
    }
    
    Node* newNode = new Node();
    newNode->data = 60;
    newNode->next = nullptr;
    temp->next = newNode;

    printLinkedList(Head);
    return 0;
}