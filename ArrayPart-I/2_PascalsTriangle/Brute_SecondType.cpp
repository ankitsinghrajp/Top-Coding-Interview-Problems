#include<iostream>
#include<vector>
using namespace std;
int nCr(int n, int r){
    int res = 1;
    for(int i = 0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}
void printNthRow(int n){
    for(int i = 1;i<=n;i++){
        cout<<nCr(n-1,i-1)<<" ";
    }
}
int main(){

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"The "<<n<<"th row is: "<<endl;
    printNthRow(n);
    
    return 0;
}