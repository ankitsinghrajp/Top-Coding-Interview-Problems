#include<iostream>
#include<vector>
using namespace std;
bool linearSearch(vector<int> arr,int target){
   for(int i = 0;i<arr.size();i++){
    if(arr[i] == target){
        return true;
    }
   }
   return false;
}
int longestSequence(vector<int> arr){
    int longest = 1;
    for(int i = 0;i<arr.size();i++){
        int x = arr[i];
        int count = 1;
        while(linearSearch(arr,x+1) == true){
            x = x+1;
            count += 1;
        }
        longest = max(longest,count);
    }
    return longest;
}
int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    cout<<"The length of the longest consecutive sequence is: "<<longestSequence(arr);
    return 0;
}