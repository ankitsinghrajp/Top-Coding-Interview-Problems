#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> majority(vector<int> arr){
    vector<int> ans;
    int count1 = 0;
    int count2 = 0;
    int el1 = -1;
    int el2 = -2;

    for(int i = 0;i<arr.size();i++){
        if(count1 == 0 && el2 != arr[i]){
            count1 = 1;
            el1 = arr[i];
        }
        else if(count2 == 0 && el1 != arr[i]){
            count2 = 1;
            el2 = arr[i];
        }
        else if(el1 == arr[i]){
            count1 ++;
        }
        else if(el2 == arr[i]){
            count2++;
        }
        else{
            count1 --;
            count2 --;
        }
    }
    
    // verify first and then return
    int first = 0;
    int second = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == el1){
            first++;
        }
        else if(arr[i] == el2){
            second ++;
        }
    }

    if(first > arr.size()/3){
        ans.push_back(el1);
    }

    if(second > arr.size()/3){
        ans.push_back(el2);
    }
    
    return ans;
}
int main(){
    vector<int> arr = {2,2,1,3,1,1,3,1,1};
    
    cout<<"The majority elements are: ";
    vector<int> ans = majority(arr);
    printArray(ans);
    return 0;
}