#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &arr){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size();i++){
        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back({arr[i]});
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}
int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    
    cout<<"The original array is: "<<endl;
    printArray(arr);

    cout<<"The merged intervals array is: "<<endl;
    vector<vector<int>> merged = mergeIntervals(arr);
    printArray(merged);

    return 0;
}