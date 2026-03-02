#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<int> patternLineGenerator(int n){
    vector<int> result;
    int ans = 1;
    result.push_back(ans);
    
    for(int i = 1;i<n;i++){
        ans = ans* (n-i)/i;
        result.push_back(ans);
    }

    return result;
}
int main(){
    
    vector<vector<int>> FinalArray;
    int n;
    cout<<"Enter the nth elements: "<<endl;
    cin>>n;

    for(int i = 1;i<=n;i++){
       vector<int> ans = patternLineGenerator(i);
       FinalArray.push_back(ans);
    }


    printArray(FinalArray);
    
    return 0;
}