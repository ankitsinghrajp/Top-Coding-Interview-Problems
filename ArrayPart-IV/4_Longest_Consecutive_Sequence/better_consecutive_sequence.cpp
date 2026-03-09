#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int longestSequence(vector<int> arr){
    sort(arr.begin(),arr.end());
    int longest = 1;
    int lastSmaller = INT32_MIN;
    int countCurrent = 0;

    for(int i = 0;i<arr.size();i++){
        if(arr[i] - 1 == lastSmaller){
            countCurrent += 1;
            lastSmaller = arr[i];
        }
        else if(arr[i] != lastSmaller){
             countCurrent = 1;
             lastSmaller = arr[i];
        }
      

        longest = max(longest,countCurrent);
    }
    return longest;
}
int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};

    cout<<"The longest subsequence is: "<<longestSequence(arr);

    return 0;
}