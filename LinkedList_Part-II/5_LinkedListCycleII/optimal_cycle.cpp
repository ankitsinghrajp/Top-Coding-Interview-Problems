#include<iostream>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode* next;
};

ListNode* detectCycle(ListNode* head){
   ListNode* slow = head;
   ListNode* fast = head;
   while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;

      if(slow == fast){
         slow = head;
         while(slow != fast){
            slow = slow->next;
            fast = fast->next;
         }
         return slow;
      }
   }
   return NULL;
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

    ListNode* loopNode = detectCycle(head);
    
    cout<<"The loop node is: "<<loopNode->val<<" ";
    return 0;
}