#include<iostream>
#include<vector>
using namespace std;
int majority(vector<int> arr){
    int element = -1;
    int count = 0;
    for(int i = 0;i<arr.size();i++){
        if(count == 0){
            element = arr[i];
        }

        if(element == arr[i]){
            count += 1;
        }
        else{
            count -= 1;
        }
    }
    return element;
}
int main(){
   vector<int> arr = {7,7,5,7,5,1,5,7,5,5,7,7,5,5,5,5};

   cout<<"The majority element is: "<<majority(arr);

    return 0;
}