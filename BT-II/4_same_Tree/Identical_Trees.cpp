#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int value){
        data = value;
        left = NULL;
        right = NULL;
      }
};

bool isSameTree(Node* p, Node* q){
    // If both p and q are null
    if(!p && !q){
        return 1;
    }
    
    // If one of them is null
    if((!p && q) || (p && !q)){
        return 0;
    }

    // check if both nodes values are equal
    if(p->data != q->data){
        return 0;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    // -------- Tree 1 --------
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    // -------- Tree 2 (Same as Tree 1) --------
    Node* root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    // -------- Tree 3 (Different Tree) --------
    Node* root3 = new Node(1);
    root3->left = new Node(2);
    root3->right = new Node(4); // different value

    // Test 1: Same trees
    if(isSameTree(root1, root2)){
        cout << "Tree1 and Tree2 are SAME\n";
    } else {
        cout << "Tree1 and Tree2 are NOT SAME\n";
    }

    // Test 2: Different trees
    if(isSameTree(root1, root3)){
        cout << "Tree1 and Tree3 are SAME\n";
    } else {
        cout << "Tree1 and Tree3 are NOT SAME\n";
    }

    return 0;
}