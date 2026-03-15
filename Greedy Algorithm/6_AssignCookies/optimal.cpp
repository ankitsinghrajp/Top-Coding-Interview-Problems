#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int AssignCookies(vector<int> &greed, vector<int> &s){
    sort(greed.begin(),greed.end());
    sort(s.begin(),s.end());
    
    int left = 0;
    int right = 0;
    int count = 0;
    while(left<greed.size() && right<s.size()){
         if(greed[left] <= s[right]){
            count += 1;
            left ++;
            right ++;
         }
         else{
            right ++;
         }
    }
    return count;
}
int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> s = {4,2,1,2,1,3};

    cout<<"We can assign cookies based on greed to "<<AssignCookies(greed,s)<<" childrens."<<endl;


    return 0;
}