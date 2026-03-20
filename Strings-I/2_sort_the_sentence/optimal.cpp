#include<iostream>
#include<vector>
using namespace std;
string sortSentence(string &s){
    vector<string> ans(10);
    string temp;
    int count = 0;
    int index = 0;
    while(index <s.size()){
        if(s[index] == ' '){
            int pos = temp[temp.size()-1] - '0';
            temp.pop_back();
            ans[pos] = temp;
            temp.clear();
            count += 1;
        }
        else{
            temp += s[index];
        }
        index ++;
    }

    // push the last word
    int pos = temp[temp.size()-1] - '0';
    temp.pop_back();
    ans[pos] = temp;
    temp.clear();
    count += 1;

    for(int i = 1;i<=count;i++){
        temp += ans[i];
        temp += ' ';
    }
    temp.pop_back();
    return temp;
}
int main(){
   string s = "is2 sentence4 This1 a3";
   cout<<"The original sentence is: "<<endl;
   cout<<s<<endl;
   cout<<"The sorted sentence is: "<<endl;
   cout<<sortSentence(s);

    return 0;
}