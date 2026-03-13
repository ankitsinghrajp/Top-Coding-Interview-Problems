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

Node* sumOfLinkedList(Node* list1, Node* list2){
    Node dummy;
    Node* temp = &dummy;

    int carry = 0;
    while(list1 != nullptr || list2 != nullptr || carry){
         int sum = 0;
         
         if(list1 != nullptr){
            sum += list1->data;
            list1 = list1->next;
         }

         if(list2 != nullptr){
            sum += list2->data;
            list2 = list2->next;
         }

         sum += carry;

         carry = sum/10;
         Node* newNode = new Node();
         newNode->data = (sum%10);
         newNode->next = nullptr;
         temp->next = newNode;
         temp = newNode;
    }
    return dummy.next;
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

    Node* list2 = new Node();
    list2->data = 5;

    Node* fourth = new Node();
    Node* fifth = new Node();

    fourth->data = 6;
    list2->next = fourth;

    fifth->data = 4;
    fourth->next = fifth;
    fifth->next = nullptr;

    cout<<"The first list is: "<<endl;
    printLinkedList(list1);

    cout<<"The second list is: "<<endl;
    printLinkedList(list2);

    Node* sumNode = sumOfLinkedList(list1, list2);
    printLinkedList(sumNode);

    return 0;
}