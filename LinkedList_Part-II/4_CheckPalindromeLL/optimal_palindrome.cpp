#include<iostream>
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
ListNode* reverseLinkedList(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
bool checkPalindrome(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverseLinkedList(slow->next);

    ListNode* first = head;
    ListNode* second = newHead;

    while(second != nullptr){
        if(first->val != second->val){
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    
    reverseLinkedList(newHead);
    return true;
}
int main(){
   ListNode* head = new ListNode();
   head->val = 1;

   ListNode* second = new ListNode();
   head->next = second;
   ListNode* third = new ListNode();
   second->next = third;
   ListNode* fourth = new ListNode();
   third->next = fourth;
   ListNode* fifth = new ListNode();
   fourth->next = fifth;

   second->val = 2;
   third->val = 3;
   fourth->val = 2;
   fifth->val = 1;
   fifth->next = nullptr;

   printLinkedList(head);

   bool isPalindrome = checkPalindrome(head);
   
   if(isPalindrome) cout<<"The linked list is palindrome!"<<endl;
   else cout<<"Not palindrome!"<<endl;
    return 0;
}