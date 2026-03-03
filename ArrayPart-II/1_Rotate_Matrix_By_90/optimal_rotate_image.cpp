#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr.size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotateImage(vector<vector<int>> &arr){
     for(int i = 0;i<arr.size();i++){
        for(int j = i+1;j<arr.size();j++){
            swap(arr[i][j], arr[j][i]);
        }
     }

     for(int i =0;i<arr.size();i++){
        reverse(arr[i].begin(),arr[i].end());
     }

}
int main(){

    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};

    cout<<"The original matrix is: "<<endl;
    printArray(arr);

    cout<<"The rotated matrix is: "<<endl;
    rotateImage(arr);
    printArray(arr);

    return 0;
}