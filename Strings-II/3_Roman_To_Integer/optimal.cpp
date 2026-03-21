#include<iostream>
#include<vector>
using namespace std;
int convert(char c){
    if(c == 'I') return 1;
    else if( c == 'V') return 5;
    else if (c == 'X') return 10;
    else if (c == 'L') return 50;
    else if (c == 'C') return 100;
    else if (c == 'D') return 500;
    return 1000;
}
int romanToInteger(string &s){
int value = 0;
for(int i = 0;i<s.size()-1;i++){
    if(convert(s[i]) >= convert(s[i+1])){
          value += convert(s[i]);
    }
    else{
        value -= convert(s[i]);
    }
}

value += convert(s[s.size()-1]);
return value;
    
}
int main(){
    string s = "III";
    
    // s = "LVIII" = 58
    // s = "MCMXCIV" = 1994
    cout<<"The integer of the given roman number is: "<<romanToInteger(s);
    return 0;
}