#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int lenOfLongest(string &s){
   vector<int> Hash(256,0);
   int first = 0;
   int second = 0;
   int longest = 0;
   while(second< s.size()){
       if(Hash[s[second]] == 1){
        while(Hash[s[second]] == 1){
            Hash[s[first++]] = 0;
        }
       }

       Hash[s[second]] = 1;
       longest = max(longest,second-first+1);
       second ++;
   }
   return longest;
}
int main(){
    string s = "cadbzabcd";
    
    cout<<"The length of the longest substring without repeating character is: "<<lenOfLongest(s);
    return 0;
}