#include<iostream>
#include<stack>
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

bool checkPalindrome(ListNode* head){
    stack<int> st;
    ListNode* temp = head;
    while(temp != nullptr){
        st.push(temp->val);
        temp = temp->next;
    }
    
    temp = head;

    while(temp != nullptr){
        if(temp->val != st.top()){
            return false;
        }
        st.pop();
        temp = temp->next;
    }
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