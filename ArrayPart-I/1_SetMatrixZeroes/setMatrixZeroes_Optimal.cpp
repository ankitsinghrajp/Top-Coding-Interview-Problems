#include<iostream>
#include<vector>
using namespace std;

void printMatrix(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

void setMatrix(vector<vector<int>> &arr){
    int col0 = 1;
    int row0 = 1;
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            if(arr[i][j] == 0){
                if(j == 0){
                    col0 = 0;
                }
                if(i == 0){
                    row0 = 0;
                }
                if(i!=0 && j!=0){
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }
    }

    for(int i = arr.size()-1;i >= 1;i--){
        for(int j = arr[0].size()-1; j >= 1;j--){
             if(arr[i][0] == 0 || arr[0][j] == 0){
                arr[i][j] = 0;
             }
        }
    }

   if(row0 == 0){
    for(int j = 0;j<arr.size();j++){
        arr[0][j] = 0;
    }
   }

    if(col0 == 0){
        for(int i = 0;i<arr.size();i++){
            arr[i][0] = 0;
        }
    }
}
int main(){

      vector<vector<int>> arr = {{1,1,1,1}, {1,0,1,1},{1,1,0,1}, {0,1,1,1}};

      cout<<"The original array is: "<<endl;
      printMatrix(arr);
      cout<<"The array after setting zeroes is: "<<endl;
      setMatrix(arr);
      printMatrix(arr);

    return 0;
}