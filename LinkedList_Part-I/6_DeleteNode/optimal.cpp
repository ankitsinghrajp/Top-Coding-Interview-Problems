// Deleting means we have the node to be deleted but not have the access to head
//just delete this node any how and get assurance as this node is not the last node

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteNode(Node* node){
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete(temp);
}
int main(){
   
    Node * list1 = new Node();
    list1->data = 2;
    
    Node* second = new Node();
    Node* third = new Node();

    list1->next = second;
    second->data = 4;
    
    third->data = 3;
    second->next = third;
    third->next = nullptr;


    cout<<"The list after deleting node is: "<<endl;
    deleteNode(second);
    printLinkedList(list1);
    return 0;
}