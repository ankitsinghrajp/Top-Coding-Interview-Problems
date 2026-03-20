#include<iostream>
using namespace std;
void rotateClockWise(string & s){
    char x = s[0];
    int index = 0;
    while(index < s.size()-1){
        s[index] = s[index+1];
        index ++;
    }
    s[index] = x;
}

void rotateAntiClockWise(string & s){
    int n = s.size();
    char x = s[n-1];
    int index = n-1;
    while(index > 0){
        s[index] = s[index-1];
        index --;
    }
    s[index] = x;
}
bool checkRotation(string str1, string str2){
    string temp = str1;
    rotateClockWise(temp);
    rotateClockWise(temp);
    if(temp == str2) return true;

    temp = str1;
    rotateAntiClockWise(temp);
    rotateAntiClockWise(temp);
    
    return temp == str2;
}
int main(){
    string str1 = "amazon";
    string str2 = "azonam";

    bool result = checkRotation(str1,str2);
    if(result){
        cout<<"The string is rotated by two places"<<endl;
    }
    else{
        cout<<"Not rotated!"<<endl;
    }
    return 0;
}