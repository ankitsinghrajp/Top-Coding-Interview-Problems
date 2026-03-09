#include<iostream>
#include<unordered_set>
using namespace std;
int lenOfLongest(string &s){
    int longest = 0;
    for(int i = 0;i<s.size();i++){
        unordered_set<int> st;
        for(int j = i;j<s.size();j++){
           if(st.count(s[j])) break;

           st.insert(s[j]);
           longest = max(longest,(int)st.size());
        }
       
    }
    return longest;
}
int main(){
    string s = "cadbzabcd";
    
    cout<<"The length of the longest substring without repeating character is: "<<lenOfLongest(s);
    return 0;
}