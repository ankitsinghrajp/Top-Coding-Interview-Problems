#include<iostream>
#include<algorithm>
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

vector<vector<int>> mergeInterval(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;
    for(int i = 0;i<arr.size();i++){
        int start = arr[i][0];
        int end = arr[i][1];

        if(!ans.empty() && arr[i][0] <= ans.back()[1]){
            continue;
        }

        for(int j = i+1;j<arr.size();j++){
            if(arr[j][0] <= end){
               end = max(end,arr[j][1]);
            }
            else{
                 break;
            }
        }
        ans.push_back({start,end});
    }

    return ans;
}
int main(){
    vector<vector<int>> arr = {{1,3},{2,6},{8,9},{8,10},{9,11},{15,18},{16,17}};
    
    cout<<"The original array is: "<<endl;
    printArray(arr);

    cout<<"The array after merging intervals is: "<<endl;
    vector<vector<int>> mergedIntervalArray = mergeInterval(arr);
    printArray(mergedIntervalArray);
    return 0;
}