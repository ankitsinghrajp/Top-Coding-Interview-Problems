#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(vector<string> ans){
    for(int i = 0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
void subsequence(string str, int index, int n, vector<string> &ans, string temp){
    if(index == n){
        ans.push_back(temp);
        return;
    }

    // Not taking 
     subsequence(str,index+1,n,ans,temp);
    // Taking
    temp.push_back(str[index]);
    subsequence(str,index+1,n,ans,temp);
}
int main(){
    string str = "abcd";
    vector<string> ans;
    string temp = "";
    
    subsequence(str,0,str.size(),ans,temp);

    cout<<"The subsequence of the given string is: "<<endl;
    sort(ans.begin(),ans.end());
    printArray(ans);
    return 0;
}