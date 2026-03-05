#include<iostream>
#include<vector>
using namespace std;
vector<int> FindRepeatingMissing(vector<int> arr){
  vector<int> ans;
  int repeating = -1;
  int missing = -1;
  for(int i = 1;i<=arr.size();i++){
    int count = 0;
    for(int j = 0;j<arr.size();j++){
        if(arr[j] == i){
            count += 1;
        }
    }
    if(count == 2){
        repeating = i;
    }
    else if( count == 0){
        missing = i;
    }
  }

  ans.push_back(repeating);
  ans.push_back(missing);
  return ans;
}

void printArray(vector<int> arr){
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {4,5,6,2,1,1};

    cout<<"The repeating and missing number is: "<<endl;
    vector<int> ans = FindRepeatingMissing(arr);
    printArray(ans);

    return 0;
}