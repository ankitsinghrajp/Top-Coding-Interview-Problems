#include<iostream>
#include<vector>
using namespace std;

int lps(string str){
    int n = str.size();
    for(int len = n-1; len > 0; len --){
        bool match = true;
        for(int i = 0;i<len;i++){
            if(str[i] != str[n-len+i]){
                match = false;
                break;
            }
        }
        if(match) return len;
    }
    return 0;
}

int main(){
    string str = "aabcdaabc";

    cout<<"The longest prefix suffix matching length is: "<<lps(str);
    return 0;
}