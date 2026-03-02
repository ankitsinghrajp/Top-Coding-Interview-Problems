#include<iostream>
using namespace std;

int nCr(int n, int r){
    int res = 1;
    for(int i = 0;i<r;i++){
        res = res * (n-i);
        res = res/(i+1);
    }
    return res;
}
int main(){

    int r;
    int c;

    cout<<"Enter the row number: ";
    cin>>r;
    cout<<"Enter the column number: ";
    cin>> c;

    cout<<"The element at row: "<<r<<" and column "<<c<<" is: "<<nCr(r-1,c-1);
    

    return 0;
}