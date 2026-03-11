#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
     int data;
     Node* next;
};

void printLinkedList(Node* Head){
    Node * temp = Head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* convertToLinkedList(vector<int> arr){
    Node* Head = new Node();
    Head->data = arr[0];
    Node* temp = Head;
    
    for(int i = 1;i<arr.size();i++){
        Node* newNode = new Node();
        newNode->data = arr[i];
        newNode->next = nullptr;
        temp->next = newNode;
        temp = newNode;
    }
    return Head;
}

void insertAtMiddle(Node* Head, int element, int x){
    Node* temp = Head;
    while(temp->data != element){
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}

Node* insertAtStart(Node* Head, int x){
    Node * newNode = new Node();
    newNode->data = x;
    newNode->next = Head;
    Head = newNode;
    return Head;
}

void insertAtBack(Node* Head, int x){
    Node* temp = Head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    temp->next = newNode;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    
    Node* Head = convertToLinkedList(arr);

    insertAtMiddle(Head,5,555);
    insertAtBack(Head,678);
    Node* newHead = insertAtStart(Head,100);
    printLinkedList(newHead);

    return 0;
}