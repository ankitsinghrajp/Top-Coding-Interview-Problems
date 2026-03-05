#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int FindDuplicate(vector<int> arr){
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];
        fast = arr[arr[fast]];
    }while(slow!=fast);

    fast = arr[0];
    while(slow!=fast){
        slow = arr[slow];
        fast = arr[fast];
    }
    return fast;
}
int main(){

    vector<int> arr = {1,2,4,5,2,8,9};
    
    cout<<"The duplicate number is: "<<FindDuplicate(arr);

    return 0;
}