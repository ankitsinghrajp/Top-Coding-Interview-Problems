#include<iostream>
#include<vector>
using namespace std;
int longestSubstring(string s){
    vector<bool> visited(256,0);
    int i = 0;
    int j = 0;
    int longest = 0;
    int count = 0;
    while(j<s.size()){
      if(visited[s[j]] == 1){
        while(visited[s[j]] != 0){
             visited[s[i]] = 0;
             i++;
             count --;
        }
      }

      visited[s[j]] = 1;
      count += 1;
      longest = max(longest,count);
      j++;
    }
    return longest;
}
int main(){
    string s = "abcdafgk";
    cout<<"The length of longest substring is: "<<longestSubstring(s);
    return 0;
}