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

Node* DeleteFromStart(Node* Head){
    if (Head == NULL) return NULL;
     Node* temp = Head;
     Head = Head->next;
     delete(temp);
     return Head;
}

Node* DeleteFromEnd(Node* Head){
    if(Head== NULL) return NULL;
    Node* temp = Head;

    if(Head->next == NULL){
        delete Head;
        return NULL;
    }
    while(temp->next->next !=nullptr){
        temp = temp->next;
    }

    Node* freeNode = temp->next;
    temp->next = nullptr;
    delete(freeNode);

    return Head;
}

Node* DeleteFromMiddleOfList(Node* Head, int x){
    if(Head == NULL) return NULL;

    if(Head->data == x){
        Node* temp = Head;
        Head = Head->next;
        delete temp;
        return Head;
    }

    Node* temp = Head;
    while(temp->next!=nullptr && temp->next->data != x){
        temp = temp->next;
    }

    if(temp->next == nullptr){
        return Head;
    }

    Node* freeNode = temp->next;
    temp->next = temp->next->next;
    delete freeNode;
    return Head;
}
int main(){
    Node* Head = new Node();
    Head->data = 1;
    Node* temp = Head;
    for(int i = 2;i<=10;i++){
        Node* tempNode = new Node();
        tempNode->data = i;
        tempNode->next = nullptr;
        temp->next = tempNode;
        temp = tempNode;
    }

    
    // Delete the first Node
//    Node* newHead = DeleteFromStart(Head);
//     DeleteFromEnd(newHead);
    Node* newHead = DeleteFromMiddleOfList(Head, 8);
    printLinkedList(newHead);
    return 0;
}