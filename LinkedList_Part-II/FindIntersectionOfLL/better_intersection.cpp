#include<iostream>
#include<unordered_set>
using namespace std;

class ListNode{
    public:
      int val;
      ListNode* next;
};


void printLinkedList(ListNode* head){
    ListNode* temp = head;

    while(temp != nullptr){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* intersection(ListNode* l1, ListNode* l2){
    ListNode* t1 = l1;
    ListNode* t2 = l2;
    int n1 = 0;
    int n2 = 0;

    while(t1 != nullptr){
        t1 = t1->next;
        n1 += 1;
    }
    t1 = l1;
    while(t2 != nullptr){
        t2 = t2->next;
        n2+= 1;
    }
    t2 = l2;

    int d;
    if(n1<n2){
        d = n2-n1;
        while(d--){
            t2 = t2->next;
        }
    }
    else{
        d = n1 - n2;
        while(d--){
            t1 = t1->next;
        }
    }

     while(t1 != nullptr && t2 != nullptr){
        if(t1 == t2){
            return t1;
        }
        t1 = t1->next;
        t2 = t2->next;
     }
   
     return NULL;
}
int main(){
    // First List
    ListNode* l1 = new ListNode();
    l1->val = 3;
    
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();
    ListNode* fourth = new ListNode();
    ListNode* fifth = new ListNode();

    second->val = 1;
    l1->next = second;

    third->val = 4;
    second->next = third;

    fourth->val = 6;
    third->next = fourth;

    fifth->val = 2;
    fourth->next = fifth;
    fifth->next = nullptr;

    // Second list
    ListNode* l2 = new ListNode();
    l2->val = 1;
    
    ListNode* secondl2 = new ListNode();
    ListNode* thirdl2 = new ListNode();
    ListNode* fourthl2 = new ListNode();

    secondl2->val = 2;
    l2->next = secondl2;

    thirdl2->val = 4;
    secondl2->next = thirdl2;

    fourthl2->val = 5;
    thirdl2->next = fourthl2;
    fourthl2->next = third;

    cout<<"The first list is: "<<endl;
    printLinkedList(l1);

    cout<<"The second list is: "<<endl;
    printLinkedList(l2);

    cout<<"The intersection of the lists is: "<<endl;
    ListNode* intersectionHead = intersection(l1,l2);
    printLinkedList(intersectionHead);
    return 0;
}