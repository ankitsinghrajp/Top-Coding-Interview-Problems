// Twist in the problem skip the duplicates return only unique permutations
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printArray(vector<string> &s){
    for(int i = 0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}

void permutations(string &s,vector<string> &ans, string &temp, vector<bool> &visited){
    if(s.size() == temp.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 0;i<s.size();i++){

        if(visited[i] == 0){

            if(i > 0 && s[i] == s[i-1] && visited[i-1] == 0) continue;

            visited[i] = 1;
            temp.push_back(s[i]);
            permutations(s,ans,temp,visited);
            visited[i] = 0;
            temp.pop_back();
        }
    }
}
int main(){
    string s = "ABCD";

    // string s = "AAAA";

    // If want to skip duplicate first sort the string and then generate with the condition 
    vector<string> ans;
    string temp;
    vector<bool> visited(s.size(),0);
    cout<<"The permutations of the string are: "<<endl;
    permutations(s,ans,temp,visited);
    printArray(ans);
    return 0;
}