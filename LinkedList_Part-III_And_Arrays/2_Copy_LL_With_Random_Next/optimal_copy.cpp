#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    int val;
    Node* next;
    Node* random;

    Node(int data){
        val = data;
        next = nullptr;
        random = nullptr;
    }
};
void insertInBetween(Node* head){
    Node* temp = head;
    while(temp!= nullptr){
        Node* newNode = new Node(temp->val);
        newNode->next = temp->next;
        temp->next = newNode;

        temp = temp->next->next;
    }
}
void connectRandomPointers(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        Node* copyNode = temp->next;
        if(temp->random != nullptr){
            copyNode->random = temp->random->next;
        }
        else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

Node* connectNextPointers(Node* head){
    Node* temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;

    while(temp != nullptr){
        res->next = temp->next;
        temp->next = temp->next->next;

        res = res->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
Node* cloneLinkedList(Node* head){
     insertInBetween(head);
     connectRandomPointers(head);
     Node* copyListHead = connectNextPointers(head);
     return copyListHead;
}

void printList(Node* head){
    while(head != nullptr){
        cout << "Node: " << head->val;

        if(head->random)
            cout << " Random: " << head->random->val;
        else
            cout << " Random: NULL";

        cout << endl;

        head = head->next;
    }
}

int main(){

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n1->random = n3;
    n2->random = n1;
    n3->random = n4;
    n4->random = n2;

    Node* head = n1;

    cout << "Original List:\n";
    printList(head);

    Node* clonedHead = cloneLinkedList(head);

    cout << "\nCloned List:\n";
    printList(clonedHead);

    return 0;
}