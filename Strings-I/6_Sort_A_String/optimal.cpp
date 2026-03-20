#include<iostream>
#include<vector>
using namespace std;
void sortString(string &s){
    vector<int> ans(26,0);
    for(int i = 0;i<s.size();i++){
        ans[s[i]-'a'] += 1;
    }
    s.clear();
    for(int i = 0;i<26;i++){
        int count = ans[i];
        while(count--){
            s += 'a' + i;
        }
    }
}
int main(){
    string s = "edcab";

    cout<<"The original string is: "<<endl;
    cout<<s<<endl;

    cout<<"The sorted string is: "<<endl;
    sortString(s);
    cout<<s<<endl;
    return 0;
}