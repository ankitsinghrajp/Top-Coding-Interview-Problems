#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i = 0;i<s.size();i++){
         if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
         }
         else{
            if(st.empty()) return false;

            char c = st.top();
            st.pop();

            if(
                c == '(' && s[i] == ')' ||
                c == '[' && s[i] == ']' ||
                c == '{' && s[i] == '}'
            ){

            }
            else{
               return false;
            }
         }
    }
    return st.empty();
}
int main(){
    string s = "({})[]()";
    // string s = "))";
    // string s = "((";
    // string s = "(((((())))))";

    if(isValid(s)){
        cout<<"paranthesis are balanced!"<<endl;
    }
    else{
        cout<<"Not balanced!"<<endl;
    }

    return 0;
}