#include<iostream>
#include<vector>
using namespace std;
void printArray(vector<string> ans){
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}

void paranthesis(int n, int left, int right, vector<string> &ans, string & temp){
    
    if(left + right == 2* n){
        ans.push_back(temp);
        return;
    }


    // Taking left paranthesis
    if(left < n){
        temp.push_back('(');
        paranthesis(n,left+1, right, ans, temp);
        temp.pop_back();
    }

    if(right < left){
        temp.push_back(')');
        paranthesis(n, left, right+1, ans, temp);
        temp.pop_back();
    }
}
int main(){
   int n = 5;
   vector<string> ans;
   string temp;

   paranthesis(n,0,0,ans,temp);
   
   printArray(ans);
    return 0;
}