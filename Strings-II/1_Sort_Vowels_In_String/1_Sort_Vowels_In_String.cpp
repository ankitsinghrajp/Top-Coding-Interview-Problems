#include<iostream>
#include<vector>
using namespace std;
string sortVowels(string & s){
    vector<int> lower(26,0);
    vector<int> upper(26,0);

    for(int i = 0;i<s.size();i++){
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
            lower[s[i] - 'a'] += 1;
            s[i] = '#';
        }
        else if(
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'
        ){
            upper[s[i] - 'A'] += 1;
            s[i] = '#';
        }
    }
    int index = 0;
    for(int i = 0;i<26;i++){
        int count = upper[i];

        while(count > 0 && index < s.size()){
            if(s[index] == '#'){
                s[index] = 'A' + i;
                count --;
            }
            index ++;
        }
    }

    for(int i = 0; i< 26;i++){
        int count = lower[i];
        while(count > 0 && index < s.size()){
            if(s[index] == '#'){
               s[index] = 'a' + i;
               count --;
            }

            index ++;
        }
    }
    return s;
}
int main(){
    string s = "lEetCOde";
    cout<<"The original string is: "<<endl<<s<<endl;
    string sorted = sortVowels(s);
    cout<<"The string after sorting vowels is: "<<endl<<sorted<<endl;
    return 0;
}