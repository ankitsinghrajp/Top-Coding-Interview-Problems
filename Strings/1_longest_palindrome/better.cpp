#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string &s)
{
    unordered_map<char,int> mpp;
   for(int i = 0;i<s.size();i++){
       mpp[s[i]] += 1;
   }
  
   int count = 0;
   bool odd = 1;
   for(auto it: mpp){
      if(it.second %2  == 0) count += it.second;
      else{
        count += it.second - 1;
        odd = 1;
      }
   }
   
   if(odd) count += 1;
   return count;
}
int main()
{
    string s = "civilwartestingwhetherthatnaptionoranynartionsoconceivedandsodedicatedcanlongendureWeareqmetonagreatbattlefiemldoftzhatwarWehavecometodedicpateaportionofthatfieldasafinalrestingplaceforthosewhoheregavetheirlivesthatthatnationmightliveItisaltogetherfangandproperthatweshoulddothisButinalargersensewecannotdedicatewecannotconsecratewecannothallowthisgroundThebravelmenlivinganddeadwhostruggledherehaveconsecrateditfaraboveourpoorponwertoaddordetractTgheworldadswfilllittlenotlenorlongrememberwhatwesayherebutitcanneverforgetwhattheydidhereItisforusthelivingrathertobededicatedheretotheulnfinishedworkwhichtheywhofoughtherehavethusfarsonoblyadvancedItisratherforustobeherededicatedtothegreattdafskremainingbeforeusthatfromthesehonoreddeadwetakeincreaseddevotiontothatcauseforwhichtheygavethelastpfullmeasureofdevotionthatweherehighlyresolvethatthesedeadshallnothavediedinvainthatthisnationunsderGodshallhaveanewbirthoffreedomandthatgovernmentofthepeoplebythepeopleforthepeopleshallnotperishfromtheearth";

    cout << "The longest palindrome can made by the string is of length: " << longestPalindrome(s);

    return 0;
}