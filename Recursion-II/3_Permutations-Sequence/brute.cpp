#include<iostream>
#include<vector>
using namespace std;

void permutations(int n, vector<string> &ans, string &temp, vector<bool> &visited){
    if(n== temp.size()){
        ans.push_back(temp);
        return;
    }

    for(int i = 1;i<=n;i++){
        if(visited[i-1] == 0){
            visited[i-1] = 1;
            temp.push_back('0'+i);
            permutations(n,ans,temp,visited);
            visited[i-1] = 0;
            temp.pop_back();
        }
    }
}
int main(){
    int n = 4;
    int k = 17;

    vector<string> ans;
    string temp;
    vector<bool> visited(n,0);

    permutations(n,ans,temp,visited);

    cout<<"The answer is: "<<ans[k-1]<<endl;

    return 0;
}