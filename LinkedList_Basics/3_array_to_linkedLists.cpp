#include<iostream>
#include<vector>
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

Node* convertToLinkedList(vector<int> arr){
    Node* Head = new Node();
    Head->data = arr[0];
    Node* temp = Head;

    for(int i = 1;i<arr.size();i++){
        Node* newNode = new Node();
        newNode->data = arr[i];
        newNode->next = nullptr;
        temp->next =  newNode;
        temp = temp->next;
    }

    return Head;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    Node* Head = convertToLinkedList(arr);

    printLinkedList(Head);
    return 0;
}