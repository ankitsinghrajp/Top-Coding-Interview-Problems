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
    unordered_set<ListNode*> st;
    
    ListNode* temp1 = l1;
    while(temp1 != nullptr){
        st.insert(temp1);
        temp1 = temp1->next;
    }
   ListNode* temp2 = l2;
    while(temp2 != nullptr){
       if(st.count(temp2)){
          return temp2;
       }
    temp2 = temp2->next;
    }
    return nullptr;
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