#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

void printArray(vector<vector<int>> arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> fourSum(vector<int> arr, int target){
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size();i++){
          if(i>0 && arr[i]== arr[i-1]) continue;

          for(int j = i+1;j<arr.size();j++){

            if(j> i+1 && arr[j] == arr[j-1]) continue;

            int k = j+1;
            int l = arr.size()-1;

            while(k<l){
                long long sum = (long long)arr[i] + arr[j] + arr[k] + arr[l];
                if(sum == target){
                    vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                    ans.push_back(temp);
                    k ++;
                    l --;

                    while(k<l && arr[k]== arr[k-1]) k++;
                    while(k<l && arr[l]== arr[l+1]) l--;
                }
                else if(sum < target){
                    k++;
                }
                else{
                    l--;
                }
            }
          }

        }
        return ans;
    
}

int main(){
    vector<int> arr = {1,0,-1,0,-2,2};
    int target = 0;
    cout<<"The elements which gives target are: "<<endl;
    
    vector<vector<int>> ans = fourSum(arr,target);
    printArray(ans);

    return 0;
}