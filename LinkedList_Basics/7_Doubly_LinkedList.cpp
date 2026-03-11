#include<iostream>
using namespace std;
class Node{
   public:
     int data;
     Node* next;
     Node* prev;
};

void printLinkedList(Node* Head){
    Node*temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* insertAtStart(Node* Head, int x){
    Node* temp = new Node();
    temp->data = x;
    temp->prev = nullptr;
    temp->next = Head;
    if(Head!=nullptr){
        Head->prev = temp;
    }
    Head = temp;
    return Head;
}

Node* insertAtEnd(Node* Head, int x){
    Node* temp = Head;
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(temp == nullptr){
        Head = newNode;
        return Head;
    }

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return Head;
}

Node* insertAtMiddle(Node* Head, int element, int x){
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    Node* temp = Head;
    if(temp == nullptr){
        Head = newNode;
        return Head;
    }

    while(temp->next!=nullptr && temp->next->data !=element){
        
        temp = temp->next;
    }
    
    if(temp->next !=nullptr){
        newNode->next = temp->next;
        temp->next->prev = newNode;
    }
    temp->next = newNode;
        newNode->prev = temp;
  

    return Head;
}

int main(){
    Node* Head = new Node();
    Head->data = 1;
    Head->prev = nullptr;

    Node* second = new Node();
    second->data = 2;
    second->prev = Head;
    Head->next = second;

    Node* third = new Node();
    third->data = 3;
    second->next = third;
    third->prev = second;

    Node* fourth = new Node();
    fourth->data = 4;
    third->next = fourth;
    fourth->prev = third;
    
    Node* fifth = new Node();
    fifth->data = 5;
    fifth->prev = fourth;
    fourth->next = fifth;
    fifth->next = nullptr;

    
    // insert 100 at start
    // Node* newHead = insertAtStart(Head,100);

    // insert at end of the linked list
    // insertAtEnd(Head,500);

    insertAtMiddle(Head,3,1000);

    printLinkedList(Head);

    return 0;
}