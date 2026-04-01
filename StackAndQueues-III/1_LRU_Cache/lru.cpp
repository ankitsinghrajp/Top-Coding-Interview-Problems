#include<iostream>
#include<map>
using namespace std;
class Node{
    public:
       int key;
       int val;
       Node* next;
       Node* prev;

    Node(int k, int v){
        key = k;
        val = v;
        next = nullptr;
        prev = nullptr;
    }
};

void deleteNode(Node* node){
    Node* prevNode = node->prev;
    Node* nextNode = node->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
}

void insertAfterHead(Node* head,Node* node){
    Node* currAfterHead = head->next;
    head->next = node;
    node->prev = head;
    node->next = currAfterHead;
    currAfterHead->prev = node;
}
class LRUCache{
      public:
      map<int,Node*> mpp;
      int capacity;
      Node* head = new Node(-1,-1);
      Node* tail = new Node(-1,-1);
      
      LRUCache(int capacity_){
            capacity = capacity_;
            mpp.clear();
            head->next = tail;
            tail->prev = head;
      }


      int get(int key){
         if(!mpp.count(key)) return -1;
         Node* node = mpp[key];
         deleteNode(node);
         insertAfterHead(head,node);
         return node->val;
      }

      void put(int key, int value){
        if(mpp.count(key)){
            Node* node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(head,node);
        }
        else{
            if(mpp.size() == capacity){
                Node* node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }

            Node* node = new Node(key,value);
            mpp[key] = node;
            insertAfterHead(head,node);
        }
      }
};
int main(){
    LRUCache lc = LRUCache(5);
    lc.put(4,5);
    lc.put(3,1);
    lc.put(6,7);
    lc.put(2,1);
    lc.put(1,1);

    cout<<"The value of key 4 is: "<<lc.get(4)<<endl;
    cout<<"The value of key 3 is: "<<lc.get(3)<<endl;
    lc.put(3,5);
    cout<<"The value after change key 3 value is: "<<lc.get(3)<<endl;

    return 0;
}