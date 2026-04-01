#include<iostream>
#include<map>
using namespace std;

class Node{
public:
    int key, val, freq;
    Node* next;
    Node* prev;

    Node(int k, int v){
        key = k;
        val = v;
        freq = 1;
        next = nullptr;
        prev = nullptr;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    int size;

    List(){
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void insertAfterHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
        size++;
    }

    void deleteNode(Node* node){
        Node* delprev = node->prev;
        Node* delnext = node->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache {
public:
    map<int, Node*> keyNode;     // key -> node
    map<int, List*> freqList;    // freq -> list

    int capacity;
    int minFreq;

    LFUCache(int capacity_) {
        capacity = capacity_;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int freq = node->freq;
        freqList[freq]->deleteNode(node);

        if(freq == minFreq && freqList[freq]->size == 0){
            minFreq++;
        }

        node->freq++;

        if(!freqList.count(node->freq)){
            freqList[node->freq] = new List();
        }

        freqList[node->freq]->insertAfterHead(node);
    }

    int get(int key) {
        if(!keyNode.count(key)) return -1;

        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if(capacity == 0) return;

        if(keyNode.count(key)){
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        }
        else{
            if(keyNode.size() == capacity){
                List* list = freqList[minFreq];
                Node* nodeToDelete = list->tail->prev;

                keyNode.erase(nodeToDelete->key);
                list->deleteNode(nodeToDelete);
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;

            if(!freqList.count(1)){
                freqList[1] = new List();
            }

            freqList[1]->insertAfterHead(newNode);
            keyNode[key] = newNode;
        }
    }
};

int main(){
    LFUCache lc(3);

    lc.put(1,10);
    lc.put(2,20);
    lc.put(3,30);

    cout<<lc.get(1)<<endl; // freq 1->2
    lc.put(4,40); // removes key 2 (LFU)

    cout<<lc.get(2)<<endl; // -1
    cout<<lc.get(3)<<endl; // 30
    cout<<lc.get(4)<<endl; // 40

    return 0;
}