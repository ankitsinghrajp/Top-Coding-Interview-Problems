#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

vector<int> nextGreaterElement(vector<int> &arr){
    vector<int> ans;
    for(int i = 0;i<arr.size();i++){
        bool nge = false;
        for(int j = i+1;j<arr.size();j++){
            if(arr[i] < arr[j]){
                ans.push_back(arr[j]);
                nge = true;
                break;
            }
        }
        if(nge == false){
            ans.push_back(-1);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {6,0,8,1,3};

    cout<<"The original array is: "<<endl;
    printArray(arr);

    cout<<"The next greater elements array is: "<<endl;
    vector<int> nge = nextGreaterElement(arr);
    printArray(nge);

    return 0;
}