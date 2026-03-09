#include<iostream>
#include<vector>
using namespace std;
int lenOfLongest(string &s){
   int longest = 0;
   
   for(int i = 0;i<s.size();i++){
       vector<int> Hash(256,0);
       
       for(int j = i;j<s.size();j++){
        if(Hash[s[j]] == 1) break;

        Hash[s[j]] = 1;
        longest = max(longest,j-i+1);
       }
  
   }

   return longest;
}
int main(){
    string s = "cadbzabcd";
    
    cout<<"The length of the longest substring without repeating character is: "<<lenOfLongest(s);
    return 0;
}