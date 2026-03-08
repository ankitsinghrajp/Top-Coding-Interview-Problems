#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
void printArray(vector<vector<int>> &arr){
    for(int i = 0;i<arr.size();i++){
        for(int j = 0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


vector<vector<int>> threeSum(vector<int> arr){
   vector<vector<int>> ans;
   sort(arr.begin(),arr.end());
   for(int i = 0;i<arr.size();i++){
    if(i>0 && arr[i] == arr[i-1]) continue;

    int j = i+1;
    int k = arr.size()-1;
    while(j<k){
        int sum = arr[i] + arr[j] + arr[k];
         if(sum == 0){

                    ans.push_back({arr[i],arr[j],arr[k]});

                    j++;
                    k--;

                    while(j<k && arr[j]==arr[j-1]) j++;   
                    while(j<k && arr[k]==arr[k+1]) k--;   
                }

        else if(arr[i] + arr[j] + arr[k] < 0){
            j += 1;
        }
        else{
            k -= 1;
        }
    }

   }
   return ans;
}

int main(){
    vector<int> arr = {-1,0,1,2,-1,-4};
   
    cout<<"The pairs which sum gives 0 are: "<<endl;
    vector<vector<int>> ans = threeSum(arr);
    printArray(ans);
    return 0;
}