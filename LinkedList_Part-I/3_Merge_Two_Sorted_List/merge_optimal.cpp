#include<iostream>
using namespace std;
class ListNode{
   public:
      int data;
      ListNode* next;
};

void printLinkedList(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
 
     ListNode* newHead = nullptr;
     ListNode* tail = nullptr;

     while(list1 != nullptr && list2 != nullptr){
      
        if(list1->data <= list2->data){
            if(newHead== nullptr){
                newHead = list1;
                tail = newHead;
            }
            else{
                tail->next = list1;
             tail = list1;
            }
             list1 = list1->next;
        }
        else{
            if(newHead == nullptr){
                newHead = list2;
                tail = newHead;
            }
            else{
                 tail->next = list2;
                  tail = list2;
            }

           
            list2 = list2->next;
        }
       
     }

     if(list1){
        tail->next = list1;
     }

     if(list2){
        tail->next = list2;
     }
     return newHead;
}
int main(){
    ListNode* list1 = new ListNode();
    list1->data = 3;

    ListNode* second = new ListNode();
    ListNode* third = new ListNode();
    ListNode* fourth = new ListNode();
    ListNode* fifth = new ListNode();

    second->data = 5;
    list1->next = second;

    third->data = 7;
    second->next = third;

    fourth->data = 8;
    third->next = fourth;

    fifth->data = 9;
    fourth->next = fifth;
    fifth->next = nullptr;



    ListNode* list2 = new ListNode();
    
    list2->data = 2;
    
    ListNode* sixth = new ListNode();
    ListNode* seventh = new ListNode();
    ListNode* eigth = new ListNode();
    ListNode* ninth = new ListNode();
    ListNode* tenth = new ListNode();

    sixth->data = 6;
    list2->next = sixth;
    
    seventh->data = 7;
    sixth->next = seventh;

    eigth->data = 10;
    seventh->next = eigth;

    ninth->data = 12;
    eigth->next = ninth;

    tenth->data = 14;
    ninth->next = tenth;
    tenth->next = nullptr;
    
     
    cout<<"The list 1 is: "<<endl;
    printLinkedList(list1);

    cout<<"The list 2 is: "<<endl;
    printLinkedList(list2);

    ListNode* mergedHead = mergeTwoLists(list1,list2);
    printLinkedList(mergedHead);
    return 0;
}