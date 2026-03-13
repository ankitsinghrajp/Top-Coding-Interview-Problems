#include<iostream>
#include<unordered_set>
using namespace std;

class ListNode{
    public:
      int val;
      ListNode * next;
};

bool detectCycle(ListNode* head){
    unordered_set<ListNode*> st;
    ListNode* temp = head;
    while(temp != nullptr){
        if(st.count(temp)){
            return true;
        }

        st.insert(temp);
        temp = temp->next;
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
    fifth->next = second;

    bool isCyclePresent = detectCycle(head);

    if(isCyclePresent){
        cout<<"YES! the cycle is present."<<endl;
    }
    else{
        cout<<"NO! not present."<<endl;
    }

    return 0;
}