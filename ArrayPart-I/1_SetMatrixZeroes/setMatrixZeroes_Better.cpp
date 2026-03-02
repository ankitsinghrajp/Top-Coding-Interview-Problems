#include<iostream>
#include<vector>
using namespace std;

int main(){
       vector<vector<int>> arr = {{1,1,1,1},{1,0,1,1}, {1,1,0,1}, {1,0,0,1}};
       vector<int> RowTracking(arr.size(),0);
       vector<int> ColTracking(arr[0].size(),0);

       for(int i = 0;i<arr.size();i++){
        for(int j = 0; j<arr[0].size();j++){
            if(arr[i][j] == 0){
                RowTracking[i] = 1;
                ColTracking[j] = 1;
            }
        }
       }

       for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            if(RowTracking[i] == 1 || ColTracking[j] == 1){
                arr[i][j] = 0;
            }
    
        }
       }

       for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
       }
    return 0;
}