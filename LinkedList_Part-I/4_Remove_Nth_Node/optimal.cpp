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

Node* removeNthNode(Node* Head, int N){
   Node* slow = Head;
   Node* fast = Head;
   
   for(int i = 0;i<N;i++){
       fast = fast->next;
   }

   if(fast == nullptr){
    Node* delNode = Head;
    Head = Head->next;
    delete delNode;
    return Head;
   }
  
 
   while(fast->next != nullptr){
    slow = slow->next;
    fast = fast->next;
   }

    Node* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
   return Head;
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

   int N = 2;
   Node* removedNthNode = removeNthNode(Head,N);

   cout<<"The list after removing nth node is: "<<endl;
   printLinkedList(removedNthNode);
    return 0;
}