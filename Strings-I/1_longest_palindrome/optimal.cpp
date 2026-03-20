#include<bits/stdc++.h>
using namespace std;
int longestPalindrome(string &s)
{
    vector<int> lower(26,0);
    vector<int> upper(26,0);
    for(int i = 0;i<s.size();i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            lower[s[i] - 'a'] += 1;
        }
        else{
            upper[s[i] - 'A'] += 1;
        }
    }

    int count = 0;
    int odd = 0;
    for(int i = 0;i<26;i++){
        if(lower[i] % 2 == 0){
            count += lower[i];
        }
        else{
            count += lower[i]-1;
            odd = 1;
        }

        if(upper[i] %2 == 0){
            count += upper[i];
        }
        else{
            count += upper[i] - 1;
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