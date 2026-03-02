#include<iostream>
using namespace std;

int main(){
    int n = 6;
    cout<<"The elements of nth row is: "<<endl;
    int ans = 1;
    cout<<ans<<" ";
    for(int i = 1;i<n;i++){
        ans = ans*(n-i)/i;
        cout<<ans<<" ";
    }
    return 0;
}