#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// This code can overflow when the m is too big like 10^9 then its power would be 10^90


// int powerFunc(int x, int n){
//     long long ans = 1;
//     while(n > 0){
//         if(n%2 == 1){
//             ans = ans * x;
//             n = n - 1;
//         }
//         else{
//             x = x * x;
//             n = n/2;
//         }
//     }
//     // x ^ n
//    return ans;
// }

// Writing optimal code for power calculation 

// return 1  if pow == m
// return 0 if pow < m
// return 2   if pow > m;

int powerFunc(int mid, int n, int m){
    long long ans = 1;
    for(int i = 1;i<=n;i++){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
  return 0;
}

int nthRoot(int n, int m){
    if(m == 0) return 0;
    int start = 1;
    int end = m;
    while(start <= end){
        int mid = (start + end)/2;
        int result = powerFunc(mid,n,m);
        if(result == 1) return mid;
        else if (result == 2) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}
int main(){
    int n = 3;
    int m = 8;

    cout<<"The nth root is: "<<nthRoot(n,m);
    return 0;
}