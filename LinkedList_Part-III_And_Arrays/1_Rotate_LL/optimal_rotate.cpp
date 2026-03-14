#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* next;

      Node(int val){
        data = val;
        next = nullptr;
      }
};

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* rotateList(Node* head, int k){
   if(head == nullptr || head->next == nullptr) return head;

   Node* tail = head;
   int n = 1;
   while(tail->next != nullptr){
      tail = tail->next;
      n += 1;
   }

   if(k%n == 0) return head;

   k = k%n;

   Node* temp = head;
   int x = n-k;
   while(--x){
    temp = temp->next;

   }
   Node* newHead = temp->next;
   temp->next = nullptr;

   tail->next = head;
   return newHead;
}
int main(){
  Node* head = new Node(1);
  Node* second = new Node(2);
  head->next = second;
  Node* third = new Node(3);
  second->next = third;
  Node* fourth = new Node(4);
  third->next = fourth;
  Node* fifth = new Node(5);
  fourth->next =fifth;

  cout<<"The original linked list is: "<<endl;
  printLinkedList(head);

  int k = 2;
  Node* rotateListHead = rotateList(head,k);

  cout<<"The list after rotating "<<k<<" places is: "<<endl;
  printLinkedList(rotateListHead);
    return 0;
}