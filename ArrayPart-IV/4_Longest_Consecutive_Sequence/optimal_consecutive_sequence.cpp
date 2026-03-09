#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int longestSequence(vector<int> arr){
    unordered_set<int> st;
    if(arr.size() == 0) return 0;
    int longest = 1;

    for(int i = 0;i<arr.size();i++){
         st.insert(arr[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
             int count = 1;
             int x = it;
             while(st.find(x+1) != st.end()){
                x += 1;
                count += 1;
             }

             longest = max(longest,count);
        }
        
    }
    return longest;
}
int main(){
    vector<int> arr = {0,3,7,2,5,8,4,6,0,1};
    
    cout<<"The longest sub sequence is: "<<longestSequence(arr);
    return 0;
}