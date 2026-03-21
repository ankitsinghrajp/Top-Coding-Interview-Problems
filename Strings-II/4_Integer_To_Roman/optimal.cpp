#include<iostream>
#include<vector>
using namespace std;
string integerToRoman(int num){
   vector<int> values = {
    1000, 900, 500, 400, 100,90, 50,40, 10,9,5,4,1
   };

   vector<string> symbols = {
    "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"
   };
   
   string ans = "";
   for(int i = 0;i<values.size();i++){
       while(num >= values[i]){
           ans += symbols[i];
           num -= values[i];
       }
   }
   return ans;
}
int main(){
    int x= 1290;
    cout<<"The roman of the integer is: "<<integerToRoman(x)<<endl;
    return 0;
}