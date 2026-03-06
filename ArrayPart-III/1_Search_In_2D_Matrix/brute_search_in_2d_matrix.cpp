#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool checkPresent(vector<vector<int>> arr, int x){
     for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            if(arr[i][j] == x){
                return 1;
            }
        }
     }
     return 0;
}
int main(){
   vector<vector<int>> arr = {{1,3,5,7},{10,11,16,20},{23,30,34,50}};
   cout<<"The matrix is: "<<endl;
   printArray(arr);

   int x;
   cout<<"Enter the value which you want to find in the array: ";
   cin>>x;

   int isPresent = checkPresent(arr,x);
   if(isPresent){
    cout<<"The element "<<x<<" is present in the matrix";
   }
   else{
    cout<<"The element "<<x<<" is not present in the matrix";
   }

    return 0;
}