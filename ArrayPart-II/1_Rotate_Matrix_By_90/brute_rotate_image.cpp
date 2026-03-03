#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<vector<int>> & arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr.size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void rotateImage(vector<vector<int>> &arr){
    vector<vector<int>> ans(arr.size(),vector<int>(arr.size()));
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr.size();j++){
            ans[j][(arr.size()-1)-i] = arr[i][j];
        }
    }


    // copy to the original matrix
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans.size();j++){
            arr[i][j] = ans[i][j];
        }
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