#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int nthRoot(int n, int m){
    if(m == 0) return 0;
    for(int i = 1;i<=m;i++){
        int ans = pow(i,n);
        if(ans == m) return i;
        else if(ans > m) return -1;
    }
    return -1;
}
int main(){
    int n = 3;
    int m = 8;

    cout<<"The nth root of m is: "<<nthRoot(n,m);

    return 0;
}