#include<iostream>
#include<vector>
using namespace std;

void markRow(vector<vector<int>> &arr, int i){
      for(int j = 0;j<arr[0].size();j++){
        arr[i][j] = -1;
      }
}

void markCol(vector<vector<int>> &arr, int j){
    for(int i = 0;i<arr.size();i++){
        arr[i][j] = -1;
    }
}
int main(){
    vector<vector<int>> arr = {{1,1,1,1},{1,0,0,1},{1,1,0,1},{1,1,1,1}};
    
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            if(arr[i][j] == 0){
                markRow(arr,i);
                markCol(arr,j);
            }
        }
    }

    cout<<"The marked matrix is : "<<endl;
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            if(arr[i][j] == -1){
                arr[i][j] = 0;
            }
            cout<<arr[i][j]<<" ";   
        }
        cout<<endl;
    }
    return 0;
}