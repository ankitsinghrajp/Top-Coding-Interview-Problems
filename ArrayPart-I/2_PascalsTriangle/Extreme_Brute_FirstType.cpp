#include<iostream>
using namespace std;

int factorial(int n){
     int fact = 1;
     for(int i = 1;i<=n;i++){
        fact *= i;
     }
     return fact;
}

int nCr(int r, int c){
    int numerator = factorial(r-1);
    int denominator = factorial(c-1) * factorial(r-c);
    
    int result = numerator/denominator;
    return result;
}
int main(){

    int r;
    int c;
    cout<<"Enter the row number: ";
    cin>>r;
    cout<<"Enter the column number: ";
    cin>>c;

    cout<<"The element at row "<<r<<" and column "<<c<<" is: "<<nCr(r,c);


    return 0;
}