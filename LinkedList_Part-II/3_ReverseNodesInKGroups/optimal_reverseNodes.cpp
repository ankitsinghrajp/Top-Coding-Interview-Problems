#include<iostream>
using namespace std;
class Node{
    public:
      int data;
      Node* next;
};

void printLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr) {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void reverseLinkedList(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

}

Node* getKthNode(Node* temp, int k){
    k -= 1;
     while(temp != NULL && k>0){
        k--;
        temp = temp->next;
     }
     return temp;
}

Node * reverseNodesKGroups(Node* head, int k){
     Node* temp = head;
     Node* prevNode = NULL;

     while(temp != NULL){
        Node* kthNode = getKthNode(temp,k);

        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLinkedList(temp);
        if(temp == head){
            head = kthNode;
        }
        else{
            prevNode->next = kthNode;
        }

        prevNode = temp;
        temp = nextNode;
     }
     return head;
}
int main(){
    Node* head = new Node();
    head->data = 1;
    
    Node* second = new Node();
    head->next = second;
    Node* third = new Node();
    second->next = third;
    Node* fourth = new Node();
    third->next = fourth;
    Node* fifth = new Node();
    fourth->next = fifth;
    fifth->next = nullptr;

    second->data = 2;
    third->data = 3;
    fourth->data = 4;
    fifth->data = 5;

    cout<<"The original linked list is: "<<endl;
    printLinkedList(head);
    
    int k = 3;

    cout<<"The linked list after reversing k Node is: "<<endl;
    Node* reversedKthHead = reverseNodesKGroups(head,k);
    printLinkedList(reversedKthHead);

    return 0;
}