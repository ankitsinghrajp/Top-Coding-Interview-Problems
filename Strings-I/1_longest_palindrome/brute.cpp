#include<iostream>
#include<vector>
using namespace std;
int longestPalindrome(string &s){
    int count = 0;
    bool odd = 0;
    vector<bool> visited(s.size(),false);
    for(int i = 0;i<s.size();i++){
        if(visited[i]) continue;
        int ans = 0;
        for(int j = 0;j<s.size();j++){
           if(s[i] == s[j]){
               ans += 1;
               visited[j] = true;
           } 
        }

        if(ans %2 == 0){
            count += ans;
        
        }
        else{
            count += ans-1;
            odd = 1;
        }
    }
    if(odd) count += 1;
    return count;
}
int main(){
   string s = "aaaabbbacccc";


   cout<<"The longest palindrome can made by the string is of length: "<<longestPalindrome(s);

    return 0;
}