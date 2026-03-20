#include<iostream>
#include<vector>
using namespace std;
bool checkPangram(string & sentence){
    vector<int> ans(26,0);
    for(int i = 0;i<sentence.size();i++){
         ans[sentence[i] - 'a'] += 1;
    }

    for(int i = 0; i< 26;i++){
        if(ans[i] == 0) return false;
    }
    return true;
}
int main(){
    string sentence = "thequickbrownfoxjumpsoverthelazydog";
    
    bool isPangram = checkPangram(sentence);
    if(isPangram){
        cout<<"The string is Pangram!"<<endl;
    }
    else{
        cout<<"The string is not Pangram!"<<endl;
    }
    return 0;
}