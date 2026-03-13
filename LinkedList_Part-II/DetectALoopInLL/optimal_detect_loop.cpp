#include<iostream>
#include<unordered_set>
using namespace std;

class ListNode{
    public:
      int val;
      ListNode * next;
};

bool detectCycle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
int main(){
    ListNode* head = new ListNode();
    head->val = 5;
    
    ListNode* second = new ListNode();
    ListNode* third = new ListNode();
    ListNode* fourth = new ListNode();
    ListNode* fifth = new ListNode();
    
    second->val = 4;
    head->next = second;

    third->val = 2;
    second->next = third;

    fourth->val = 1;
    third->next = fourth;

    fifth->val = 8;
    fourth->next = fifth;
    fifth->next = third;

    bool isCyclePresent = detectCycle(head);

    if(isCyclePresent){
        cout<<"YES! the cycle is present."<<endl;
    }
    else{
        cout<<"NO! not present."<<endl;
    }

    return 0;
}