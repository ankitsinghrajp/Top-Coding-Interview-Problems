#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode* child;

    ListNode(int x){
        val = x;
        next = nullptr;
        child = nullptr;
    }
};

ListNode* printLinkedList(ListNode* head){
    ListNode* temp = head;
    while(temp!= nullptr){
        cout<<temp->val<<" ";
        temp = temp->child;
    }
    cout<<endl;
}

ListNode* merge(ListNode* list1, ListNode* list2){
    ListNode* dummyNode = new ListNode(-1);
    
    ListNode* temp = dummyNode;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val <= list2->val){
            temp->child = list1;
            temp = list1;
            list1 = list1->child;
        }
        else{
            temp->child = list2;
            temp = list2;
            list2 = list2->child;
        }
        temp->next = nullptr;
    }

    if(list1) temp->child = list1;
    else temp->child = list2;

    return dummyNode->child;
}
ListNode* Flatten(ListNode* head){
   if(head == NULL || head->next == NULL){
    return head;
   }

   ListNode* mergedHead = Flatten(head->next);
   return merge(head,mergedHead);
}
int main(){

    // Main list
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(1);
    ListNode* fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;

    // Child of 3
    ListNode* seven = new ListNode(7);
    ListNode* eight = new ListNode(8);

    head->child = seven;
    seven->child = eight;

    // Child of 2
    ListNode* six = new ListNode(6);
    second->child = six;

    // Child of 1
    ListNode* nine = new ListNode(9);
    ListNode* ten = new ListNode(10);

    third->child = nine;
    nine->child = ten;

    cout<<"The flatten list is: "<<endl;
    ListNode* flattenHead = Flatten(head);

    printLinkedList(flattenHead);

    return 0;
}