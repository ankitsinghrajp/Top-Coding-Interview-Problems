#include<iostream>
#include<vector>
using namespace std;
double powerX(int x, int n){
    double result = 1;
   for(int i = 1;i<=n;i++){
       result *= x;
   }
   return result;
}
int main(){
     int x;
     int n;
     cout<<"Enter the value of x: ";
     cin>>x;
     cout<<"Enter the value of n: ";
     cin>>n;

     cout<<"The result is: "<<powerX(x,n);
    return 0;
}