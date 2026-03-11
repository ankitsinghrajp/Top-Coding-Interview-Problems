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

}

Node* convertToLinkedListReverseOrder(vector<int> arr){
    Node* Head = new Node();
    Head->data = arr[0];
    Head->next = nullptr;
    for(int i = 1;i<arr.size();i++){
        Node* temp = new  Node();
        temp->data = arr[i];
        temp->next = Head;
        Head = temp;
    }
    return Head;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    Node* Head = convertToLinkedListReverseOrder(arr);

    printLinkedList(Head);

    return 0;
}